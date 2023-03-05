#include "InventoryHolder.hpp"
#include <iostream>
using namespace std;

InventoryHolder::InventoryHolder()
{
    this->cardsLength = 0;
    this->cards = new Card[cardsLength];
}

InventoryHolder::~InventoryHolder()
{
    delete[] cards;
}

InventoryHolder InventoryHolder::operator+(const Card &c)
{
    Card *temp = new Card[cardsLength];
    for (int i = 0; i < cardsLength; i++)
    {
        temp[i] = cards[i];
    }
    delete[] cards;

    this->cardsLength++;
    this->cards = new Card[cardsLength];
    for (int i = 0; i < cardsLength - 1; i++)
    {
        cards[i] = temp[i];
    }
    delete[] temp;
    cards[cardsLength - 1] = c;
    return *this;
}

InventoryHolder InventoryHolder::operator-(const Card &c)
{
}
