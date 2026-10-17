#ifndef STATESPACE_H
#define STATESPACE_H

#include "utils.h"

#include <concepts>

namespace vm
{
    template <typename T>
    requires std::floating_point<T>
    class StateSpace2D
    {
        public:
            [[nodiscard]] consteval StateSpace2D() = default;
            [[nodiscard]] consteval StateSpace2D(const T x, const T y) : x_{x}, y_{y} {}

            void pbc(vm::ParticleConfiguration2D<T>& particle) const;

        private:
            T x_{};
            T y_{};
    };

    template <typename T>
    requires std::floating_point<T>
    inline void StateSpace2D<T>::pbc(vm::ParticleConfiguration2D<T>& particle) const
    {
        particle.x = vm::utils::wrap<T>(
            particle.x,
            -x_,
            x_);

        particle.y = vm::utils::wrap<T>(
            particle.y,
            -y_,
            y_);
    }
}

#endif
