#include "Vec3.h"
#include "ParticleSystem.h"
#include "Grid.h"
#include "Bucket.h"
#include <random>

// Random float between min and max
float randomFloat(float min, float max)
{
    return min + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * (max - min);
}

// Return the element in the linear array that corresponds to the 3D index
int getLinearIndex(const Vec3<int>& ijk, const int resolution)
{
    return ijk.x + ijk.y * resolution + ijk.z * resolution * resolution;
}

// Return the 3D index that corresponds to the linear array index
Vec3<int> get3DIndex(const int index, const int resolution)
{
    Vec3<int> ijk;
    ijk.x = index % resolution;
    ijk.y = (index / resolution) % resolution;
    ijk.z = index / (resolution * resolution);
    return ijk;
}