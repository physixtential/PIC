#include "Grid.h"
#include <cmath>
#include <iostream>

Grid::Grid(const Vec3<int> lowerLeft, const Vec3<float> dimensions, const float dx):
    m_dx(dx),
    m_dimensions(dimensions),
    m_lowerLeft(Vec3<int>(std::floor(lowerLeft.x / dx), std::floor(lowerLeft.y / dx), std::floor(lowerLeft.z / dx)))
{
    Vec3<float> subdivisions = dimensions / dx;

    // Add buckets
    // TODO: Something very wrong here. Lets scrap this and go sparse
    for (int i = 0; i <= std::ceil(subdivisions.x); i++)
    {
        for (int j = 0; j <= std::ceil(subdivisions.y); j++)
        {
            for (int k = 0; k <= std::ceil(subdivisions.z); k++)
            {
                Vec3<int> bucketLowerLeft = m_lowerLeft + Vec3<int>(i, j, k);
                Bucket bucket = Bucket(bucketLowerLeft, dx);
                addBucket(bucket);
            }
        }
    }
}

Bucket* Grid::bucketExists(const Bucket& bucket)
{
    for (auto& existingBucket : m_buckets)
    {
        if (bucket.m_lowerLeft == existingBucket.m_lowerLeft)
            return &existingBucket;
    }
    return nullptr;
}

Bucket* Grid::addBucket(const Bucket& bucket)
{
    if (m_dx == 0)
        m_dx = bucket.m_dx;
    else if (m_dx != bucket.m_dx)
    {
        std::cout << "Bucket dx does not match grid dx. Not handled. You are going to break something." << std::endl;
    }
    auto* foundBucket = bucketExists(bucket);
    if (foundBucket != nullptr) {
        return foundBucket;
    }
    else {
        m_buckets.push_back(bucket);
        return &m_buckets[m_buckets.size() - 1];
    }
}

Bucket* Grid::getBucket(const Vec3<float> position)
{
    Vec3<int> bucketLowerLeft = Vec3<int>(std::floor(position.x / m_dx), std::floor(position.y / m_dx), std::floor(position.z / m_dx));
    for (Bucket& bucket : m_buckets)
    {
        if (bucket.m_lowerLeft == bucketLowerLeft)
        {
            return &bucket;
        }
    }
    std::cout << "Bucket does not exist at lowerLeft: " << bucketLowerLeft.x << ' ' << bucketLowerLeft.y << ' ' << bucketLowerLeft.z << " to accomodate: " << position.x << ' ' << position.y << ' ' << position.z << std::endl;
    return addBucket(Bucket(bucketLowerLeft, m_dx));
}

Vec3<int> Grid::bucketLocation(const Vec3<float> position, const float dx)
{
    return Vec3<int>(std::floor(position.x / dx), std::floor(position.y / dx), std::floor(position.z / dx));
}

void Grid::printGrid()
{
    // Print the grid
    std::cout << "Number of buckets: " << m_buckets.size() << std::endl;
    for (const auto& bucket : m_buckets)
    {
        if (bucket.m_lowerLeft.y != m_lowerLeft.y)
        {
            std::cout << std::endl;
            m_lowerLeft.y = bucket.m_lowerLeft.y;
        }
        if (bucket.m_lowerLeft.x != m_lowerLeft.x)
        {
            std::cout << std::endl
                << "x: " << bucket.m_lowerLeft.x << std::endl;
            m_lowerLeft.x = bucket.m_lowerLeft.x;
        }
        std::cout << "[" << bucket.m_particles.m_positions.size() << "]\n";
    }
}

void Grid::printGridWithCoords()
{
    // Print the grid
    std::cout << "Number of buckets: " << m_buckets.size() << std::endl;
    for (const auto& bucket : m_buckets)
    {
        std::cout << bucket.m_lowerLeft.x << '\t' << bucket.m_lowerLeft.y << '\t' << bucket.m_lowerLeft.z << "\t[" << bucket.m_particles.m_positions.size() << ']';
        // for (size_t i = 0; i < bucket.m_particles.m_positions.size(); i++)
        // {
        //     std::cout << "\t{" << (int)bucket.m_particles.m_positions[i].x << '\t' << (int)bucket.m_particles.m_positions[i].y << '\t' << (int)bucket.m_particles.m_positions[i].z << "}\t";
        // }
        std::cout << std::endl;
    }
}

std::vector<Bucket> Grid::getNeighbors(const Bucket& bucket)
{
    std::vector<Bucket> neighbors;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                Vec3<int> neighborLowerLeft = bucket.m_lowerLeft + Vec3<int>(i, j, k);
                Bucket neighbor = Bucket(neighborLowerLeft, m_dx);
                if (bucketExists(neighbor))
                {
                    neighbors.push_back(neighbor);
                }
            }
        }
    }
    return neighbors;
}

void Grid::bucketizeParticle(const Vec3<float> position, const Vec3<float> velocity, const float mass)
{
    Bucket* bucket = getBucket(position);
    bucket->m_particles.m_positions.push_back(position);
    bucket->m_particles.m_velocities.push_back(velocity);
    bucket->m_particles.m_masses.push_back(mass);
}
