%% 1. CẤU HÌNH ĐƯỜNG DẪN
baseDir = 'C:\Users\Duy Khanh\Downloads';
inputFileName = '2.jpg';
inputFile = fullfile(baseDir, inputFileName);

% Tạo thư mục result nếu chưa có
outputDir = fullfile(baseDir, 'result');
if ~exist(outputDir, 'dir')
    mkdir(outputDir);
end

if ~exist(inputFile, 'file')
    error('Không tìm thấy file! Hãy kiểm tra lại tên ảnh tại: %s', inputFile);
end

%% 2. TIỀN XỬ LÝ
src = imread(inputFile);
imgFloat = double(src) / 255.0;

% Bước 1: Feature Channels (V, S, C_min)
[I_V, I_S, C_min] = get_feature_channels(imgFloat);

% Bước 2: Dark Channel (patch_size = 15)
I_dark = imerode(C_min, strel('square', 15));

% Bước 3: Transmission (Thô)
t_raw = estimate_transmission_improved(I_dark, I_V, I_S);

% Bước 4: Guided Filter (Làm mịn)
grayImg = rgb2gray(imgFloat);
t_refined = guided_filter_manual(grayImg, t_raw, 80, 0.001);

% Bước 5 & 6: Dehaze
mask = t_refined < 0.1;
if any(mask(:))
    A_G = max(imgFloat(repmat(mask, [1, 1, 3])));
else
    A_G = max(imgFloat(:));
end

t_bounded = max(t_refined, 0.1);
I_enh = zeros(size(imgFloat));
for i = 1:3
    I_enh(:,:,i) = (imgFloat(:,:,i) - A_G) ./ t_bounded + A_G;
end

I_enh = min(max(I_enh, 0), 1);
% --- BỔ SUNG: TĂNG ĐỘ SẮC NÉT (SHARPENING) ---
h_blur = fspecial('gaussian', [3 3], 0.5); % Tạo bộ lọc mờ
img_blur = imfilter(I_enh, h_blur, 'replicate');
edge_detail = I_enh - img_blur; % Trích xuất chi tiết cạnh
k_sharp = 2; % Hệ số sắc nét (tùy chỉnh)
I_sharp = I_enh + k_sharp * edge_detail;

% Đảm bảo giá trị vẫn trong khoảng [0, 1]
I_sharp = min(max(I_sharp, 0), 1);

% Bước 7: Gamma Correction (áp dụng trên ảnh đã làm nét)
%result = I_sharp .^ gamma_val;
gaman= input('Nhập hệ số Gamma: ');
% Bước 7: Gamma Correction
result =((I_sharp).^gaman);

%% 3. LƯU CÁC FILE VÀO THƯ MỤC RESULT
% Lưu ý: Cần nhân 255 và chuyển về uint8 để xem được trên Windows
imwrite(uint8(I_V * 255), fullfile(outputDir, '01_Value_Channel.jpg'));
imwrite(uint8(I_S * 255), fullfile(outputDir, '02_Saturation_Channel.jpg'));
imwrite(uint8(I_dark * 255), fullfile(outputDir, '03_Dark_Channel.jpg'));
imwrite(uint8(t_raw * 255), fullfile(outputDir, '04_Transmission_Raw.jpg'));
imwrite(uint8(t_refined * 255), fullfile(outputDir, '05_Transmission_Refined.jpg'));
imwrite(uint8(I_enh * 255), fullfile(outputDir, '06_Dehazed_No_Gamma.jpg'));
imwrite(uint8(result * 255), fullfile(outputDir, '07_Final_Result.jpg'));

fprintf('Đã lưu tất cả các file vào: %s\n', outputDir);

%% 4. HIỂN THỊ TRÊN MATLAB (ĐỂ KIỂM TRA)
figure('Units', 'normalized', 'Position', [0.1, 0.1, 0.8, 0.7]);
subplot(2,4,1); imshow(src); title('1. Ảnh gốc');
subplot(2,4,2); imshow(I_V); title('2. Value');
subplot(2,4,3); imagesc(I_S); axis image; colormap(gca, hot); title('3. Saturation');
subplot(2,4,4); imshow(I_dark); title('4. Dark Channel');
subplot(2,4,5); imagesc(t_raw); axis image; colormap(gca, jet); title('5. Trans (Thô)');
subplot(2,4,6); imagesc(t_refined); axis image; colormap(gca, jet); title('6. Trans (Mịn)');
subplot(2,4,7); imshow(I_enh); title('7. Dehazed');
subplot(2,4,8); imshow(result); title('8. Final (Gamma)');

%% CÁC HÀM HỖ TRỢ
function [I_V, I_S, C_min] = get_feature_channels(img)
    C_max = max(img, [], 3);
    C_min = min(img, [], 3);
    I_V = C_max;
    I_S = (C_max - C_min) ./ (C_max + 1e-6);
end

function t = estimate_transmission_improved(I_dark, I_V, I_S)
    denom = exp((I_S.^4) .* (I_V + I_S).^0.01);
    t = exp(-(I_dark ./ (denom + 1e-6)));
end

function q = guided_filter_manual(I, p, r, eps)
    % Cửa sổ lọc có kích thước w x w (với bán kính r)
    w = 2*r + 1;

    % Tạo nhân bộ lọc trung bình (Box Filter) để tính tổng/trung bình vùng
    h = ones(w) / (w^2);

    % --- BƯỚC 1: TÍNH TOÁN CÁC GIÁ TRỊ TRUNG BÌNH CỤC BỘ ---
    mI = imfilter(I, h, 'replicate');    % Trung bình ảnh dẫn đường (mean of I)
    mp = imfilter(p, h, 'replicate');    % Trung bình ảnh cần lọc (mean of p)
    mIp = imfilter(I.*p, h, 'replicate');% Kỳ vọng của tích I và p (E[I*p])
    mII = imfilter(I.*I, h, 'replicate');% Kỳ vọng của bình phương I (E[I^2])

    % --- BƯỚC 2: TÍNH TOÁN PHƯƠNG SAI VÀ HIỆP PHƯƠNG SAI ---
    % Công thức: Cov(I,p) = E[I*p] - E[I]*E[p]
    covIp = mIp - mI.*mp;                % Hiệp phương sai giữa I và p

    % Công thức: Var(I) = E[I^2] - (E[I])^2
    varI = mII - mI.*mI;                 % Phương sai của ảnh dẫn đường I

    % --- BƯỚC 3: TÌM HỆ SỐ TUYẾN TÍNH (a, b) TỐI ƯU ---
    % Hệ số a: Tỷ lệ khuếch đại chi tiết biên (càng cao khi vùng đó có cạnh)
    a = covIp ./ (varI + eps);

    % Hệ số b: Giá trị bù để bảo toàn độ sáng tổng thể
    b = mp - a.*mI;

    % --- BƯỚC 4: LÀM MỊN HỆ SỐ (TRÁNH NHIỄU KHỐI) ---
    % Tính trung bình các hệ số a và b từ các cửa sổ chồng lấp nhau
    ma = imfilter(a, h, 'replicate');    % Trung bình hệ số a (mean of a)
    mb = imfilter(b, h, 'replicate');    % Trung bình hệ số b (mean of b)

    % --- BƯỚC 5: TẠO ẢNH ĐẦU RA ---
    % Kết hợp tuyến tính hệ số trung bình với ảnh dẫn đường gốc
    q = ma.*I + mb;                      % Công thức hồi quy: q = a*I + b
end
