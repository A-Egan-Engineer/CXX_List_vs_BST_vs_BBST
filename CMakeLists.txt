cmake_minimum_required(VERSION 4.2)
project(CXX_List_vs_BST_vs_BBST)

set(CMAKE_CXX_STANDARD 20)

add_executable(CXX_List_vs_BST_vs_BBST main.cpp
        "CPP Files/BST.cpp"
        "Headers/BST.h"
        "Headers/Node.h"
        "CPP Files/LinkedList.cpp"
        "Headers/LinkedList.h"
        "CPP Files/AVL.cpp"
        "Headers/AVL.h"
        "CPP Files/MainMenu.cpp"
        "Headers/MainMenu.h")
