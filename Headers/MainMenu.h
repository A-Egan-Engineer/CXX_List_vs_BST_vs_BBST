#ifndef CXX_LIST_VS_BST_VS_BBST_MAINMENU_H
#define CXX_LIST_VS_BST_VS_BBST_MAINMENU_H
#include "../Headers/BST.h"
#include "../Headers/AVL.h"
#include "../Headers/LinkedList.h"
#include "..//Headers/Node.h"
#include <chrono>
#include <unistd.h>
#include <iostream>

using namespace std;

// Main menu class that houses the functionality of
// the included structures. This allows main.cpp to
// consist of constructing a main menu and calling
// the menu function (2 lines of code).
class MainMenu {

    public:
    void mainMenu();
    void populateLists();
    void searchNumber();
};

#endif //CXX_LIST_VS_BST_VS_BBST_MAINMENU_H
