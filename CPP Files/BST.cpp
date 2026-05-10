#include "../Headers/BST.h"

using namespace std;

// Inserts a node as root if tree is empty.
// Otherwise, the new node size is compared to
// current left or right parent/child to find
// correct location in structure. Deletes node
// if another node in the list shares the same value.
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

// Allows the user to search the tree to find if a specific
// integer is include in the tree. Traverses the tree based on
// whether the number is smaller or larger the data stored in
// the current node it is comparing with before moving to left/right
// child.
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

