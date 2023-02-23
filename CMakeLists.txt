cmake_minimum_required(VERSION 3.22)
project(PIC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")

add_executable(PIC 
main.cpp
Bucket.cpp
Bucket.h
Vec3.cpp
Vec3.h
Utils.h
Grid.cpp
Grid.h
ParticleSystem.h
ParticleSystem.cpp
)

