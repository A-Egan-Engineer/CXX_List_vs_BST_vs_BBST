#ifndef CXX_LIST_VS_BST_VS_BBST_AVL_H
#define CXX_LIST_VS_BST_VS_BBST_AVL_H
#include "../Headers/Node.h"
#include "../Headers/Node.h"
#include <algorithm>
#include <cstdio>
#include <iostream>

class AVL {

    public:
    AVL* left;
    AVL* right;
    Node* root = nullptr;

    int Max(int a, int b);
    int Height(Node* node);
    Node* newNode(int data);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    int getBalance(Node* node);
    Node* insert(Node* node, int data);
    Node* minValueNode(Node* node);
    void printTree(Node* root);
    Node* search(Node* node,int data, bool showSearchPath = false);

};


#endif //CXX_LIST_VS_BST_VS_BBST_AVL_H
