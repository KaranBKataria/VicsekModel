#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <cstdint>
#include <span>

/*
* Computes the Minkowski distance between two 2D spans
* (default 2-norm).
*/
double minkowski_distance(
	std::span<const double, 2> v1,
	std::span<const double, 2> v2,
	const std::int16_t& p = 2
);

#endif
