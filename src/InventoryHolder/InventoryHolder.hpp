#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"
#include <vector>
#include <algorithm>

class InventoryHolder
{
protected:
    int cardsLength;
    vector<Card> cards;

public:
    InventoryHolder();          // ctor
    virtual ~InventoryHolder(); // dtor
    vector<Card> operator+(const Card &);
    vector<Card> operator-(const Card &);
};

#endif