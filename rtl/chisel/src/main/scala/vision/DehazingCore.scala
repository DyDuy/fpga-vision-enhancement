package vision

import chisel3._
import chisel3.util.Pipe

/**
  * Khối xử lý điểm ảnh minh họa.
  *
  * Mỗi điểm ảnh đầu ra bằng điểm ảnh đầu vào cộng 5 theo số học modulo
  * `2^bitWidth`, sau đó đi qua pipeline có `latency` chu kỳ.
  *
  * @param bitWidth độ rộng điểm ảnh, tính bằng bit
  * @param latency số tầng pipeline
  */
class DehazingCore(bitWidth: Int = 10, latency: Int = 6) extends Module {
  require(bitWidth >= 3, "bitWidth phải đủ lớn để biểu diễn hằng số 5")
  require(latency >= 0, "latency không được âm")

  val io = IO(new Bundle {
    val pixelIn = Input(UInt(bitWidth.W))
    val pixelOut = Output(UInt(bitWidth.W))
  })

  val incremented = io.pixelIn +% 5.U(bitWidth.W)
  io.pixelOut := Pipe(true.B, incremented, latency).bits
}

/** Sinh Verilog vào `generated/` hoặc thư mục được truyền ở tham số đầu tiên. */
object DehazingGen extends App {
  val outputDirectory = args.headOption.getOrElse("generated")

  (new chisel3.stage.ChiselStage).emitVerilog(
    new DehazingCore(bitWidth = 10, latency = 6),
    Array("--target-dir", outputDirectory)
  )
}

