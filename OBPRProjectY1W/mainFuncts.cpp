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
    cout << "Would you like to try again?" << endl;
    do {
        cout << "Make a selection: " << endl
            << "1. My revenge will be immediate. Allow me to battle once more..." << endl
            << "2. Return to main menu." << endl
            << "Selection: ";
        cin >> gOSelection;
        switch (gOSelection) {
        case 1:
            return true;
            break;
        case 2:
            cout << "You have selected option 2." << endl;
            return false;
            break;
        default:
            cout << "Invalid selection. Try again." << endl;
        }
    } while (gOSelection != 1 && gOSelection != 2);
    return false;
}

bool gameStart() { //nathan's baby
    string pname;
    cout << "\nWhat is your name?\n"
        << "Name: ";
    cin >> pname;
    cout << "\n\n";
    cout << "You enter a deep, dark, and dank dungeon, when suddenly...\n"
        <<"A MONSTER APPEARS!!!\n"
        <<"You draw your sword and brace for the bloodshed to come...\n\n";

    Player* p = new Player(pname);
    Game* g = new Game();
    HealthPot* hp = new HealthPot(p->getInv(0));
    BigHeart* bh = new BigHeart(p->getInv(1));
    GreatSword* gs = new GreatSword(p->getInv(2));
    ToughShield* ts = new ToughShield(p->getInv(3));
    Opticals* o = new Opticals(p->getInv(4));
    int checkGame;
    system("pause");
    do {
        checkGame = g->GamePlay(p, bh, gs, hp, o, ts);
    } while (checkGame == 0);
    
    switch (checkGame) {
    case 1:
        return true;
        break;
    case 2:
        return false;
        break;
    }

}

