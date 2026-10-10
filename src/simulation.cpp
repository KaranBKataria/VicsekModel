#include "simulation.h"
#include "vicsekStep.h"
#include "stateSpace.h"

#include <iostream>
#include <random>
#include <numbers>

void vm::simulation::run(
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

void vm::simulation::setUpConfiguration(
    std::vector<vm::ParticleConfiguration2D>& particles,
    const double xlim,
    const double ylim)
{
    using std::numbers::pi;

    std::random_device rd{};
    std::mt19937 gen(rd());
    std::uniform_real_distribution spatial_dist_x(-xlim, xlim);
    std::uniform_real_distribution spatial_dist_y(-ylim, ylim);
    std::uniform_real_distribution angle_dist(0.0, 2.0 * pi);

    for (std::size_t i{}; i < particles.size(); ++i)
    {
        particles.emplace_back(
            spatial_dist_x(gen),
            spatial_dist_y(gen),
            angle_dist(gen)
            );
    }
}
