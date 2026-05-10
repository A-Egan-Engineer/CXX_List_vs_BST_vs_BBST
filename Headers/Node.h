#ifndef CXX_LIST_VS_BST_VS_BBST_NODE_H
#define CXX_LIST_VS_BST_VS_BBST_NODE_H

// Node Class used to create nodes across multiple data structures.
// Does not require a .cpp file as everything is initialised in
// the data structure classes.
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
