cmake_minimum_required(VERSION 3.23)
project(test_exercise)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_exercise main.cpp)
target_link_libraries(test_exercise -static gcc stdc++ winpthread)