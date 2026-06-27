#include <iostream>
#include <limits>

// Check IEEE-754 portability
static_assert(std::numeric_limits<float>::is_iec559);
static_assert(std::numeric_limits<double>::is_iec559);

static_assert(std::numeric_limits<float>::digits == 24);
static_assert(std::numeric_limits<double>::digits == 53);

int main(int argc, char* argv[])
{
    return 0;
}
