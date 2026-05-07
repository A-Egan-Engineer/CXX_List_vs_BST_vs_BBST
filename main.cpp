#include "Headers/BST.h"
#include <iostream>

using namespace std;

int main() {
    BST bst1;

    bst1.insert(new Node(302));
    bst1.insert(new Node(564));
    bst1.insert(new Node(123));
    bst1.insert(new Node(893));
    bst1.insert(new Node(978));
    bst1.insert(new Node(324));

    cout << endl;
    cout << "Searching for Integer 978..." << endl;
    Node* Ptr = bst1.search(978, true);

    if (Ptr == nullptr){
        cout << "Not found" << endl;
    }
    else {
        cout << "Found -> " << Ptr->data << endl;
    }

    return 0;
}
