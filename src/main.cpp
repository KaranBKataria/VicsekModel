#include "../include/math_utils.h"
#include "../include/vicsek_model.h"

#include <array>
#include <cstdint>
#include <iostream>
#include <limits>

// Check IEEE-754 float64 portability
static_assert(std::numeric_limits<double>::is_iec559);
static_assert(std::numeric_limits<double>::digits == 53);

int main(int argc, char* argv[])
{
    std::array<double,2> u {1.0, 1.0}; 
    std::array<double,2> v {2.0, 2.0}; 
    std::int16_t p{2};

    std::cout << minkowski_distance(p, u, v) << "\n";

    return 0;
}
