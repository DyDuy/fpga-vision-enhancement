# Test plan

| Requirement | Test | Evidence | Status |
|---|---|---|---|
| Proof-of-concept cộng 5 đúng latency | Chisel unit tests | `sbt test` | Existing test, chưa chạy trong repository mới |
| Streaming giữ đúng thứ tự khi liên tục | Chisel unit test | `sbt test` | Existing test |
| Wrap unsigned đúng | Chisel unit test | `sbt test` | Existing test |
| Model dehazing đúng baseline | Chưa có | Chưa có | Planned |
| RTL dehazing khớp fixed-point model | Chưa có | Chưa có | Planned |
| Reset/stall/frame boundary | Chưa có | Chưa có | Planned |
| DE1-SoC timing và throughput | Chưa có | Chưa có | Planned |
