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

class MainMenu {

    public:
    void mainMenu();
    void populateLists();
    void searchNumber();
};

#endif //CXX_LIST_VS_BST_VS_BBST_MAINMENU_H
