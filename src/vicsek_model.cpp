/*
* This source file implements the interfaces seen in the vicsek_model 
* header file.
*/

#include "../include/vicsek_model.h"

#include <array>
#include <cmath>
#include <cstdint>
#include <span>

// State struct of a single particle in the system at time t
struct Particle 
{
    std::array<double, 2> pos;
    double angle;

    Particle(std::array<double, 2> p_pos, double p_angle) : pos(std::move(p_pos)), angle(p_angle)
    {}
};

void periodic_boundaries(
    std::span<double, 2> particle_pos,
    const double xlim_abs,
    const double ylim_abs
    )
{
    /*
    * Apply periodic boundary conditions on the state space.
    *
    * The state space has dimensions (-xlim_abs, xlim_abs) x (-ylim_abs, ylim_abs).
    */

    // Check horizontal boundary
    if (particle_pos[0] > xlim_abs)
    {
        particle_pos[0] = particle_pos[0] - 2 * xlim_abs;
    }
    else if (particle_pos[0] < -xlim_abs)
    {
        particle_pos[0] = particle_pos[0] + 2 * xlim_abs;
    }

    // Check vertical boundary
    if (particle_pos[1] > ylim_abs)
    {
        particle_pos[1] = particle_pos[1] - 2 * ylim_abs;
    }
    else if (particle_pos[1] < -ylim_abs)
    {
        particle_pos[1] = particle_pos[1] + 2 * ylim_abs;
    }
}

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
    /* 
    * Numerical simulation of active matter dynamics described
    * by the Vicsek model for num_steps number of timesteps, with delta_t
    * resolution in seconds.
    *
    * Initial implementation assumes all particles to have a constant,
    * shared velocity, with an open ball around each particle of the
    * specified radius.
    *
    * The state space has dimensions (-xlim_abs, xlim_abs) x (-ylim_abs, ylim_abs).
    */

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

