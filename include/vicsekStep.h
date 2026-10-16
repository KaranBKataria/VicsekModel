#ifndef VICSEKSTEP_H
#define VICSEKSTEP_H

#include "particle.h"
#include "stateSpace.h"

#include <random>
#include <numbers>
#include <vector>

namespace vm
{
    void positionStep(
        vm::ParticleConfiguration2D<double>& particle,
        const vm::StateSpace2D<double>& grid,
        double speed,
        double del_t);

    void positionStep(
        vm::ParticleConfiguration2D<float>& particle,
        const vm::StateSpace2D<float>& grid,
        float speed,
        float del_t);

    template <typename T>
    void angleStep(
        vm::ParticleConfiguration2D<T>& particle,
        const std::vector<vm::ParticleConfiguration2D<T>>& particles,
        T radius)
    {
        using std::numbers::pi;

        T acc{};
        int neighbourCount{};

        static std::random_device rd{};
        static std::mt19937 gen(rd());
        static std::normal_distribution<T> whiteNoise(0.0, 0.1);

        // Naive implementation O(n)
        for (const auto& [x, y, angle] : particles)
        {
            if (std::hypot(x - particle.x, y - particle.y) < radius)
            {
                acc += angle;
                ++neighbourCount;
            }
        }

        particle.angle = (acc / static_cast<T>(neighbourCount)) + whiteNoise(gen);
        particle.angle = vm::utils::wrap<T>(particle.angle, 0.0, 2.0 * pi);
    }
}

#endif
