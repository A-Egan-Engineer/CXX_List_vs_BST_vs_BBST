#include "../Headers/LinkedList.h"
#include "../Headers/Node.h"

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
        cout << temp->data; // Prints data of current node
        cout << endl;
        temp = temp->next; // Jumps to next node address
    }
    cout << endl;
}

void LinkedList::insertAtStart(int data) {

    Node* newNode = new Node(data); // Creates a new node to be inserted into a list at beginning (new head)
    newNode->next = head; // New node points to current head
    head = newNode; // Updates head of list to store new head
}

void LinkedList::insertAtEnd(int data) {

    if (head == nullptr) { // If list is empty
        insertAtStart(data); // Insert node at beginning of list
        return; // Early exit if list is empty and node inserted at beginning
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    while (temp->next != nullptr) { // Loops through list until end is reached
        temp = temp->next; // Points to next node in list
    }
    temp->next = newNode; // Previous node points to new node
    newNode->next = nullptr; // New tail node points to NULL
}

void LinkedList::insertAtPos(int data, int index) {
    Node* newNode = new Node(data);
    Node* temp = head;
    Node* previous = head;
    for (int i = 0; i < index; i++) { // Loops through list until index is reached
        previous = temp; // Previous node stored as temp
        temp = temp->next; // temp becomes next node after new node insertion
    }
    newNode->next = temp; // New node set to point to next node
    previous->next = newNode; // previous node set to point to
    if (head == nullptr) { // If head is empty
        insertAtStart(data); // Insert new node at start of list (head)
        return; // Exits early when above if statement is condition is met
    }
    if (index >= listCount()) { // If index is greate than or equal to node count
        insertAtEnd(data); // Insert new node at end of list (tail)
    }
}

void LinkedList::deleteAtStart() {

    if (head == nullptr) { // If list is empty, deletes nothing by exiting early (safeguard)
        return;
    }
    Node* temp = head; // Sets temp as current head node
    head = head->next; // Head moves to next position
    delete temp; // Deletes previous head node
}

void LinkedList::deleteAtEnd() {


    if (head == nullptr) { // If list is empty
        return; // Exits early
    }
    if (!head->next) { // If list consists of only one node
        delete head; // Deletes last node
        head = nullptr; // Head points to NULL
        return; // Exit early
    }
    Node* temp = head; // Temp points to head
    Node* previous = head; // Previous points to head
    while (temp->next != nullptr) { // Iterates through list until end of list is reached
        previous = temp; // Sets previous node to current node
        temp = temp->next; // temp stores next node
    }
    previous->next = nullptr; // New tail node points to NULL
    delete temp; // Deletes old node at end of list
}
void LinkedList::deleteAtPos(int index) {

    if (head == nullptr) {
        return;
    }
    if (index == 0) { // If list consists of only one node
        deleteAtStart(); // Delete from start of list
        return; // Exit early as sole node deleted
    }
    if (index >= listCount() - 1) { // If index is greater than index of last node
        deleteAtEnd(); // Delete end node
        return; // Exit early once end node deleted
    }
    Node* temp = head;
    Node* previous = head;
    for (int i = 0; i < index; i++) { // Loops through list until index is reached
        previous = temp; // Previous node stored as temp
        temp = temp->next; // temp becomes next node after new node insertion
    }
    previous->next = temp->next; // previous node set to point to next node, after node that is being deleted
    delete temp; // Deletes node at position of index


}