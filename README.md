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
## 2. Core Algorithm: Dark Channel Prior (DCP)

The dehazing system is built upon the **Atmospheric Scattering Model**, which describes the formation of a hazy image as follows:
$$I(p,q) = J(p,q)t(p,q) + A(1 - t(p,q))$$
Where:
* $I(p,q)$: Observed hazy image.
* $J(p,q)$: Scene radiance (haze-free image to be recovered).
* $t(p,q)$: Transmission map.
* $A$: Global atmospheric light.

The core processing pipeline consists of five major stages:

### 2.1. Pre-processing & Color Space Transformation
The system extracts intrinsic features from the RGB input to estimate brightness and saturation levels:
* **Value (Brightness) Channel:** $I_{Hazy}^{V}(p,q) = \frac{\max(R,G,B)}{C_{\alpha_{0}}}$
* **Saturation Channel:** $I_{Hazy}^{S}(p,q) = \frac{\max(R,G,B) - \min(R,G,B)}{\max(R,G,B)}$

### 2.2. Dark Channel Estimation
Based on the **Dark Channel Prior** observation, in most non-sky patches, at least one color channel has very low intensity pixels. The dark channel is estimated using a $15 \times 15$ local sliding window ($\Omega_k$):
$$I_{dark}(p,q) = \min_{(i,j) \in \Omega_{k}} \left( \min_{\tau \in \{R,G,B\}} (I_{Hazy}^{\tau}(i,j)) \right)$$

### 2.3. Advanced Transmission Map Estimation
The transmission map $T_{R}^{\prime}$ is calculated by integrating dark channel, brightness, and saturation information to ensure a smooth transition between hazy and clear regions:
* This stage avoids over-saturation and maintains depth consistency across the scene.

### 2.4. Atmospheric Light Estimation ($A_G$)
The global atmospheric light is automatically identified by locating the brightest pixels within the most opaque regions of the transmission map:
$$A_{G} = \max_{(i,j) \in \{(p,q) | T_{R}^{\prime}(p,q) < T_{0}\}} (I_{Hazy}(i,j))$$

### 2.5. Image Restoration & Refinement
The haze-free image $I_{enh}$ is recovered by inverting the scattering model. To optimize hardware performance, fixed-point arithmetic is used for the division operation:
$$I_{enh}(p,q) = \frac{I_{Hazy}(p,q) - A_{G}}{T_{R}^{\prime}(p,q)} + A_{G}$$
* **Refinement:** A Box Filter (optimized for $O(N)$ complexity) is applied to suppress halo artifacts and ensure edge-preserving smoothness.
