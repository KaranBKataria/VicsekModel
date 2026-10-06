#include "../include/vicsekStep.h"
#include "../include/stateSpace.h"

#include <cmath>

void vm::positionStep(
    vm::ParticleConfiguration2D& particle,
    const vm::StateSpace2D& grid,
    const double speed,
    const double del_t
    )
{
    const double speedTime = speed * del_t;

    // Update particle position
    particle.x += speedTime * std::cos(particle.angle);
    particle.y += speedTime * std::sin(particle.angle);

    // Apply periodic boundary conditions
    grid.pbc(particle);
}

void vm::angleStep(
    vm::ParticleConfiguration2D& particle,
    const std::vector<vm::ParticleConfiguration2D>& particles,
    const double radius
    )
{
    double acc{ 0.0 };

    // Naive implementation O(n)
    for (const auto& [x, y, angle] : particles)
    {
        if (std::hypot(x - particle.x, y - particle.y) < radius)
        {
            acc += angle;
        }
    }

    particle.angle = acc / static_cast<double>(particles.size());
}