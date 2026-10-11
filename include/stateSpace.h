#ifndef STATESPACE_H
#define STATESPACE_H

#include "utils.h"

namespace vm
{
    class StateSpace2D
    {
        // Default is 1.0 x 1.0 grid
        double x_{ 1.0 };
        double y_{ 1.0 };

    public:
        StateSpace2D() = default;
        StateSpace2D(const double x, const double y) : x_{x}, y_{y} {}

        void pbc(vm::ParticleConfiguration2D& particle) const
        {
            particle.x = vm::utils::wrap<double>(
                particle.x,
                -x_,
                x_);

            particle.y = vm::utils::wrap<double>(
                particle.y,
                -y_,
                y_);
        }
    };
}


#endif
