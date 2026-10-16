#include "simulation.h"
#include "stateSpace.h"

#include <vector>

int main()
{
    // Specify simulation configuration
    constexpr int N{ 100 };
    constexpr double DEL_T{ 0.05 };   // 0.1s increments
    constexpr double MAX_T{ 600.0 }; // 10 min timescale
    constexpr int TIMESTEPS{ static_cast<int>(MAX_T / DEL_T) };
    constexpr double SPEED{ 1.0 };
    constexpr double RADIUS{ 1.0 };
    constexpr double XLIM{ 5.0 };
    constexpr double YLIM{ 5.0 };

    constexpr vm::StateSpace2D<double> GRID{ XLIM, YLIM };
    std::vector<vm::ParticleConfiguration2D<double>> particles;
    particles.reserve(N);

    vm::simulation::setUpConfiguration<double>(particles, XLIM, YLIM);
    vm::simulation::run<double>(particles, GRID, TIMESTEPS, DEL_T, SPEED, RADIUS);

    return 0;
}