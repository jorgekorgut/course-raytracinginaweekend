#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <vector>
#include <algorithm>

using color = vec3;

void write_color(std::vector<unsigned char>& image, int index, const color& pixel_color) {

    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Gamma-correct and clamp to [0, 255]
    auto red = static_cast<unsigned char>(int(255.999 * r));
    auto green = static_cast<unsigned char>(int(255.999 * g));
    auto blue = static_cast<unsigned char>(int(255.999 * b));

    image[index + 0] = red;
    image[index + 1] = green;
    image[index + 2] = blue;
}

#endif