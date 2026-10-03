#include "../include/simulation.h"
#include "../include/vicsekStep.h"
#include "../include/periodicBoundaries.h"

void vm::simulation(
    std::vector<vm::ParticleConfiguration>& particles,
    const vm::Grid& grid,
    const int timesteps,
    const double del_t,
    const double speed,
    const double radius)
{
    for (int t{0}; t < timesteps; ++t)
    {
        for (auto& p : particles)
        {
            vm::angleStep(p, particles, radius);
            vm::positionStep(p, grid, speed, del_t);
        }
    }
}