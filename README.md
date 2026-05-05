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

The dehazing system is built upon the **Atmospheric Scattering Model**, which describes the formation of a hazy image as a linear combination of the scene radiance and the atmospheric light:

$$I(p,q) = J(p,q)t(p,q) + A(1 - t(p,q))$$

**Where:**
* $I(p,q)$: The observed hazy image (Input).
* $J(p,q)$: The scene radiance (Haze-free image to be recovered).
* $t(p,q)$: The transmission map (Medium transparency).
* $A$: The global atmospheric light.

The core processing pipeline is divided into five specialized hardware stages:

 ### 2.1. Pre-processing & Color Space Transformation
To extract relevant features for dehazing, the system converts the RGB input into characteristic channels to retrieve brightness and saturation information

* **Value (Brightness) Channel ($I_{Hazy}^{V}$):** $$I_{Hazy}^{V}(p,q) = \frac{C_{\alpha_{1}}(p,q)}{C_{\alpha_{0}}}$$ 
 where $C_{\alpha_{1}}(p,q) = \max(R,G,B)$ is the maximum intensity among the three color channels at pixel $(p,q)$.

* ### Saturation Channel

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




 ### 2.2. Dark Channel Estimation
A crucial step in identifying haze density is the estimation of the Dark Channel. This is implemented using a $15 \times 15$ local sliding window ($\Omega_k$) to find the minimum intensity across all color channels:

$$I_{dark}(p,q) = \min_{(i,j) \in \Omega_{k}} \left( \min_{\tau \in \{R,G,B\}} (I_{Hazy}^{\tau}(i,j)) \right)$$

 ### 2.3. Advanced Transmission Map Estimation
The system generates an improved transmission map ($T_{R}^{\prime}$) by integrating the dark channel, brightness, and saturation data. This multi-feature approach ensures the map is smooth and depth-consistent:

$$T_{R}^{\prime}(p,q) = \exp \left( -\frac{I_{dark}(p,q)}{\exp((I_{Hazy}^{S}(p,q))^{4} \times (I_{Hazy}^{V}(p,q) + I_{Hazy}^{S}(p,q))^{0.01})} \right)$$

 ### 2.4. Atmospheric Light Estimation ($A_{G}$)
The global atmospheric light is identified by finding the maximum intensity of the input image in regions where the transmission map is below a specific threshold $T_0$:

$$A_{G} = \max_{(i,j) \in \{(p,q) | T_{R}^{\prime}(p,q) < T_{0}\}} (I_{Hazy}(i,j))$$

 ### 2.5. Image Restoration & Blending
The final haze-free output is recovered by inverting the scattering model. To ensure natural visual perception, a blending weight ($\omega$) is calculated based on the average haze density ($\rho_I$):

  **Restoration:** $I_{enh}(p,q) = \frac{I_{Hazy}(p,q) - A_{G}}{T_{R}^{\prime}(p,q)} + A_{G}$

  
