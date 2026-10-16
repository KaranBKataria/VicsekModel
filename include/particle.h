#ifndef PARTICLE_H
#define PARTICLE_H

namespace vm
{
    template <typename T>
    struct ParticleConfiguration2D
    {
        T x{};
        T y{};
        T angle{};
    };
}

#endif
