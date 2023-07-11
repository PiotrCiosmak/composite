cmake_minimum_required(VERSION 3.25)
project(composite)

set(CMAKE_CXX_STANDARD 23)

add_executable(composite main.cpp include/Component.hpp src/Component.cpp include/Leaf.hpp src/Leaf.cpp include/Composite.hpp src/Composite.cpp)
