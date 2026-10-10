#include "simulation.h"
#include "stateSpace.h"

#include <numbers>
#include <random>
#include <vector>

int main(int argc, char* argv[])
{
    using std::numbers::pi;

    constexpr int N{ 50 };
    constexpr double DEL_T{ 0.1 };   // 0.1s increments
    constexpr double MAX_T{ 600.0 }; // 10 min timescale
    constexpr int TIMESTEPS{ static_cast<int>(MAX_T / DEL_T) };
    constexpr double SPEED{ 0.4 };
    constexpr double RADIUS{ 1.0 };
    const vm::StateSpace2D GRID{ 5.0, 5.0 };

    std::random_device rd{};
    std::mt19937 gen(rd());
    std::uniform_real_distribution spatial_dist(-5.0, 5.0);
    std::uniform_real_distribution angle_dist(0.0, 2.0 * pi);

    std::vector<vm::ParticleConfiguration2D> particles;
    particles.reserve(N);

    for (int i{}; i < N; ++i)
    {
        particles.emplace_back(spatial_dist(gen), spatial_dist(gen), spatial_dist(gen));
    }

    // Run simulation
    vm::simulation(particles, GRID, TIMESTEPS, DEL_T, SPEED, RADIUS);

    return 0;
}