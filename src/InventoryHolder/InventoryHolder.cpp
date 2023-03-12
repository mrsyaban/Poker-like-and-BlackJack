#include "InventoryHolder.hpp"
#include <iostream>
using namespace std;

InventoryHolder::~InventoryHolder()
{
    while (!this->cards.empty())
    {
        this->cards.pop_back();
    }
    cout << "vector cards telah dikosongkan" << endl;
}

void InventoryHolder::addCard(const Card& c) {
    this->cards.push_back(c);
}

void InventoryHolder::delCard(const Card& c) {
    auto cardAt = this->cards.begin();
    this->cards.erase(cardAt);
}