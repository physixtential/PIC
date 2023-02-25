#include "Bucket.h"

Bucket::Bucket(const Vec3<int> lowerLeft, const float dx):
    m_lowerLeft(lowerLeft),
    m_dx(dx)
{}

void Bucket::updateCenterOfMass() {
    m_centerOfMass = Vec3<float>(0.0f, 0.0f, 0.0f);
    m_totalMass = 0.0f;
    for (int i = 0; i < m_particles.m_positions.size(); i++) {
        m_centerOfMass += m_particles.m_positions[i] * m_particles.m_masses[i];
        m_totalMass += m_particles.m_masses[i];
    }
    m_centerOfMass /= m_totalMass;
}