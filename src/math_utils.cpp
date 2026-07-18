#include "../include/math_utils.h"

#include <cassert>
#include <cstdint>
#include <cmath>
#include <span>

double minkowski_distance(std::int16_t p, std::span<const double> v1, std::span<const double> v2)
{
	/*
	 * Computes the Minkowski distance between two 2D vectors,
	 * an induced metric based on the p-norm.
	 */

	assert(p >= 1);
	assert(v1.size() == v2.size());

  	double norm{};

	for (std::size_t i{}; i < v1.size(); ++i) {
		norm += std::pow(std::fabs(v1[i]-v2[i]), p);
	}
    
	return std::pow(norm, 1.0/p);
}
