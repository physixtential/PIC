#include <iostream>
#include "Grid.h"
#include "ParticleSystem.h"
#include "Vec3.h"
#include <cmath>
#include <limits>
#include "Utils.h"
#include <map>
int main()
{
    // Create the particles
    std::cout << "Creating particles" << std::endl;
    ParticleSystem particles;
    for (size_t i = 0; i < 2000; i++)
    {
        Vec3<float> position = Vec3<float>(randomFloat(-50, 50), randomFloat(-50, 50), randomFloat(-50, 50));
        Vec3<float> velocity = Vec3<float>(randomFloat(-50, 50), randomFloat(-50, 50), randomFloat(-50, 50));
        float mass = randomFloat(1, 2);
        particles.addParticle(position, velocity, mass);
    }
    // // Print the positions
    // std::cout << "Positions:" << std::endl;
    // for (const auto& position : particles.m_positions)
    // {
    //     std::cout << position.x << ' ' << position.y << ' ' << position.z << std::endl;
    // }

    // Create the grid
    std::cout << "Creating grid" << std::endl;
    Grid grid(Vec3<int>(-50, -50, -50), Vec3<float>(100, 100, 100), 34);

    // Bucketize the particles
    std::cout << "Bucketizing particles" << std::endl;
    for (size_t i = 0; i < particles.m_positions.size(); i++)
    {
        grid.bucketizeParticle(particles.m_positions[i], particles.m_velocities[i], particles.m_masses[i]);
    }

    // Print the grid
    std::cout << "Printing grid" << std::endl;
    grid.printGridWithCoords();

    // lowest bucket
    const auto& bucket = grid.getBucket(Vec3<float>(-50, -50, -50));
    const auto& masses = bucket->m_particles.m_masses;
    std::cout << bucket->m_lowerLeft.x << ' ' << bucket->m_lowerLeft.y << ' ' << bucket->m_lowerLeft.z << ' ' << masses.size() << std::endl;

    // Print masses
    std::cout << "Masses:" << std::endl;
    for (const auto& mass : masses)
    {
        std::cout << mass << std::endl;
    }

    // Calculate the center of mass
    std::cout << "Calculating center of mass" << std::endl;
    Vec3<float> centerOfMass = Vec3<float>(0, 0, 0);
    float totalMass = 0;
    for (size_t i = 0; i < masses.size(); i++)
    {
        centerOfMass += bucket->m_particles.m_positions[i] * masses[i];
        totalMass += masses[i];
    }

    return 0;
}
