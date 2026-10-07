#include "simulation.h"
#include "stateSpace.h"

#include <vector>
#include <numbers>

int main(int argc, char* argv[])
{
    using std::numbers::pi;

    constexpr int N{ 2 };
    constexpr double DEL_T{ 0.1 };   // 0.1s increments
    constexpr double MAX_T{ 600.0 }; // 10 min timescale
    constexpr int TIMESTEPS{ static_cast<int>(MAX_T / DEL_T) };
    constexpr double SPEED{ 1.0 };
    constexpr double RADIUS{ 0.5 };
    const vm::StateSpace2D GRID{ 20.0, 20.0 };

    std::vector<vm::ParticleConfiguration2D> particles;
    particles.reserve(N);

    particles.emplace_back(-5, 0, 0);
    particles.emplace_back(0, -5, pi);

    // Run simulation
    vm::simulation(particles, GRID, TIMESTEPS, DEL_T, SPEED, RADIUS);

    return 0;
}