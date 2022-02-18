cmake_minimum_required(VERSION 3.18)
include(GoogleTest)
add_executable(otus2_test test.cpp  unit2_tests.cpp)
include_directories(${PROJECT_SOURCE_DIR}/unit2)
target_link_libraries(otus2_test gtest)
add_test( otus2_test otus2_test )

gtest_discover_tests(otus2_test)