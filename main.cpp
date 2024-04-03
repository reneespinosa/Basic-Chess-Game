#include <iostream>
#include "Game/Game.h"

using namespace std;

int main() {


    cout << "Welcome to Chess!\n";

    bool controler = false;
    char choice;

    // Bucle del menú principal
    do {
        cout << "\nMain Menu:\n";
        cout << "1. New Game\n";
        cout << "2. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string player1Name, player2Name;
                cout << "\nEnter Player 1's name: ";
                cin >> player1Name;
                cout << "\nEnter Player 2's name: ";
                cin >> player2Name;

                // Iniciar un nuevo juego
                Game game(player1Name, player2Name);

                // Bucle del juego
                while (!game.getgameOver()) {
                   game.playMove();
                }

                cout<<"\n Congratulations!\n";
                char again ;
                cout<<"Play again? (Y) : \n";
                cin>>again;

                if(again!='Y')controler = true;

                break;
            }
            case '2':
                cout << "Thanks for playing Chess!\n";
                controler = true;
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (!controler);




    return 0;
}
