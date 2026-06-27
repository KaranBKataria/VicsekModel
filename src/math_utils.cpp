#include "../include/math_utils.h"

#include <array>
#include <cassert>
#include <cstdint>
#include <cmath>

double minkowski_distance(std::int16_t p, const std::array<double,2>& v1, const std::array<double,2>& v2)
{
	/*
	 * Computes the Minkowski distance between two 2D vectors,
	 * an induced metric based on the p-norm.
	 */

	assert(p >= 1);

	double norm = 0;

	for (std::size_t i{}; i < v1.size(); i++) {
		norm += std::pow(std::fabs(v1[i]-v2[i]), p);
	}
    
	return std::pow(norm, 1.0/p);
}
