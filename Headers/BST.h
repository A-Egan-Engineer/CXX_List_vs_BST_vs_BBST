#ifndef CXX_LIST_VS_BST_VS_BBST_BST_H
#define CXX_LIST_VS_BST_VS_BBST_BST_H

#pragma once
#include "../Headers/Node.h"
#include <iostream>

using namespace std;

class BST {

    public:
    Node* root = nullptr;

    virtual void insert(Node* newNode);
    Node* search(int data, bool showSearchPath = false);
};
#endif //CXX_LIST_VS_BST_VS_BBST_BST_H
