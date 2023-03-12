#include "Deck.hpp"
#include <iostream>
using namespace std;

int main () {   
    Deck d;
    for (int i = 0; i < 52; i++) {
        cout << d.cards.at(i).number << endl; // jangan lupa pake getter :')
    }

    return 0;
}