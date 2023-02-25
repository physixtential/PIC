//
// Created by Job Guidos on 2/11/23.
//

#ifndef UNTITLED1_VEC3_H
#define UNTITLED1_VEC3_H

template<typename T>
struct Vec3 {
public:
    Vec3() : x(0), y(0), z(0) {};

    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    T x;
    T y;
    T z;

};

template<typename T>
Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template<typename T>
bool operator==(const Vec3<T>& v1, const Vec3<T>& v2) {
    return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

template<typename T>
Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

// Scalar multiplication
template<typename T>
Vec3<T> operator*(const Vec3<T>& v, const T scalar) {
    return Vec3<T>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template<typename T>
Vec3<T> operator*(const T scalar, const Vec3<T>& v) {
    return Vec3<T>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template<typename T>
Vec3<T> operator/(const Vec3<T>& v, const float scalar) {
    return Vec3<T>(v.x / scalar, v.y / scalar, v.z / scalar);
}

template<typename T>
Vec3<T>& operator+=(Vec3<T>& v1, const Vec3<T>& v2) {
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1;
}

// Operator <
template<typename T>
bool operator<(const Vec3<T>& v1, const Vec3<T>& v2) {
    if (v1.x < v2.x) {
        return true;
    } else if (v1.x == v2.x) {
        if (v1.y < v2.y) {
            return true;
        } else if (v1.y == v2.y) {
            if (v1.z < v2.z) {
                return true;
            }
        }
    }
    return false;
}

// Operator /=
template<typename T>
Vec3<T>& operator/=(Vec3<T>& v1, const float scalar) {
    v1.x /= scalar;
    v1.y /= scalar;
    v1.z /= scalar;
    return v1;
}

#endif //UNTITLED1_VEC3_H
