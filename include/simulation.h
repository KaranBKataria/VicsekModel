#ifndef SIMULATION_H
#define SIMULATION_H

#include "particle.h"
#include "periodicBoundaries.h"

#include <vector>

namespace vm
{
    void simulation(
        std::vector<vm::ParticleConfiguration>& particles,
        const vm::Grid& grid,
        int timesteps,
        double del_t,
        double speed,
        double radius
        );
}

#endif
