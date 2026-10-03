#include "../include/simulation.h"
#include "../include/periodicBoundaries.h"

#include <vector>
#include <numbers>

int main(int argc, char* argv[])
{
    using std::numbers::pi;

    const int N{ 2 };
    const int TIMESTEPS { 1^000^000 };
    const double DEL_T { 0.5 };
    const double SPEED { 1.0 };
    const double RADIUS { 1.0 };
    const vm::Grid grid{ 20.0, 20.0 };

    std::vector<vm::ParticleConfiguration> particles;
    particles.reserve(N);

    particles.emplace_back(-5, 0, 0);
    particles.emplace_back(0, -5, pi);

    // Run simulation
    vm::simulation(particles, GRID, TIMESTEPS, DEL_T, SPEED, RADIUS);

    return 0;
}