cmake_minimum_required(VERSION 3.15)
project(lab_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_2 main.cpp Table/Table.cpp Table/Table.h Table/TableElement.h KeyOrdTable/KeyOrdTable.cpp KeyOrdTable/KeyOrdTable.h ValueOrdTable/ValueOrdTable.cpp ValueOrdTable/ValueOrdTable.h FrOrdTable/FrOrdTable.cpp FrOrdTable/FrOrdTable.h)