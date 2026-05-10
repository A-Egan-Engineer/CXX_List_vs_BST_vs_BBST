#include "../Headers/LinkedList.h"

// Iterates through the list, adding one to counter
// until list is exhausted (tail->null).
int LinkedList::listCount(){
    int counter = 0;
    Node* temp = head;

    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

// Iterates through the list until the value stored in
// the key variable is found and prints the key and index
// key is found at. If key value is not found in list, it
// returns 0.
int LinkedList::searchList(int key) {

    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "The integer " << key << " found in the list at index " << index << endl;
            return 1;
        }
        temp = temp->next;
        index++;
    }
    return 0;
}

// Iterates through list and prints data in list,
// until list is exhausted.
void LinkedList::display() {

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

// Insertion of node at the start of the list.
void LinkedList::insertAtStart(int data) {

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insertion of node at the end of the list.
void LinkedList::insertAtEnd(int data) {

    if (head == nullptr) {
        insertAtStart(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
}

// Inserts node at a specified index within the list.
void LinkedList::insertAtPos(int data, int index) {
    Node* newNode = new Node(data);
    Node* temp = head;
    Node* previous = head;
    for (int i = 0; i < index; i++) {
        previous = temp;
        temp = temp->next;
    }
    newNode->next = temp;
    previous->next = newNode;
    if (head == nullptr) {
        insertAtStart(data);
        return;
    }
    if (index >= listCount()) {
        insertAtEnd(data);
    }
}

// Deletes the head node, replaces head with index 1.
void LinkedList::deleteAtStart() {

    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Deletes the tail node, and node at tail -1 becomes
// new tail node.
void LinkedList::deleteAtEnd() {


    if (head == nullptr) {
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    Node* previous = head;
    while (temp->next != nullptr) {
        previous = temp;
        temp = temp->next;
    }
    previous->next = nullptr;
    delete temp;
}

// Deletes a node at a specific index in the list.
void LinkedList::deleteAtPos(int index) {

    if (head == nullptr) {
        return;
    }
    if (index == 0) {
        deleteAtStart();
        return;
    }
    if (index >= listCount() - 1) {
        deleteAtEnd();
        return;
    }
    Node* temp = head;
    Node* previous = head;
    for (int i = 0; i < index; i++) {
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
    delete temp;


}