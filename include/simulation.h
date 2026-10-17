#ifndef SIMULATION_H
#define SIMULATION_H

#include "particle.h"
#include "stateSpace.h"
#include "vicsekStep.h"

#include <concepts>
#include <iostream>
#include <random>
#include <numbers>
#include <vector>

namespace vm::simulation
{
    /*
     * Run full simulation
    */
    template <typename T>
    requires std::floating_point<T>
    void run(
        std::vector<vm::ParticleConfiguration2D<T>>& particles,
        const vm::StateSpace2D<T>& grid,
        const int timesteps,
        const T del_t,
        const T speed,
        const T radius)
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

    /*
     * Set up random particle configuration on spatial domain
    */
    template <typename T>
    requires std::floating_point<T>
    void setUpConfiguration(
        std::vector<vm::ParticleConfiguration2D<T>>& particles,
        const T xlim,
        const T ylim)
    {
        using std::numbers::pi;

        std::random_device rd{};
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> spatial_dist_x(-xlim, xlim);
        std::uniform_real_distribution<T> spatial_dist_y(-ylim, ylim);
        std::uniform_real_distribution<T> angle_dist(0.0, 2.0 * pi);

        for ([[maybe_unused]] std::size_t i{}; i < particles.capacity(); ++i)
        {
            particles.emplace_back(
                spatial_dist_x(gen),
                spatial_dist_y(gen),
                angle_dist(gen)
                );
        }
    }
}

#endif
