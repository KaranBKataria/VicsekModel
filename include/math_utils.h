#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <cstdint>
#include <span>

double minkowski_distance(std::int16_t p, std::span<double> v1, std::span<double> v2);

#endif
