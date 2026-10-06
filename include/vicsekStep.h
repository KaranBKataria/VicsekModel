#ifndef VICSEKSTEP_H
#define VICSEKSTEP_H

#include "particle.h"
#include "stateSpace.h"

#include <vector>

namespace vm
{
    void positionStep(
        vm::ParticleConfiguration2D& particle,
        const vm::StateSpace2D& grid,
        double speed,
        double del_t);

    void angleStep(
        vm::ParticleConfiguration2D& particle,
        const std::vector<vm::ParticleConfiguration2D>& particles,
        double radius);
}

#endif
