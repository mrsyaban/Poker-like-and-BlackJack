#include <iostream>
#include "Deck.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;

template <class T>
Deck<T>::Deck() {
    vector<T> tempDeck;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            T temp = Card(CardColor(i), j);
            tempDeck.push_back(temp);
        }
    }

    while (!tempDeck.empty()) {
        int position = rand() % tempDeck.size();
        auto cardAt = tempDeck.begin() + position;
        *this = *this + tempDeck.at(position);
        tempDeck.erase(cardAt);        
    }

    // acak
}

template <>
void Deck<Card>::getInfo() const {
    cout << "This is Main Deck" << endl;
}

template <>
void Deck<Ability>::getInfo() const {
    cout << "This is Ability Deck" << endl;
}