#include "IO.hpp"

void IO::splashScreen(){
    string splash = "WELKAMM";
    cout << splash << endl;
}

void IO::inputPlayerName(){
    string inputNick;
    cout << "Silakan Masukkan Nama Pemain:" << endl;
    cout << "Player 1 : "; cin >> set(inputNick) >> endl;
}

