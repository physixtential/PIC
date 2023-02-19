//
// Created by Job Guidos on 2/11/23.
//
#include "Vec3.h"

#ifndef UNTITLED1_BOX_H
#define UNTITLED1_BOX_H


struct Bucket {
    Bucket(const Vec3<int> lowerLeft, const float dx);

    // The integer position of the box. I should check if one exists at that location whenever creating one and do something different
    Vec3<int> m_lowerLeft;

    // The side dimension of the square box.
    float m_dx;
};


#endif //UNTITLED1_BOX_H
