#include "../Headers/MainMenu.h"

using namespace std;

MainMenu::MainMenu() {

    cout << "Main Menu" << endl;
    cout << "1. Search for Number in Data Structures" << endl;
    cout << "2. Exit" << endl;

    cin >> menuChoice;

    if (menuChoice == 1) {
        cout << "Enter number to be searched: ";
        cin >> searchNumber;
    }
    else if (menuChoice == 2) {
        cout << "Exiting Program..." << endl;
        return;
    }
}