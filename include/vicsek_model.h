#ifndef VICSEK_MODEL_HPP
#define VICSEK_MODEL_HPP

#include <cstdint>
#include <span>

struct Particle;

void periodic_boundaries(
    std::span<double, 2> particle, 
    const double xlim_abs, 
    const double ylim_abs
);

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
