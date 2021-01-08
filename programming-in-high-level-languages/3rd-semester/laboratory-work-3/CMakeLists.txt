cmake_minimum_required(VERSION 3.17)
project(laboratory_work_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread -g")

add_executable(laboratory_work_3 main.cpp AvlTree/AvlTree.h AvlTree/AvlTree.hpp)