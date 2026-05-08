#include "../Headers/MainMenu.h"

using namespace std;

Node* root = nullptr;
LinkedList list1;
BST bst1;
AVL avl1;

typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds ms;

void MainMenu::populateLists() {

    for (int i = 1; i <= 150000; i++) {
        int r = rand() % 1000000;
        list1.insertAtStart(r);
        bst1.insert(new Node (r));
        root = avl1.insert(root,(r));
    }
}

void MainMenu::searchNumber() {
    int searchNumber;

    cout << "Enter a number to search: " << endl;
    cin >> searchNumber;

    cout << endl;

    cout << "Searching Linked List..." << endl;
    auto startListSearch = Clock::now();
    list1.searchList(searchNumber);
    auto endListSearch = Clock::now();
    auto duration = chrono::duration_cast<ms>(endListSearch - startListSearch);
    cout << "Linked List Search Time: " << duration << endl;

    cout << endl;

    cout << "Searching Binary Search Tree: " << endl;
    auto startBinarySearchTree = Clock::now();
    Node* bstPtr = bst1.search(searchNumber, true);
    auto endBinarySearchTree = Clock::now();
    auto duration1 = chrono::duration_cast<ms>(endBinarySearchTree - startBinarySearchTree);
    if (bstPtr == nullptr) {
        cout << "Not Found" << endl;
    }
    else {
        cout << "Found -> " << bstPtr->data << " in Binary Search Tree" << endl;
    }
    cout << "Binary Search Tree Search Time: " << duration1 << endl;

    cout << endl;

    cout << "Searching AVL Tree: " << endl;
    auto startAVLTree = Clock::now();
    Node* avlPtr = avl1.search(root, searchNumber, true);
    auto endAVLTree = Clock::now();
    auto duration2 = chrono::duration_cast<ms>(endAVLTree- startAVLTree);
    if (avlPtr == nullptr) {
        cout << "Not Found" << endl;
    }
    else {
        cout << "Found -> " << avlPtr->data << " in AVL Tree" << endl;
    }
    cout << "AVL Search Time: " << duration2 << endl;

    cout << endl;

    cout << "Linked List Time: " << duration << endl;
    cout << "BST Time: " << duration1 << endl;
    cout << "AVL Time: " << duration2 << endl;

    cout << endl;
}

void MainMenu::mainMenu() {
    int menuChoice;

    populateLists();

    while (true) {
        cout << endl;
        cout << "Main Menu" << endl;
        cout << "1. Search for Number in Data Structures" << endl;
        cout << "2. Exit Program" << endl;
        cout << endl;

        cin >> menuChoice;

        if (menuChoice == 1) {
            searchNumber();
        }
        else if (menuChoice == 2) {
            cout << "Exiting Program..." << endl;
            sleep(3);
            break;
        }
        else {
            cout << endl;
            cout << "Invalid Choice" << endl;
        }
    }
}
