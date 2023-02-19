cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(untitled1 main.cpp Bucket.cpp Bucket.h Vec3.cpp Vec3.h Utils.h Grid.cpp Grid.h Test.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(untitled1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
