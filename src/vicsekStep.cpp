#include "vicsekStep.h"
#include "stateSpace.h"

#include <cmath>

void vm::positionStep(
    vm::ParticleConfiguration2D<double>& particle,
    const vm::StateSpace2D<double>& grid,
    double speed,
    double del_t
    )
{
    const double speedTime{ speed * del_t };

    // Update particle position
    particle.x += speedTime * std::cos(particle.angle);
    particle.y += speedTime * std::sin(particle.angle);

    // Apply periodic boundary conditions
    grid.pbc(particle);
}

void vm::positionStep(
    vm::ParticleConfiguration2D<float>& particle,
    const vm::StateSpace2D<float>& grid,
    float speed,
    float del_t
    )
{
    const float speedTime{ speed * del_t };

    // Update particle position
    particle.x += speedTime * std::cosf(particle.angle);
    particle.y += speedTime * std::sinf(particle.angle);

    // Apply periodic boundary conditions
    grid.pbc(particle);
}
