#include "../Headers/AVL.h"


using namespace std;
// Compares two integers and returns the larger.
int AVL::Max(int a, int b) {
    return a > b ? a : b;
}
// Returns height of a given node.
int AVL::Height(Node* node) {
    if (node == nullptr)
        return 0;
    else return node->height;
}
// Initialises a new node for insertion to structure.
Node* AVL:: newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return (node);
}
// Performs a right rotate if tree is unbalanced left, by
// calculating and comparing the height of the left and
// right child nodes. Returns the new root.
Node* AVL::rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp2 = x->right;
    x->right = y;
    y->left = temp2;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
    return x;
}
// Performs a left rotate if tree is unbalanced right, by
// calculating and comparing the height of the left and
// right child nodes. Returns the new root.
Node* AVL::leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp2 = y->left;
    y->left = x;
    x->right = temp2;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
    return y;
}
// Used to get the balance of the tree, by comparing
// the height of the left node, minus the right.
// Tree is balanced if return = -1,0,1. Else,
// balancing is needed.
int AVL::getBalance(Node *node) {
    if (node == nullptr)
        return 0;
    return Height(node->left) - Height(node->right);
}
// Inserts the node into the tree based on size of data stored
// in the node, and uses the getBalance method the calculate balance.
// Makes comparisons of left vs right and rotate balance left or
// right depending on returned balance. Checks for LL/LR/RL/RR.
Node* AVL::insert(Node* node, int data) {
    if (node == nullptr)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(Height(node->left), Height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
// Finds and returns the smallest value node. Iterates
// through the left side of the tree until the child of
// node is null.
Node *AVL::minValueNode(Node *node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
// Method to print the data structure using
// in-order traversal method. Starts left->root->right.
void AVL::printTree(Node* root) {
    if (root == nullptr)
        return;
    if (root != nullptr) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}
// Allows the user to search the tree to find if a specific
// integer is include in the tree. Traverses the tree based on
// whether the number is smaller or larger the data stored in
// the current node it is comparing with before moving to left/right
// child.
Node* AVL::search(Node* node,int data, bool showSearchPath) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* current = node;

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