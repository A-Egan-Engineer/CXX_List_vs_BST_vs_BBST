#include "../Headers/LinkedList.h"

int LinkedList::listCount(){
    int counter = 0;
    Node* temp = head;

    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

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
    return -1;
}

void LinkedList::display() {

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::insertAtStart(int data) {

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

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

void LinkedList::deleteAtStart() {

    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

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