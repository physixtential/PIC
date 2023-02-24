#pragma once
#include "Vec3.h"
#include "ParticleSystem.h"


struct Bucket {
    Bucket(const Vec3<int> lowerLeft, const float dx);

    // The integer position of the bucket. I should check if one exists at that location whenever creating one and do something different
    Vec3<int> m_lowerLeft;

    // The side dimension of the square bucket.
    float m_dx;

    // Center of mass of the bucket
    Vec3<float> m_centerOfMass;

    // The particles in the bucket
    ParticleSystem m_particles;
};