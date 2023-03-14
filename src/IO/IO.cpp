#include "IO.hpp"

string retrieveInput(){
    string input;
    cout << "\033[0m" << "\033[1m\033[36m" << " ";
    cin >> input;
    cout << "\033[0m";
    return input;
}

void IO::splashScreen(){
    string splash = "WELKAMM";
    cout << splash << endl;
}

string IO::mainMenu(){
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "          MAIN MENU           " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << " 1. Start " << endl;
    cout << wordColor << " 2. Exit" << endl;
    cout << endl;
    cout << enterColor << "Enter Command >>>"; 
    
    string command = retrieveInput();
    cout << resetColor << endl;
    return command; 
}

void IO::inputPlayerName(Game& game){
    string nick1, nick2, nick3, nick4, nick5, nick6, nick7;
    cout << wordColor << "Please enter player name :" << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    for (int i=1; i<=7; i++) {
        cout << enterColor<< "Player " << i <<" >>> "; game.addPlayer();
    }
    cout << resetColor << endl;
}


