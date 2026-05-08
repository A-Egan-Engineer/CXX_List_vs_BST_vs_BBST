#include "Headers/BST.h"
#include "Headers/AVL.h"
#include "Headers/LinkedList.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {

    Node* root = nullptr;

    LinkedList list1;
    BST bst1;
    AVL avl1;

    for (int i = 1; i <= 150000; i++) {
        int r = rand() % 1000000;
        list1.insertAtStart(r);
        bst1.insert(new Node (r));
        root = avl1.insert(root,(r));
    }

    cout << endl;

    list1.searchList(1024);

    cout << endl;

    cout << "Searching for Integer 1024 " << endl;
    Node* BstPtr = bst1.search(1024,true);
    if (BstPtr == nullptr) {
        cout << "Not Found" << endl;
    }
    else {
        cout << "Found->" << BstPtr->data << endl;
    }
    cout << endl;

    cout << "Searching for Integer 1024 " << endl;
    Node* AvlPtr = avl1.search(root,1024,true);
    if (AvlPtr == nullptr) {
        cout << "Not Found" << endl;
    }
    else {
        cout << "Found->" << AvlPtr->data << endl;
    }
    cout << endl;

    return 0;
}
