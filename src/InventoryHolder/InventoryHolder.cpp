#include "InventoryHolder.hpp"
#include <iostream>
using namespace std;

InventoryHolder::InventoryHolder() {
    
}

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

// vector<Card> InventoryHolder::operator-(const Card &c)
// {
//     if (find(cards.begin(), cards.end(), c) != cards.end())
//     {
//         cards.erase(std::remove(cards.begin(), cards.end(), c), cards.end());
//         this->cardsLength--;
//     }
//     else
//     {
//         // exception card not found??;
//     }
//     return cards;
// }