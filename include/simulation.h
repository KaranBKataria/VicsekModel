#ifndef SIMULATION_H
#define SIMULATION_H

#include "particle.h"
#include "stateSpace.h"

#include <vector>

namespace vm
{
    void simulation(
        std::vector<vm::ParticleConfiguration2D>& particles,
        const vm::StateSpace2D& grid,
        int timesteps,
        double del_t,
        double speed,
        double radius);
}

#endif
