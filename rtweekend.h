#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <iostream>
#include <memory>
#include <cstdlib>
#include "constants.h"

// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

// Common Headers
#include "interval.h"
#include "color.h"
#include "ray.h"
#include "vec3.h"

#endif