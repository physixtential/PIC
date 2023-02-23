#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
}

ParticleSystem::~ParticleSystem() {
}

void ParticleSystem::addParticle(const Vec3<float> position, const Vec3<float> velocity, const float mass)
{
    m_positions.push_back(position);
    m_velocities.push_back(velocity);
    m_masses.push_back(mass);
}
