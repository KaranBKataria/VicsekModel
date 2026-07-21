/*
* This source file implements the interfaces seen in the math_utils 
* header file.
*/

#include "../include/math_utils.h"

#include <cassert>
#include <cstdint>
#include <cmath>
#include <span>

double minkowski_distance(
	std::span<const double, 2> v1,
	std::span<const double, 2> v2,
	const std::int16_t& p = 2
	)
{
	/*
	* Computes the Minkowski distance between two 2D spans
	* (default 2-norm).
	*/

	assert(p >= 1);
	assert(v1.size() == v2.size());

  	double norm{};

	for (std::size_t i{}; i < v1.size(); ++i) {
		norm += std::pow(std::fabs(v1[i]-v2[i]), p);
	}
    
	return std::pow(norm, 1.0/p);
}
