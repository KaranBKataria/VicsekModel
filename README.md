# Numerical Simulation of Active Matter Dynamics - Vicsek Model

Numerical simulation of active matter dynamics described by the [Vicsek model](https://en.wikipedia.org/wiki/Vicsek_model) in C++2x. Requires C++20 support at a minimum; C++23 ideally—animations using OpenGL and shared-memory parallelism with OpenMP to be implemented.

The goal of this project is also to assess the impact of different floating-point formats on numerical stability across various time scales. Formats/precisions to be explored include IEEE 754's float32, float64, float128 (software-emulated double-double),
and legacy x87 80-bit extended precision format.

## Versions

This project is still in the development stage at v0.1.0; v1.0.0 will be released once a basic implementation of the numerical simulation with OpenGL-based animations is achieved.
The table below summarises the versions and their corresponding features to be produced as the project progresses. Please note that this may be subject to changes and adaptation.

| Version  | Features |
| ------------- | ------------- |
| v1  | Preliminary serial implementation - no optimisation or parallelism |
| v2  | OpenMP-based shared-memory parallelism and optimisation of performance bottlenecks (SIMD, Cache-friendly loops) |
| v3  | Per-particle velocities and optimised neighbour search |

