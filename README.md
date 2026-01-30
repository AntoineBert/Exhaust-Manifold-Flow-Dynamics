Voici le contenu structuré pour ton projet CFD, prêt à être copié-collé dans un fichier README.md.

Markdown
# CFD Pulsatile Flow Simulation (ANSYS Fluent UDF)

## 📌 Project Overview
This project involves a transient CFD (Computational Fluid Dynamics) study of an engine exhaust manifold. To accurately simulate the scavenging process, I developed a **User-Defined Function (UDF)** in C to define complex, time-dependent velocity inlet profiles for each cylinder.

The simulation replicates a 4-cylinder engine running at **3000 RPM**, where each exhaust valve opens in a specific sequence with a sinusoidal velocity profile.



## ⚙️ Key Technical Features
* **Pulsatile Velocity Profiles:** Implementation of periodic sinusoidal waves to represent discrete exhaust strokes.
* **Phase-Shift Logic:** Precise timing offsets (0ms, 5ms, 10ms, 15ms) to simulate the firing order of the engine cylinders.
* **Transient Analysis:** Moving beyond steady-state to capture pressure waves and interference between cylinders during the scavenging phase.
* **Manual Modulo Calculation:** Optimized time-tracking within the UDF to handle engine cycles ($T_{cycle} = 20ms$) over long simulation times.

## 🛠 The Code (UDF)
The script `udf_velocity_inlet.c` uses the Fluent `DEFINE_PROFILE` macro. 
Key parameters defined in the code:
* **RPM:** 3000.
* **Mean Velocity:** 20.0 m/s.
* **Valve Open Duration ($T_{open}$):** 0.008 s.

### Velocity Equation Used:
During the valve opening period ($0 \le t \le T_{open}$):
$$v(t) = V_{max} \cdot \sin\left(\pi \cdot \frac{t}{T_{open}}\right)$$

## 🚀 How to Use in ANSYS Fluent
1. Open ANSYS Fluent.
2. Go to **User Defined** > **Functions** > **Compiled**.
3. Add `udf_velocity_inlet.c` and click **Build** then **Load**.
4. In **Boundary Conditions**, select the inlet of Cylinder 1, change type to **Velocity Inlet**, and under velocity magnitude, select `udf inlet_velocity_cyl1`.
5. Repeat the process for Cylinders 2, 3, and 4 using their respective functions.

## 👥 Author
* **Antoine BERTRAND** - *CFD Simulation & UDF Development*
* **Location:** Colorado State University, Department of Mechanical Engineering

## 📄 License
This project is licensed under the MIT License.
