cmake_minimum_required(VERSION 4.2)
project(CXX_List_vs_BST_vs_BBST)

set(CMAKE_CXX_STANDARD 20)

add_executable(CXX_List_vs_BST_vs_BBST main.cpp
        "CPP Files/BST.cpp"
        "Headers/BST.h"
        "CPP Files/Node.cpp"
        "Headers/Node.h")
