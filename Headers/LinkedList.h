#ifndef CXX_LIST_VS_BST_VS_BBST_LINKEDLIST_H
#define CXX_LIST_VS_BST_VS_BBST_LINKEDLIST_H

#pragma once
#include <iostream>
#include "../Headers/Node.h"

using namespace std;

class LinkedList {

public:
    Node* head = nullptr;
    Node* tail = nullptr;

    int listCount();
    int searchList(int key);
    void display();

    void insertAtStart(int data);
    void insertAtEnd(int data);
    void insertAtPos(int data, int index);

    void deleteAtStart();
    void deleteAtEnd();
    void deleteAtPos(int index);
};

#endif //CXX_LIST_VS_BST_VS_BBST_LINKEDLIST_H
