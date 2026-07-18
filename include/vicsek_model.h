#ifndef VICSEK_MODEL_HPP
#define VICSEK_MODEL_HPP

#include <span>

struct Particle;
void periodic_boundaries(std::span<double, 2> particle, double xlim_abs, double ylim_abs);
void vicsek_model(std::span<Particle> particles, int num_steps);

#endif
