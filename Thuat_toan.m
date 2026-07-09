%% 1. CẤU HÌNH ĐƯỜNG DẪN
baseDir = 'C:\LuanVan_SoC\anh';
inputFileName = 'test23.jpg';
inputFile = fullfile(baseDir, inputFileName);

% Tạo thư mục result nếu chưa có
outputDir = 'C:\Users\Duy Khanh\Downloads\result';
if ~exist(outputDir, 'dir')
    mkdir(outputDir);
end
if ~exist(inputFile, 'file')
    error('Không tìm thấy file! Hãy kiểm tra lại tên ảnh tại: %s', inputFile);
end

%% 2. TIỀN XỬ LÝ & TRÍCH XUẤT KÊNH ĐẶC TRƯNG
src = imread(inputFile);
imgFloat = double(src) / 255.0;

% Bước 1: Feature Channels (V, S, C_min)
[I_V, I_S, C_min] = get_feature_channels(imgFloat);

% Bước 2: Dark Channel (patch_size = 3x3)
I_dark = imerode(C_min, strel('square', 3));

% Bước 3: Transmission (Thô)
t_raw = estimate_transmission_improved(I_dark, I_V, I_S);

% Bước 4: Guided Filter (Làm mịn bản đồ truyền dẫn)
grayImg = rgb2gray(imgFloat);
t_refined = guided_filter_manual(grayImg, t_raw, 80, 0.001);

% Bước 5 & 6: Khôi phục ảnh khử sương (Dehaze)
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
I_enh = min(max(I_enh, 0), 1); % --- ẢNH NÀY CHỈ KHỬ SƯƠNG, GIỮ NGUYÊN GAMMA MẶC ĐỊNH ---

% --- BƯỚC 7: TĂNG ĐỘ SẮC NÉT (SHARPENING) ---
h_blur = fspecial('gaussian', [3 3], 0.5); 
img_blur = imfilter(I_enh, h_blur, 'replicate');
edge_detail = I_enh - img_blur; 
k_sharp = 2; % Hệ số làm sắc nét
I_sharp = I_enh + k_sharp * edge_detail;
I_sharp = min(max(I_sharp, 0), 1); % --- ẢNH ĐÃ LÀM SẮC NÉT, CHƯA CHỈNH GAMMA ---

% --- BƯỚC 8: ĐIỀU CHỈNH GAMMA THỦ CÔNG (CHỈ ÁP DỤNG TRÊN ẢNH SẮC NÉT) ---
gamma_val = 0.8; % Chỉnh thủ công tại đây (<1: sáng lên, >1: tối đi)
I_final_gamma = I_sharp .^ gamma_val; % --- ẢNH CUỐI CÙNG HOÀN THIỆN ---

%% 3. LƯU CÁC FILE VÀO THƯ MỤC RESULT
apply_cmap = @(img, cmap) ind2rgb(uint8((img - min(img(:))) ./ (max(img(:)) - min(img(:)) + 1e-6) * 255), cmap);

% Nhóm ảnh gốc (Giá trị thực tế)
imwrite(uint8(I_V * 255), fullfile(outputDir, '01_Value_Channel.jpg'));
imwrite(uint8(I_S * 255), fullfile(outputDir, '02_Saturation_Channel_Dark.jpg'));
imwrite(uint8(I_dark * 255), fullfile(outputDir, '03_Dark_Channel.jpg'));
imwrite(uint8(t_raw * 255), fullfile(outputDir, '04_Transmission_Raw_Dark.jpg'));
imwrite(uint8(t_refined * 255), fullfile(outputDir, '05_Transmission_Refined_Dark.jpg'));

% Lưu ảnh kết quả theo từng giai đoạn độc lập để so sánh trong báo cáo
imwrite(uint8(I_enh * 255), fullfile(outputDir, '06_Dehazed_Only.jpg'));       % Chỉ khử sương
imwrite(uint8(I_sharp * 255), fullfile(outputDir, '07_Sharpened_Only.jpg'));   % Khử sương + Sắc nét
imwrite(uint8(I_final_gamma * 255), fullfile(outputDir, '08_Final_Gamma.jpg')); % Khử sương + Sắc nét + Gamma

% Nhóm ảnh màu Heatmap minh họa tài liệu
imwrite(apply_cmap(I_S, hot(256)), fullfile(outputDir, '02_Saturation_Channel_Color.jpg'));
imwrite(apply_cmap(t_raw, jet(256)), fullfile(outputDir, '04_Transmission_Raw_Color.jpg'));
imwrite(apply_cmap(t_refined, jet(256)), fullfile(outputDir, '05_Transmission_Refined_Color.jpg'));

fprintf('Đã lưu độc lập các phân đoạn ảnh vào: %s\n', outputDir);

%% 4. HIỂN THỊ TRÊN MATLAB TOÀN DIỆN
figure('Name', 'Kiem tra cac giai doan xu ly anh', 'Units', 'normalized', 'Position', [0.05, 0.05, 0.9, 0.85]);

% Hàng 1: Các bước trích xuất đặc trưng chính
subplot(3,4,1); imshow(src); title('1. Ảnh gốc');
subplot(3,4,2); imshow(I_V); title('2. Value Channel');
subplot(3,4,3); imshow(I_dark); title('3. Dark Channel');
subplot(3,4,4); imshow(I_enh); title('4. Ảnh Dehazed (Mặc định)');

% Hàng 2: Trực quan so sánh hiệu quả của việc Sắc nét và Gamma độc lập
subplot(3,4,5); imshow(I_S); title('5. Saturation');
subplot(3,4,6); imshow(t_refined); title('6. Trans Mịn');
subplot(3,4,7); imshow(I_sharp); title('7. Ảnh Sharpened (No Gamma)');
subplot(3,4,8); imshow(I_final_gamma); title(sprintf('8. Final (Sharp + Gamma = %.2f)', gamma_val));

% Hàng 3: Bản đồ nhiệt đồ thị (Heatmap)
subplot(3,4,9); imagesc(I_S); axis image off; colormap(gca, hot); title('9. Saturation (Heatmap)');
subplot(3,4,10); imagesc(t_raw); axis image off; colormap(gca, jet); title('10. Trans Thô (Heatmap)');
subplot(3,4,11); imagesc(t_refined); axis image off; colormap(gca, jet); title('11. Trans Mịn (Heatmap)');

%% ================= CÁC HÀM CON (FUNCTIONS) =================
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
    w = 2*r + 1;
    h = ones(w) / (w^2);
    mI = imfilter(I, h, 'replicate');
    mp = imfilter(p, h, 'replicate');
    mIp = imfilter(I.*p, h, 'replicate');
    mII = imfilter(I.*I, h, 'replicate');
    covIp = mIp - mI.*mp;
    varI = mII - mI.*mI;
    a = covIp ./ (varI + eps);
    b = mp - a.*mI;
    ma = imfilter(a, h, 'replicate');
    mb = imfilter(b, h, 'replicate');
    q = ma.*I + mb;
end