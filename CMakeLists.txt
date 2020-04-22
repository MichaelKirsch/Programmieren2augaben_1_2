cmake_minimum_required(VERSION 3.15)
project(Programmieren2augaben_1_2)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE sourceFiles "src/*.hpp" "src/*.h" "src/*.cpp")

add_executable(Programmieren2augaben_1_2 main.cpp ${sourceFiles})