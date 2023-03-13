#include "IO.hpp"

void IO::splashScreen(){
    string splash = "WELKAMM";
    cout << splash << endl;
}


void IO::mainMenu(){
    string command;
    cout << "==============================" << endl;
    cout << "          MAIN MENU           " << endl;
    cout << "==============================" << endl;
    cout << " 1. Start " << endl;
    cout << " 2. Exit" << endl;
    cout << endl;
    cout << "Enter Command : "; cin >> command; 
}

void IO::inputPlayerName(){
    string nick1, nick2, nick3, nick4, nick5, nick6, nick7;
    cout << "Silakan Masukkan Nama Pemain :" << endl;
    cout << "==============================" << endl;
    cout << "Player 1 : "; cin >> nick1;
    cout << "Player 2 : "; cin >> nick2;
    cout << "Player 3 : "; cin >> nick3;
    cout << "Player 4 : "; cin >> nick4;
    cout << "Player 5 : "; cin >> nick5;
    cout << "Player 6 : "; cin >> nick6;
    cout << "Player 7 : "; cin >> nick7;
}
