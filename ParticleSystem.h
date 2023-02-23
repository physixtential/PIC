#pragma once
#include "Vec3.h"
#include <vector>

struct ParticleSystem
{
    std::vector<Vec3<float>> m_positions;
    std::vector<Vec3<float>> m_velocities;
    std::vector<float> m_masses;

    ParticleSystem();
    ~ParticleSystem();

    void addParticle(const Vec3<float> position, const Vec3<float> velocity, const float mass);
};
