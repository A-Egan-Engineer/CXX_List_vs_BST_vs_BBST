#ifndef CXX_LIST_VS_BST_VS_BBST_NODE_H
#define CXX_LIST_VS_BST_VS_BBST_NODE_H


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {};

};

#endif //CXX_LIST_VS_BST_VS_BBST_NODE_H
