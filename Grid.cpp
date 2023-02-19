//
// Created by Job Guidos on 2/16/23.
//

#include "Grid.h"
#include <cmath>

Grid::Grid(const Vec3<int> lowerLeft, const Vec3<float> dimensions, const float dx): m_dx(dx){
    Vec3<float> subdivisions = dimensions / dx;

    // Add buckets
    for (int i = 0; i < std::ceil(subdivisions.x); i++)
    {
        for (int j = 0; j < std::ceil(subdivisions.y); j++)
        {
            for (int k = 0; k < std::ceil(subdivisions.z); k++)
            {
                Vec3<int> bucketLowerLeft = lowerLeft + Vec3<int>(i, j, k);
                Bucket bucket = Bucket(bucketLowerLeft, dx);
                addBucket(bucket);
            }
        }
    }
}

bool Grid::bucketExists(const Bucket& bucket){
    bool found = false;
    for (const auto& existingBucket : m_buckets)
    {
        if (bucket.m_lowerLeft == existingBucket.m_lowerLeft)
            found = true;
    }
    return found;
    
}

void Grid::addBucket(const Bucket& bucket) {
    if (!bucketExists(bucket))
        m_buckets.push_back(bucket);
}