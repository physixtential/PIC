#pragma once
#include <vector>
#include <memory>
#include "Vec3.h"
#include "Bucket.h"

struct Grid {
    // The buckets in the grid
    std::vector<Bucket> m_buckets;

    // Side length of the square buckets
    float m_dx;

    // The dimensions of the grid
    Vec3<float> m_dimensions;

    Vec3<int> m_lowerLeft;

    // Constructor
    Grid(const Vec3<int> lowerLeft, const Vec3<float> dimensions, const float dx);

    // Returns true if the bucket exists in the grid
    std::unique_ptr<Bucket> bucketExists(const Bucket& bucket);

    // Checks if a bucket exists, if not, adds a bucket to the grid. Returns a pointer to the bucket.
    std::unique_ptr<Bucket> addBucket(const Bucket& bucket);

    // Return the bucket in which the provided position resides. If the bucket does not exist, create it.
    std::unique_ptr<Bucket> getBucket(const Vec3<float> position);

    // Returns nearest bucket lower left coordinates for given flost position.
    Vec3<int> bucketLocation(const Vec3<float> position, const float dx);

    // Prints the grid
    void printGrid();

    // Prints the grid with coordinates
    void printGridWithCoords();

    // Get neighbors of a bucket
    std::vector<Bucket> getNeighbors(const Bucket& bucket);

    // Bucketize particle
    void bucketizeParticle(const Vec3<float>& position, const Vec3<float>& velocity, const float mass);

    // Bucketize particle system
    void bucketizeParticleSystem(const ParticleSystem& particles);
};