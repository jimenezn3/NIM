// Nick Diaz
// NIM Game


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    // Variables
    int aiMove;
    int playerMove;
    string playerName;
    int heap = 23;
    char start;

    srand(time(NULL));

    cout << "Would you like to play a game of NIM? (y/n) "; //Prompts user to play or not

    while (cin >> start) {
        if (start == 'y') { 		//Gameplay resulting in selecting 'y'
            cout << "Enter your name: ";
	cin.ignore();
            getline(cin, playerName);
            cout << "There are " << heap << " objects in the heap" << endl;
                do {
                    cout << playerName << ", how many objects will you remove? (1, 2, 3): ";
                    cin >> playerMove;

           	    if (playerMove > 3) { 			// To avoid cheating and breaking the program with a # higher than the heap
                        while (playerMove > 3) {
                            cout << "You cannot remove more than 3 objects at once, please enter a new number: ";
                            cin >> playerMove;
                        }
                    }

                    heap = heap - playerMove;
                    cout << heap << " left in the heap" << endl;
                    if (heap == 0) {
                        cout << "Computer wins" << endl;
                        return 0;
                    }

                    aiMove = (rand() % 3) + 1;

                    if (aiMove > heap) { 		// Checks if the computer's move is greater than the # of objects in the heap
                        while (aiMove > heap) {
                            aiMove = (rand() % 3) + 1;
                        }
                    }

                    cout << "Computer removing " << aiMove << " objects" << endl;
                    heap = heap - aiMove;
                    cout << heap << " left in the heap" << endl;
                    if (heap == 0) {
                        cout << "You win!" << endl;
                        return 0;
                    }
                } while (heap >= 0);
        }
        else if (start == 'n') {		 //Program exiting if 'n' is selected
            cout << "Ok, have a good day" << endl;
            break;
        }
        else { 			//Input validation
            cout << "Invalid input, please try again ";
        }
    }

    return 0;
}
