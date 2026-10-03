#include "../include/periodicBoundaries.h"
#include "../include/particle.h"

class vm::Grid
{
    // Default is 1.0 x 1.0 grid
    double x_{ 1.0 };
    double y_{ 1.0 };

public:
    Grid(const double x, const double y) : x_{x}, y_{y} {}

    void pbc(vm::ParticleConfiguration& particle) const;
};
