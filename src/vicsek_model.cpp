/*
This source file implements the Vicsek model.
*/

#include "../include/vicsek_model.h"

#include <array>
#include <cmath>

class VicsekParticle
{
    private:

        // Position at time t
        double m_x{}, m_y{};

        // Velocity at time t
        double v_x{}, v_y{};

        // Velocity angle at time t
        double velocity_direction{};

        double angle_step(double delta_t, std::array<double,2> position);

        double position_step(double delta_t, double dist);

    public:

        // position and velocity vectors at time t
        std::array<double,2> m_pos{m_x, m_y};
        std::array<double,2> m_vel{v_x, v_y};

        VicsekParticle(double x, double y, double vx, double vy, double vel_dir) : m_x{ x }, m_y{ y }, v_x{ vx }, v_y{ vy }, velocity_direction{ vel_dir }
		{}

        double vicsek_step(double delta_t, std::array<double,2> position);
};
