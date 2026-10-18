# Lưu lỗi và nhật ký khắc phục

## A — Kiến trúc và luồng ghi nhận

```text
Build Python đã tích hợp gặp lỗi        Log GUI/board/tool khác do bạn nhập
                  |                                  |
                  +---------> record_failure <--------+
                                    |
          build/bug/<hardware|software|generation>/<UTC-timestamp>-<uuid>/
                       |                 |                 |
                  record.json     diagnostics.log      journal.md
                  metadata        trích đoạn lỗi       bạn bổ sung

Log đầy đủ + source snapshot của run vẫn ở vị trí gốc.
```

Mỗi sự cố dùng thư mục riêng; không có chỉ mục chung bị ghi đè khi nhiều build lỗi đồng thời. `hardware/` dành cho Quartus/FPGA, `software/` dành cho HPS/Linux, `generation/` dành cho HLS/Magma/Chisel/Halide. API chỉ nhận ba miền này. Nguồn: [miền hợp lệ, dòng 16](../../software/python/bug_journal.py#L16), [API và tạo thư mục riêng, dòng 203](../../software/python/bug_journal.py#L203).

## B — Chứng cứ và truy xuất nguồn

`record.json` schema version 1 ghi thời điểm UTC, thông báo/bước lỗi, mã thoát gốc (bao gồm mã âm), câu lệnh, tham chiếu run/log, bản chụp metadata được truyền vào, Git HEAD/trạng thái dirty và môi trường Python/OS. Đường dẫn nằm trong repo có cả đường dẫn tương đối và tuyệt đối; đường dẫn ngoài repo giữ đường dẫn tuyệt đối. Git không đọc được sẽ là `null` kèm giới hạn, không suy đoán phiên bản. Nguồn: [tham chiếu đường dẫn, dòng 52](../../software/python/bug_journal.py#L52), [Git best effort, dòng 63](../../software/python/bug_journal.py#L63), [các trường record, dòng 230](../../software/python/bug_journal.py#L230).

`diagnostics.log` giữ thông báo lỗi và tối đa 128 KiB dữ liệu đầu/cuối cho mỗi log văn bản được cung cấp. Nếu cắt bớt, ghi rõ phần giữa bị bỏ và kích thước/path log gốc. Log mất hoặc không đọc được vẫn được ghi như một giới hạn; chỉ đọc tệp thường, bỏ qua thư mục, thiết bị và FIFO. Waveform, binary, mã nguồn và cache không được nhập làm log. Log văn bản hỗ trợ `.log`, `.txt`, `.rpt`, `.out`, `.err`, `.summary` hoặc tên `transcript`; byte không giải mã được thay bằng ký tự thay thế, nên đối chiếu byte chính xác phải đọc tệp gốc. Nguồn: [giới hạn và tên tệp, dòng 17](../../software/python/bug_journal.py#L17), [đọc giới hạn và ghi thiếu chứng cứ, dòng 101](../../software/python/bug_journal.py#L101).

Khi run đã tạo nguồn đầu vào, metadata của sự cố giữ tham chiếu run và bản sao danh sách/hash đầu vào của builder; mã nguồn đầy đủ vẫn nằm trong run, không chép thêm vào `build/bug`. Lỗi trước bước staging/snapshot có thể chưa có nguồn hoặc log để đối chiếu. Commit trong `git.head` được quan sát lúc ghi sự cố; kiểm tra cả hash nguồn và trạng thái dirty khi tái hiện. Nguồn: [hardware input staging, dòng 50](../../software/python/build_fpga.py#L50), [HPS source snapshot, dòng 174](../../software/hps/build_run.py#L174), [hardware snapshot metadata, dòng 155](../../software/python/build_fpga.py#L155), [software snapshot metadata, dòng 44](../../software/hps/build_run.py#L44), [Git best effort, dòng 63](../../software/python/bug_journal.py#L63).

`journal.md` phân biệt triệu chứng quan sát, giả thuyết chưa xác nhận, nguyên nhân đã xác nhận, sửa đổi và kiểm chứng. Các trường nguyên nhân, sửa đổi và kiểm chứng trong record khởi đầu là `null`; helper không tự kết luận lỗi do hardware hay thuật toán nào. Nguồn: [mẫu nhật ký, dòng 155](../../software/python/bug_journal.py#L155), [trạng thái ban đầu, dòng 230](../../software/python/bug_journal.py#L230).

## C — Build tự động và nhập lỗi thủ công

Hai entrypoint hiện đã tích hợp recorder:

| Entrypoint | Khi nào ghi sự cố? | Miền và log gốc |
|---|---|---|
| `python software/python/build_fpga.py stage\|generate\|compile` | Lỗi cấu hình, tìm tool, staging, metadata, Qsys/Quartus, timeout hoặc ngắt Ctrl+C. [Luồng và hook, dòng 165](../../software/python/build_fpga.py#L165), [timeout/ngắt tool, dòng 117](../../software/python/build_fpga.py#L117). | `hardware/`; log run `build/quartus/<name>/runs/<run-id>/logs/*.log`. [Capture, dòng 150](../../software/python/build_fpga.py#L150). |
| `bash software/hps/build.sh all` trong WSL/Linux | Tham số/target sai, khởi tạo run, snapshot, toolchain, compiler, ghi metadata hoặc ngắt trước khi commit thành công. [Bash entrypoint, dòng 11](../../software/hps/build.sh#L11), [luồng và hook, dòng 312](../../software/hps/build_run.py#L312). | `software/`; log run `build/hps/linux/runs/<run-id>/logs/build.log`. [Capture, dòng 32](../../software/hps/build_run.py#L32). |

`stage|generate|compile` là ba lựa chọn thay thế, không nhập nguyên chuỗi có dấu `|`. Chạy thành công không tạo sự cố; warning của tool/compiler có mã thoát 0 không tự thành bug khi build hoàn tất thành công. Hardware CLI vẫn trả 1 khi thất bại, còn `record.json.exit_code` giữ mã tool con nếu có; timeout/lỗi nội bộ dùng 1, Ctrl+C dùng 130. HPS giữ mã lỗi gốc trong JSON; mã signal âm của tiến trình con được chuyển thành `128 - code` khi trả về terminal, còn ngắt do handler trước commit dùng 130. Nguồn: [hardware mã tool và trạng thái, dòng 127](../../software/python/build_fpga.py#L127), [hardware kết quả và capture, dòng 215](../../software/python/build_fpga.py#L215), [HPS compile result, dòng 245](../../software/hps/build_run.py#L245), [HPS kết quả và chuẩn hóa mã, dòng 343](../../software/hps/build_run.py#L343).

Chạy từ thư mục gốc dự án trong terminal VS Code. Cần Python 3; helper dùng thư viện chuẩn, không cài package bổ sung. CLI mặc định xác định repo theo vị trí script, nên lệnh hoạt động trên Windows và trong bản repo truy cập từ WSL. Nguồn: [imports, dòng 4](../../software/python/bug_journal.py#L4), [CLI/root mặc định, dòng 264](../../software/python/bug_journal.py#L264).

```powershell
# Tạo thư mục/help, không tạo một sự cố giả.
python software/python/bug_journal.py --init

# Nhập một lỗi bạn quan sát từ Quartus GUI; thay đường dẫn bằng log thực tế.
python software/python/bug_journal.py --domain hardware --phase fit --exit-code 1 --message "Quartus GUI: fitting failed" --log "build/quartus/vision_1x1/runs/RUN-ID/logs/quartus-compile.log" --run-directory "build/quartus/vision_1x1/runs/RUN-ID"

# Nhập log ứng dụng chạy trên Linux của board sau khi chép log về máy.
python software/python/bug_journal.py --domain software --phase board-runtime --exit-code 1 --message "Ứng dụng HPS gặp lỗi khi chạy trên board" --log "build/hps/board-runtime.log"
```

Các đường dẫn `RUN-ID` và `board-runtime.log` phía trên là chỗ điền của bạn, không phải kết quả đo đã có. Có thể lặp `--log` để tham chiếu nhiều log; `--command` lưu câu lệnh gốc. CLI in đường dẫn sự cố vừa tạo. Nguồn: [khai báo CLI và gọi recorder, dòng 264](../../software/python/bug_journal.py#L264).

API dùng cho entrypoint build:

```python
from bug_journal import record_failure

incident = record_failure(
    root, "hardware", message="Quartus failed", exit_code=return_code,
    phase="compile", run_directory=run_dir, record=run_metadata,
    logs=[compile_log], command=compile_command,
)
```

Caller cần bắt lỗi ghi nhật ký riêng và giữ nguyên lỗi/mã thoát của build. Hai builder đã xử lý lỗi recorder theo cách này: cảnh báo không ghi được nhật ký, giữ kết quả build. Nguồn: [hardware recorder exception, dòng 161](../../software/python/build_fpga.py#L161), [software recorder exception, dòng 58](../../software/hps/build_run.py#L58).

## D — Vận hành và giới hạn

Tự động ghi áp dụng cho hai entrypoint trong mục C khi thất bại. Quartus GUI, chạy trực tiếp ứng dụng C trên board và lệnh ngoài của HLS/Magma/Chisel/Halide cần dùng CLI nhập log (`--domain generation` cho tool sinh RTL). Recorder nhận chứng cứ được truyền vào, không theo dõi mọi tiến trình và không chạy lại build/board. Không tự nhập lại lỗi lịch sử; muốn bổ sung một lỗi cũ, gọi CLI với log và thông tin đã kiểm chứng. Nguồn: [hardware hook cho lần chạy hiện tại, dòng 150](../../software/python/build_fpga.py#L150), [software hook cho lần chạy hiện tại, dòng 32](../../software/hps/build_run.py#L32), [API nhận chứng cứ, dòng 203](../../software/python/bug_journal.py#L203), [CLI nhập chứng cứ, dòng 264](../../software/python/bug_journal.py#L264).

Sau khi sửa, mở `journal.md` của sự cố và ghi tệp/dòng hoặc commit, cách tái hiện, câu lệnh kiểm chứng, run/log mới và kết quả quan sát. Chỉ chuyển trạng thái sang đã khắc phục khi chứng cứ kiểm chứng đủ; sửa Markdown không tự cập nhật `record.json`. Nguồn: [trường nhật ký để bổ sung, dòng 155](../../software/python/bug_journal.py#L155), [record ghi một lần, dòng 256](../../software/python/bug_journal.py#L256).

Chi phí đọc log được giới hạn theo số log và tối đa 128 KiB/log; kích thước metadata và thông báo do caller cung cấp không có hạn mức riêng. Hai lệnh Git có timeout 3 giây mỗi lệnh; state Git được quan sát khi ghi sự cố, không phải snapshot nguyên tử của nguồn build. Log đang được ghi tiếp có thể thay đổi sau lần chụp. Nguồn: [timeout, dòng 63](../../software/python/bug_journal.py#L63), [đọc log, dòng 101](../../software/python/bug_journal.py#L101), [metadata và giới hạn, dòng 230](../../software/python/bug_journal.py#L230).

`build/bug` nằm trong `build/` đã được Git bỏ qua; mã recorder/hook trong `software/` và hướng dẫn trong `docs/` nằm ngoài thư mục sinh kết quả để đưa vào Git. Giữ/back up các sự cố cần thiết trước khi dọn build. Muốn đưa nhật ký lên Git, chủ động xuất phần đã xác minh sang tài liệu có phiên bản, giữ các tham chiếu tới chứng cứ. Không có cơ chế tự xóa lịch sử hoặc tự xuất nhật ký. Nguồn: [quy tắc build/, `.gitignore` dòng 2](../../.gitignore#L2), [khởi tạo chỉ giữ thư mục và README hiện có, dòng 87](../../software/python/bug_journal.py#L87).

Các kiểm tra hành vi được định nghĩa tại [test_bug_journal.py, dòng 33](../../software/python/tests/test_bug_journal.py#L33): bảo toàn log, mã thoát âm, đường dẫn/metadata, trích đoạn giới hạn, thiếu log/Git, song song và CLI/init. Kết quả kiểm tra phải đọc từ báo cáo validation riêng; tài liệu này không khẳng định build FPGA hoặc chạy board đã qua.
