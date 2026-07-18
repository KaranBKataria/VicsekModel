#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <cstdint>
#include <span>

double minkowski_distance(std::int16_t p, std::span<const double> v1, std::span<const double> v2);

#endif
