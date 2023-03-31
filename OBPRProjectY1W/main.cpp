/*
COMMAND LINE WARRIORS

*/

#include "mainFuncts.h"

/////MAIN/////
int main()
{
    int selection;
    bool tryAgain;
    std::cout << "unga bunga bonanza\n";
    while (true) {
        selection = menu();
        switch (selection) {
        case 1:
            do {
                tryAgain = gameStart();
            } while (tryAgain == true);
            break;
        case 2:
            cout << endl << "You have selected option 2." << endl
                << "'Till next time, warrior." << endl;
            return 0;
            break;
        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }
    }
}
