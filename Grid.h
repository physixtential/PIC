//
// Created by Job Guidos on 2/16/23.
//

#ifndef UNTITLED1_GRID_H
#define UNTITLED1_GRID_H

#include <vector>
#include "Bucket.h"

struct Grid {
    std::vector<Bucket> m_buckets;
    float m_dx;

    Grid(const Vec3<int> lowerLeft, const Vec3<float> upperRight, const float dx);

    bool bucketExists(const Bucket& bucket);
    void addBucket(const Bucket& bucket);
};


#endif //UNTITLED1_GRID_H
