#ifndef CXX_LIST_VS_BST_VS_BBST_NODE_H
#define CXX_LIST_VS_BST_VS_BBST_NODE_H

class Node {
public:
    int data;
    Node* next;
    Node* left;
    Node* right;
    int height;

    Node(int data) : data(data), next(nullptr), left(nullptr), right(nullptr), height(1) {};

};

#endif //CXX_LIST_VS_BST_VS_BBST_NODE_H
