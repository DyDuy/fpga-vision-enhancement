# Design-and-implementation-of-a-vision-enhancement-system-on-the-FPGA-DE1-SoC-platform-
## 1. Introduction

In modern applications such as surveillance, search-and-rescue, and intelligent transportation systems, maintaining accurate visibility under adverse weather conditions—such as haze, fog, or smoke—remains a significant challenge. This thesis focuses on the **Design and Implementation of a Real-Time Haze and Smoke Removal System** on the **FPGA DE1-SoC** platform.

The system leverages a high-performance **System-on-Chip (SoC)** architecture to achieve optimal task partitioning:

* **Hardware (FPGA Fabric):** Executes parallel Digital Signal Processing (DSP) algorithms using **Verilog HDL**, ensuring pixel-stream processing with ultra-low latency.
* **Software (HPS - Hard Processor System):** Utilizes the dual-core **ARM Cortex-A9** to manage system-level control, parameter tuning, and user interaction.

### Project Highlights

* **Industry-Standard Development Workflow:** The project follows a rigorous design flow, moving from algorithmic prototyping in **MATLAB**, functional verification and timing analysis in **ModelSim**, to hardware synthesis and deployment via **Quartus Prime**.
* **Superior Performance:** Demonstrates the significant advantages of FPGAs over traditional computing architectures (CPUs/GPUs) in high-speed image processing through massive hardware concurrency.
* **Practical Applicability:** Beyond enhancing visual quality in real-world scenarios, this research establishes a robust framework for future integrated intelligent vision enhancement systems.
