#ifndef VICSEK_MODEL_HPP
#define VICSEK_MODEL_HPP

#include <cstdint>
#include <span>

// State struct of a single particle in the system at time t
struct Particle;

/*
* Apply periodic boundary conditions on the state space.
*
* The state space has dimensions (-xlim_abs, xlim_abs) x (-ylim_abs, ylim_abs).
*/
void periodic_boundaries(
    std::span<double, 2> particle_pos, 
    const double xlim_abs, 
    const double ylim_abs
);

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
void vicsek_model(
    std::span<Particle> particles,
    const double delta_t, 
    const uint32_t num_steps, 
    const double velocity, 
    const double radius,
    const double xlim_abs = 1.0,
    const double ylim_abs = 1.0
);

#endif
