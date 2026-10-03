#ifndef VICSEKSTEP_H
#define VICSEKSTEP_H

#include "particle.h"
#include "periodicBoundaries.h"

#include <vector>

namespace vm
{
    void positionStep(vm::ParticleConfiguration& particle, vm::Grid& grid, double speed, double del_t);

    void angleStep(
        vm::ParticleConfiguration& particle,
        const std::vector<vm::ParticleConfiguration>& particles,
        double radius);
}

#endif
