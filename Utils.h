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
