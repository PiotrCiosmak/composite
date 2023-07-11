cmake_minimum_required(VERSION 3.25)
project(composite)

set(CMAKE_CXX_STANDARD 23)

add_executable(composite main.cpp src/Component.cpp src/Leaf.cpp src/Composite.cpp)
