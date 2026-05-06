# Design and Implementation of a Vision Enhancement System on FPGA DE1-SoC

[![Platform](https://img.shields.io/badge/Platform-Terasic%20DE1--SoC-blue)](https://www.terasic.com.tw/)
[![Chip](https://img.shields.io/badge/FPGA-Cyclone%20V-orange)](https://www.intel.com/)
[![HDL](https://img.shields.io/badge/Language-Verilog%20HDL-red)]()

## 📖 1. Introduction

In modern applications such as surveillance, search-and-rescue, and intelligent transportation systems, maintaining accurate visibility under adverse weather conditions—such as haze, fog, or smoke—remains a significant challenge. This thesis focuses on the **Design and Implementation of a Real-Time Haze and Smoke Removal System** on the **FPGA DE1-SoC** platform.

The system leverages a high-performance **System-on-Chip (SoC)** architecture to achieve optimal task partitioning:

* ⚡ **Hardware (FPGA Fabric):** Executes parallel Digital Signal Processing (DSP) algorithms using **Verilog HDL**, ensuring pixel-stream processing with ultra-low latency.
* 🧠 **Software (HPS - Hard Processor System):** Utilizes the dual-core **ARM Cortex-A9** to manage system-level control, parameter tuning, and user interaction.

### ✨ Project Highlights
* 🛡️ **Industry-Standard Workflow:** Prototyping in **MATLAB**, functional verification in **ModelSim**, and hardware synthesis via **Quartus Prime**.
* 🚀 **Superior Performance:** Demonstrates the significant advantages of FPGAs over CPUs/GPUs in high-speed image processing through massive hardware concurrency.
* 🌍 **Practical Applicability:** Establishes a robust framework for future integrated intelligent vision enhancement systems.

---

## 🔬 2. Core Algorithm: Dark Channel Prior (DCP)

The dehazing system is built upon the **Atmospheric Scattering Model**:

$$I(p,q) = J(p,q)t(p,q) + A(1 - t(p,q))$$

### 🛠️ Processing Pipeline Stages

#### 🔵 2.1. Pre-processing & Color Space Transformation
Converts RGB input into characteristic channels to retrieve brightness and saturation information:
* **Value (Brightness) Channel ($I_{Hazy}^{V}$):**
    $$I_{Hazy}^{V}(p,q) = \frac{\max(R,G,B)}{C_{\alpha_{0}}}$$
### Saturation Channel
$$
I_{Hazy}^{S}(p,q) =
\begin{cases}
\frac{C_{\tau}(p,q)}{C_{\alpha_{1}}(p,q)} & \text{if } C_{\alpha_{1}}(p,q) > 0 \\
0 & \text{otherwise}
\end{cases}
$$
where:
$$
C_{\tau}(p,q) = C_{\alpha_{1}}(p,q) - C_{\alpha_{2}}(p,q)
$$

#### 🌑 2.2. Dark Channel Estimation
Implemented using a $15 \times 15$ local sliding window ($\Omega_k$) to find the minimum intensity:
$$I_{dark}(p,q) = \min_{(i,j) \in \Omega_{k}} \left( \min_{\tau \in \{R,G,B\}} (I_{Hazy}^{\tau}(i,j)) \right)$$

#### 🌀 2.3. Advanced Transmission Map Estimation
Generates an improved map ($T_{R}^{\prime}$) by integrating dark channel, brightness, and saturation:
$$T_{R}^{\prime}(p,q) = \exp \left( -\frac{I_{dark}(p,q)}{\exp((I_{Hazy}^{S}(p,q))^{4} \times (I_{Hazy}^{V}(p,q) + I_{Hazy}^{S}(p,q))^{0.01})} \right)$$

#### 💡 2.4. Atmospheric Light Estimation ($A_{G}$)
Identifies global atmospheric light in regions where the transmission map is below a specific threshold $T_0$:
$$A_{G} = \max_{(i,j) \in \{(p,q) | T_{R}^{\prime}(p,q) < T_{0}\}} (I_{Hazy}(i,j))$$

#### 🖼️ 2.5. Image Restoration & Blending
The final haze-free output is recovered by inverting the scattering model:
$$I_{enh}(p,q) = \frac{I_{Hazy}(p,q) - A_{G}}{T_{R}^{\prime}(p,q)} + A_{G}$$

---

## 🖥️ 3. Platforms & Development Tools

### 🏗️ Hardware Architecture
* **FPGA Platform:** `Terasic DE1-SoC (Cyclone V SoC)`
* **Processor:** `Dual-core ARM Cortex-A9 MPCore (HPS)`

### 💻 Software & Languages
* **HDLs:** `Verilog HDL`
* **Programming:** `C/C++`, `Python`, `MATLAB`
* **FPGA Design Suite:** `Intel Quartus Prime`, `Qsys (Platform Designer)`
* **Simulation & Verification:** `ModelSim / Questa Intel Starter Edition`
* **Remote Tools:** `WinSCP`, `MobaXterm`, `Linux (Basic Administration)`
## 🛠️ 4. System Architecture & Control Logic

The system operation is orchestrated by a custom-designed hardware controller, integrating high-speed logic with a unified SoC bus fabric.

### 4.1. Finite State Machine (FSM) Design 🚦 
To ensure reliable data synchronization between the FPGA processing pipeline and the memory subsystem, a multi-state FSM was implemented. This FSM manages the handshaking protocols and prevents data contention.

**Key Operational States:**
* **STATE_0_IDLE:** Initial reset state; waits for start signals or triggers.
* **PRE_READ / POST_READ (States 4 & 6):** Handles the setup and cleanup of the data retrieval process from the input buffer.
* **PRE_WRITE / POST_WRITE (States 1 & 3):** Manages the synchronization overhead before and after writing processed frames to memory.
* **WRITE_TRANSFER / READ_TRANSFER (States 2 & 5):** The active payload phase where high-speed burst data transfer occurs.

> **Logic Highlight:** The FSM features multiple feedback loops to the `IDLE` state, ensuring system stability and automatic recovery in case of transfer interruptions.

### 🧬 4.2. Qsys System Integration (Platform Designer)
The project utilizes **Intel Platform Designer (Qsys)** to create a seamless interconnect between the HPS (Hard Processor System) and Custom FPGA IP Cores.

* **Interconnect:** Utilizes the **Avalon-MM (Memory Mapped)** interface for control register access and **Avalon-ST (Streaming)** for real-time pixel processing.
* **Bridge Architecture:** * **H2F Bridge:** Allows the ARM Cortex-A9 to tune dehazing parameters (thresholds, atmospheric light constants) in real-time.
    * **F2H Bridge:** Enables high-bandwidth access for the FPGA hardware accelerators to the shared DDR3 SDRAM.
* **Clock Domain Crossing (CDC):** Optimized to handle different clock frequencies between the HPS peripherals and the high-speed FPGA vision pipeline.

---

## 5. References 📚

1. **He, K., Sun, J., & Tang, X. (2010).** "Single Image Haze Removal Using Dark Channel Prior." *IEEE Transactions on Pattern Analysis and Machine Intelligence*, 33(12), 2341-2353.
2. **Bruce Land.** "HPS Peripherals and University Program Computer." *Cornell University, ECE5760.* [Online]. Available: [Cornell ECE5760 Resource](https://people.ece.cornell.edu/land/courses/ece5760/DE1_SOC/HPS_peripherials/univ_pgm_computer.index.html)
3. **Terasic Inc.** "DE1-SoC Development Kit User Manual." [Online]. Available: [Terasic Website](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&No=836)
4. **Intel Corporation.** "Avalon Interface Specifications." [Online]. Available: [Intel FPGA Documentation](https://www.intel.com/content/www/us/en/docs/programmable/683091/current/avalon-interface-specifications.html)
5. **Zhu, Q., Mai, J., & Shao, L. (2015).** "A Fast Cost-Effective Image Dehazing Algorithm Based on the Color Attenuation Prior." *IEEE Transactions on Image Processing*, 24(11), 3522-3533.
