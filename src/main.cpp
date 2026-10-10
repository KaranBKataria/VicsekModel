#include "simulation.h"
#include "stateSpace.h"

#include <vector>

int main(int argc, char* argv[])
{
    // Specify simulation configuration
    constexpr int N{ 50 };
    constexpr double DEL_T{ 0.1 };   // 0.1s increments
    constexpr double MAX_T{ 600.0 }; // 10 min timescale
    constexpr int TIMESTEPS{ static_cast<int>(MAX_T / DEL_T) };
    constexpr double SPEED{ 0.4 };
    constexpr double RADIUS{ 1.0 };
    constexpr double XLIM{ 5.0 };
    constexpr double YLIM{ 5.0 };

    const vm::StateSpace2D GRID{ XLIM, YLIM };
    std::vector<vm::ParticleConfiguration2D> particles;
    particles.reserve(N);

    vm::simulation::setUpConfiguration(particles, XLIM, YLIM);
    vm::simulation::run(particles, GRID, TIMESTEPS, DEL_T, SPEED, RADIUS);

    return 0;
}