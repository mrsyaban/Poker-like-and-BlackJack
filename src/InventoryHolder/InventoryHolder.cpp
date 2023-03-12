#include "InventoryHolder.hpp"
#include <iostream>
using namespace std;

InventoryHolder::InventoryHolder()
{
    this->cardsLength = 0;
}

InventoryHolder::~InventoryHolder()
{
    while (!cards.empty())
    {
        cards.pop_back();
    }
    cout << "vector cards telah dikosongkan" << endl;
}

InventoryHolder InventoryHolder::operator+(const Card &c)
{
    cards.push_back(c);
    this->cardsLength++;
}

InventoryHolder InventoryHolder::operator-(const Card &c)
{
    if (find(cards.begin(), cards.end(), c) != cards.end())
    {
        cards.erase(std::remove(cards.begin(), cards.end(), c), cards.end());
        this->cardsLength--;
    }
    else
    {
        // exception card not found??;
    }
}