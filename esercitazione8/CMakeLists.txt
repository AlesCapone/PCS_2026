cmake_minimum_required(VERSION 3.20)
project(esercitazione6) 

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla") 

add_executable(test_unidirected test_unidirected.cpp) 
add_test(NAME unidirected COMMAND test_unidirected) 

enable_testing()