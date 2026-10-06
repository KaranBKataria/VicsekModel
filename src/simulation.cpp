#include "../include/simulation.h"
#include "../include/vicsekStep.h"
#include "../include/stateSpace.h"

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
        std::cout << "Time t = " << t << "\n";
        std::cout << "-----------------------" <<"\n";

        for (auto& p : particles)
        {
            vm::angleStep(p, particles, radius);
            vm::positionStep(p, grid, speed, del_t);

            std::cout << "Position = (" << p.x << ", " << p.y << ")" << "\n";
            std::cout << "Angle = " << p.angle << "\n\n";
        }
    }
}