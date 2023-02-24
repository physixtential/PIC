#include "Vec3.h"
#include "ParticleSystem.h"
#include "Grid.h"
#include "Bucket.h"
#include <random>

// Trilinear interpolation

// 1. Find the 8 grid points that surround the point
// 2. Find the distance between the point and the 8 grid points
// 3. Find the weight of each grid point
// 4. Find the interpolated value


// Random float between min and max
float randomFloat(float min, float max)
{
    return min + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * (max - min);
}

// Calculate the center of mass of a bucket
Vec3<float> getCenterOfMass(const Bucket& bucket)
{
    const auto& masses = bucket.m_particles.m_masses;
    const auto& positions = bucket.m_particles.m_positions;
    Vec3<float> comNumerator = Vec3<float>(0, 0, 0);
    float totalMass = 0;
    for (size_t i = 0; i < masses.size(); i++)
    {
        comNumerator += positions[i] * masses[i];
        totalMass += masses[i];
    }
    return comNumerator / totalMass;
}
Vec3<float> centerOfMass = Vec3<float>(0, 0, 0);
float totalMass = 0;
for (size_t i = 0; i < masses.size(); i++)
{
    centerOfMass += bucket->m_particles.m_positions[i] * masses[i];
    totalMass += masses[i];
}