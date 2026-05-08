#include "../Headers/BST.h"

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
        else {
            delete newNode;
            return;
        }
    }
}

Node* BST::search(int data, bool showSearchPath) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* current = root;

    while (current != nullptr) {
        if (current->data == data) {
            return current;
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

