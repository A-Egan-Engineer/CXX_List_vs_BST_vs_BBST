#include "../Headers/BST.h"
#include <iostream>

using namespace std;

void BST::insert(Node *newNode) {
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (true) {
        parent = current;
        if (newNode->data < current->data) {
            current = current->left;
            if (current == nullptr) {
                parent->left = newNode;
                return;
            }
        }
        else if (newNode->data > current->data) {
            current = current->right;
            if (current == nullptr) {
                parent->right = newNode;
                return;
            }
        }
    }
}

Node* BST::search(int data, bool showSearchPath) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* current = root;

    while (current->data != data) {
        if (current == nullptr) {
            return nullptr;
        }

        if (showSearchPath) {
            cout << current->data << " " << endl;
        }

        if (data < current->data) {
            current = current->left;
        }
        else if (data > current->data) {
            current = current->right;
        }
    }

    return current;
}

