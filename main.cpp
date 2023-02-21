#include <iostream>
#include "Grid.h"
#include "ParticleSystem.h"

int main() {
    Grid grid(Vec3<int>(0,0,0), Vec3<float>(1,1,1), 0.1);

    // Print the grid
    for (const auto& bucket : grid.m_buckets)
    {
        std::cout << bucket.m_lowerLeft.x << ", " << bucket.m_lowerLeft.y << ", " << bucket.m_lowerLeft.z;
        
    }

    // Print number of buckets
    std::cout << "Number of buckets: " << grid.m_buckets.size() << std::endl;

    // Add a particle to the grid
    grid.m_buckets[0].m_particles.m_positions.push_back(Vec3<float>(0.1, 0.1, 0.1));
    grid.m_buckets[0].m_particles.m_velocities.push_back(Vec3<float>(0.1, 0.1, 0.1));
    grid.m_buckets[0].m_particles.m_masses.push_back(1.0);

    // Print the particle
    std::cout << "Particle: " << grid.m_buckets[0].m_particles.m_positions[0].x << ", " << grid.m_buckets[0].m_particles.m_positions[0].y << ", " << grid.m_buckets[0].m_particles.m_positions[0].z << std::endl;


    return 0;
}
