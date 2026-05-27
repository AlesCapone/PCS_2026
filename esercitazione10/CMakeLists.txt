cmake_minimum_required(VERSION 3.20)

project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror")

find_package(Eigen3 REQUIRED)

add_executable(test_gradiente test_gradiente.cpp)
add_test(NAME test_gradiente COMMAND test_gradiente) 

target_link_libraries(test_gradiente Eigen3::Eigen)

enable_testing()