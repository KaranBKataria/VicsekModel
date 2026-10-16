#include "simulation.h"
#include "stateSpace.h"

#include <vector>

int main()
{
    // Specify simulation configuration
    constexpr int N{ 100 };
    constexpr float DEL_T{ 0.05f };   // 0.1s increments
    constexpr float MAX_T{ 600.0f }; // 10 min timescale
    constexpr int TIMESTEPS{ static_cast<int>(MAX_T / DEL_T) };
    constexpr float SPEED{ 1.0f };
    constexpr float RADIUS{ 1.0f };
    constexpr float XLIM{ 5.0f };
    constexpr float YLIM{ 5.0f };

    constexpr vm::StateSpace2D<float> GRID{ XLIM, YLIM };
    std::vector<vm::ParticleConfiguration2D<float>> particles;
    particles.reserve(N);

    vm::simulation::setUpConfiguration<float>(particles, XLIM, YLIM);
    vm::simulation::run<float>(particles, GRID, TIMESTEPS, DEL_T, SPEED, RADIUS);

    return 0;
}