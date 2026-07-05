"""
Prototype implementation of the Vicsek model
"""
import numpy as np

class ActiveParticle:

    def __init__(
        self, 
        pos_x: float, 
        pos_y: float, 
        vel_x: float, 
        vel_y: float, 
        vel_angle: float
    ) -> None:
        
        # Initial conditions
        self.position_vec0 = np.array([pos_x, pos_y])
        self.velocity_vec0 = np.array([vel_x, vel_y])
        self.vel_angle0 = vel_angle

        # State at time t
        self.position_vec = np.array([pos_x, pos_y])
        self.velocity_vec = np.array([vel_x, vel_y])
        self.vel_angle = vel_angle

    def position_step(self, del_t: float) -> None:
        vel_angle_direction = [np.cos(self.vel_angle), np.sin(self.vel_angle)]

        self.position_vec += self.position_vec + (self.velocity_vec * del_t * vel_angle_direction)
    
    def angle_step(self, ball_radius: float, active_particles) -> None:
        """
        Aleatoric uncertainty/noise is modelled as a uniform
        random variable U([-180, 180]).
        """
        assert (ball_radius > 0)

        epsilon: float = np.random.uniform(low=-180, high=180, size=1)
        nearby_particles = []

        for particle in active_particles:
            if np.linalg.norm(x=self.position_vec - particle.postion_vec) < ball_radius:
                nearby_particles.append(particle)

        self.vel_angle += np.array(nearby_particles).mean() + epsilon

if __name__ == "__main__":
    
    particle_1 = ActiveParticle(0.5, 0.5, 2, 1, vel_angle=60)
    particle_2 = ActiveParticle(0.1, 0.1, -1, 0, vel_angle=60)

    particle_1.position_step(del_t=0.1)
    print(particle_1.position_vec)
