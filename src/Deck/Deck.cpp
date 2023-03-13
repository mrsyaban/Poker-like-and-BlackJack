#include <iostream>
#include "Deck.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;

template <>
Deck<Card>::Deck() {
    vector<Card> tempDeck;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            Card temp = Card(CardColor(i), j);
            tempDeck.push_back(temp);
        }
    }

    this->deleteall();
    
    while (!tempDeck.empty()) {
        int position = rand() % tempDeck.size();
        auto cardAt = tempDeck.begin() + position;
        *this + tempDeck.at(position);
        tempDeck.erase(cardAt);        
    }
}

template <>
Deck<Ability>::Deck() {
    vector<Ability> tempDeck;

    ReRoll reRoll;
    tempDeck.push_back(reRoll);
    Quadruple quadruple;
    tempDeck.push_back(quadruple);
    Quarter quarter;
    tempDeck.push_back(quarter);
    ReverseDirection reverseDirection;
    tempDeck.push_back(reverseDirection);
    SwapCard swapCard;
    tempDeck.push_back(swapCard);
    Switch tukar;
    tempDeck.push_back(tukar);
    Abilityless abilityless;
    tempDeck.push_back(abilityless);

    this->deleteall();
    while (!tempDeck.empty()) {
        int position = rand() % tempDeck.size();
        auto abilityAt = tempDeck.begin() + position;
        *this + tempDeck.at(position);
        tempDeck.erase(abilityAt);        
    }
}

template <>
void Deck<Card>::getInfo() const {
    cout << "This is Main Deck" << endl;
}

template <>
void Deck<Ability>::getInfo() const {
    cout << "This is Ability Deck" << endl;
}