#ifndef PARTICLE_H
#define PARTICLE_H

#include <concepts>

namespace vm
{
    template <typename T>
    requires std::floating_point<T>
    struct ParticleConfiguration2D
    {
        T x{};
        T y{};
        T angle{};
    };
}

#endif
