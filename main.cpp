#include "Headers/BST.h"
#include <iostream>

#include "Headers/LinkedList.h"
#include "Headers/node.h"

using namespace std;

int main() {

    LinkedList list1;
    BST bst1;

    list1.insertAtStart(302);
    list1.insertAtStart(564);
    list1.insertAtStart(123);
    list1.insertAtStart(893);
    list1.insertAtStart(978);
    list1.insertAtStart(324);

    cout << endl;

    list1.searchList(893);

    list1.display();

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
    cout << endl;

    return 0;
}
