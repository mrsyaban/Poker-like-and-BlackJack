#include <iostream>
#include "Deck.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;

InventoryHolder& Deck::operator+(const Card& c) {
    addCard(c);
    return *this;
}

InventoryHolder& Deck::operator-(const Card& c) {
    addCard(c);
    return *this;
}

InventoryHolder& Deck::operator=(InventoryHolder& other) {
    this->cards = other.getCards();
    return *this;
}

Deck::Deck() {
    vector<Card> tempDeck;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            Card temp = Card(CardColor(i), j);
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