#ifndef SIMULATION_H
#define SIMULATION_H

#include "particle.h"
#include "stateSpace.h"

#include <vector>

namespace vm::simulation
{
    void run(
        std::vector<vm::ParticleConfiguration2D>& particles,
        const vm::StateSpace2D& grid,
        int timesteps,
        double del_t,
        double speed,
        double radius);

    void setUpConfiguration(
        std::vector<vm::ParticleConfiguration2D>& particles,
        double xlim,
        double ylim);
}

#endif
