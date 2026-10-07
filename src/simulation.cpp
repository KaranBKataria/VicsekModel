#include "simulation.h"
#include "vicsekStep.h"
#include "stateSpace.h"

#include <iostream>

void vm::simulation(
    std::vector<vm::ParticleConfiguration2D>& particles,
    const vm::StateSpace2D& grid,
    const int timesteps,
    const double del_t,
    const double speed,
    const double radius)
{
    for (int t{1}; t < timesteps + 1; ++t)
    {
        for (auto& p : particles)
        {
            vm::angleStep(p, particles, radius);
            vm::positionStep(p, grid, speed, del_t);

            std::cout << t << "," << p.x << "," << p.y << "," << p.angle << "\n";
        }
    }
}