#include <iostream>
#include "Grid.h"

int main() {
    Grid grid(Vec3<int>(0,0,0), Vec3<float>(1,1,1), 0.1);

    // Print the grid
    for (const auto& bucket : grid.m_buckets)
    {
        std::cout << "Bucket: " << bucket.m_lowerLeft.x << ", " << bucket.m_lowerLeft.y << ", " << bucket.m_lowerLeft.z << std::endl;
    }

    // Print number of buckets
    std::cout << "Number of buckets: " << grid.m_buckets.size() << std::endl;

    // Fill the grid with particles


    return 0;
}
