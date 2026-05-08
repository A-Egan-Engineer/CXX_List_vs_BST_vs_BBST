#include "../Headers/AVL.h"


using namespace std;

int AVL::Max(int a, int b) {
    return a > b ? a : b;
}

int AVL::Height(Node* node) {
    if (node == nullptr)
        return 0;
    else return node->height;
}

Node* AVL:: newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return (node);
}

Node* AVL::rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp2 = x->right;
    x->right = y;
    y->left = temp2;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
    return x;
}

Node* AVL::leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp2 = y->left;
    y->left = x;
    x->right = temp2;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
    return y;
}

int AVL::getBalance(Node *node) {
    if (node == nullptr)
        return 0;
    return Height(node->left) - Height(node->right);
}

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

Node *AVL::minValueNode(Node *node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

void AVL::printTree(Node* root) {
    if (root == nullptr)
        return;
    if (root != nullptr) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

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