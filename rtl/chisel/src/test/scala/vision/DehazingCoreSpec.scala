package vision

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class DehazingCoreSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "DehazingCore"

  it should "add five after the configured latency" in {
    test(new DehazingCore(bitWidth = 10, latency = 6)) { dut =>
      dut.io.pixelIn.poke(37.U)
      dut.clock.step(6)
      dut.io.pixelOut.expect(42.U)
    }
  }

  it should "accept one new pixel per clock" in {
    val latency = 3

    test(new DehazingCore(bitWidth = 10, latency = latency)) { dut =>
      val inputs = Seq(0, 10, 100, 511, 900)
      val expected = inputs.map(value => (value + 5) & 0x3ff)

      inputs.zipWithIndex.foreach { case (value, index) =>
        dut.io.pixelIn.poke(value.U)
        dut.clock.step()

        val completedIndex = index + 1 - latency
        if (completedIndex >= 0) {
          dut.io.pixelOut.expect(expected(completedIndex).U)
        }
      }

      expected.drop(inputs.length - latency + 1).foreach { value =>
        dut.io.pixelIn.poke(0.U)
        dut.clock.step()
        dut.io.pixelOut.expect(value.U)
      }
    }
  }

  it should "wrap on unsigned overflow" in {
    test(new DehazingCore(bitWidth = 10, latency = 1)) { dut =>
      dut.io.pixelIn.poke(1023.U)
      dut.clock.step()
      dut.io.pixelOut.expect(4.U)
    }
  }
}
