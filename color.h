#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <algorithm>
#include <vector>

using color = vec3;

inline double linear_to_gamma(double linear_component) {
  if (linear_component > 0)
    return std::sqrt(linear_component);

  return 0;
}

void write_color(std::vector<unsigned char> &image, int index,
                 const color &pixel_color) {

  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // Apply a linear to gamma transform for gamma 2
  r = linear_to_gamma(r);
  g = linear_to_gamma(g);
  b = linear_to_gamma(b);

  // Gamma-correct and clamp to [0, 255]
  static const interval intensity(0.000, 0.999);

  auto red = static_cast<unsigned char>(int(256 * intensity.clamp(r)));
  auto green = static_cast<unsigned char>(int(256 * intensity.clamp(g)));
  auto blue = static_cast<unsigned char>(int(256 * intensity.clamp(b)));

  image[index + 0] = red;
  image[index + 1] = green;
  image[index + 2] = blue;
}

#endif