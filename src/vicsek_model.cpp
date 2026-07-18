/*
This source file implements the Vicsek model.
*/

#include "../include/vicsek_model.h"

#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>

// State struct of a single particle in the system at a given point in time
struct Particle 
{
    std::array<double, 2> pos;
    double angle;
};

// Enable periodic boundary conditions on a square centered on (0,0) (default)
void periodic_boundaries(
    std::span<double, 2> particle, 
    const double xlim_abs, 
    const double ylim_abs
    )
{
    // Check horizontal boundary
    if (particle[0] > xlim_abs)
    {
        particle[0] = particle[0] - 2 * xlim_abs;
    }
    else if (particle[0] < -xlim_abs)
    {
        particle[0] = particle[0] + 2 * xlim_abs;
    }

    // Check vertical boundary
    if (particle[1] > ylim_abs)
    {
        particle[1] = particle[1] - 2 * ylim_abs;
    }
    else if (particle[1] < -ylim_abs)
    {
        particle[1] = particle[1] + 2 * ylim_abs;
    }
}

// Vicsek model for swarm dynamics
void vicsek_model(
    std::span<Particle> particles, 
    const double delta_t, 
    const u_int32_t num_steps, 
    const double velocity, 
    const double radius,
    const double xlim_abs = 1.0,
    const double ylim_abs = 1.0
    )
{
    // Need to add exceptions here for input args

    for (u_int32_t t{0}; t < num_steps; ++t)
    {
        for (auto& particle : particles)
        {
            double theta{particle.angle};

            // Update particle position
            particle.pos[0] += velocity * delta_t * std::cos(theta);
            particle.pos[1] += velocity * delta_t * std::sin(theta);

            // PBC
            periodic_boundaries(particle.pos, xlim_abs, ylim_abs);
        }
    }
}

