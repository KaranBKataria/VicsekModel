#include "../include/vicsekStep.h"
#include "../include/periodicBoundaries.h"

#include <cmath>

void vm::positionStep(vm::ParticleConfiguration &particle, const vm::Grid& grid, const double speed, const double del_t)
{
    const double speedTime = speed*del_t;

    // Update particle position
    particle.x += speedTime*std::cos(particle.angle);
    particle.y += speedTime*std::sin(particle.angle);

    // Periodic boundary conds
    grid.pbc(particle);
}

void vm::angleStep(
    vm::ParticleConfiguration& particle,
    const std::vector<vm::ParticleConfiguration>& particles,
    const double radius
    )
{
    double acc{ 0.0 };

    // Naive implementation O(n)
    for (const auto& p : particles)
    {
        if (std::hypot(p.x - particle.x, p.y - particle.y) < radius)
        {
            acc += p.angle;
        }
    }

    particle.angle = acc / static_cast<double>(particles.size());
}