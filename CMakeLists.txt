cmake_minimum_required(VERSION 3.18)
project(otus2)
set(CMAKE_CXX_STANDARD 17)
enable_testing()
add_subdirectory(unit1)
add_subdirectory(unit2)
add_subdirectory(tests)
add_subdirectory(googletest)

