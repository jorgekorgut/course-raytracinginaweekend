# course-raytracinginaweekend

<img src="./output/final-image-14.png"/>

This repository is a personal implementation of concepts from [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html), a popular introductory guide to ray tracing.

It serves as a learning project and step-by-step walkthrough of core ray tracing techniques, written in C++. The code progressively builds a simple yet powerful ray tracer from scratch.

- Shading with Normals
- Antialiasing
- Camera Properties
- Diffuse Lighting
- Lambertian Reflection
- Fuzzy Reflection
- Refraction
- Schlick’s Approximation
- Defocus Blur

## Building

### Building with CMake

```
cmake -B build
cmake --build build
```

### Generating PPM images on powershell

```
.\build\Debug\RayTracingInAWeekend.exe | set-content output/image.ppm -encoding String
```
