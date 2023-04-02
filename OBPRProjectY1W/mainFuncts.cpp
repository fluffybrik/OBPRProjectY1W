#include "mainFuncts.h"

int menu() {
    int selection;
    bool tryagain = false;
    cout << endl << "MAIN MENU: " << endl;
        cout << "Type your selection" << endl
            << "1. Pull me forth into the heat of the battle..." << endl
            << "2. Quit" << endl
            << "Selection: ";
        cin >> selection;
    return selection;
}

bool gameOver() {
    int gOSelection;
    cout << "Hahahahaha loser. Would you like to try again?" << endl;
    do {
        cout << "Make a selection: " << endl
            << "1. My revenge will be immediate. Allow me to battle again..." << endl
            << "2. Return to main menu." << endl
            << "Selection: ";
        cin >> gOSelection;
        switch (gOSelection) {
        case 1:
            return true;
        case 2:
            cout << "You have selected option 2." << endl;
            return false;
        default:
            cout << "Invalid selection. Try again." << endl;
        }
    } while (gOSelection != 1 && gOSelection != 2);
    return false;
}

bool gameStart() { //ben's baby
    cout << endl << "You have selected option 1. Starting game..." << endl
        << "pew pew shooot shoot AHHHHHHHHHHHH" << endl
        << "game over...." << endl << endl; //ALL TEMPRORERYERYAERRAY
    return gameOver();
}

