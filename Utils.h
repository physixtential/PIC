#include "Vec3.h"
#include "ParticleSystem.h"
#include "Grid.h"
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