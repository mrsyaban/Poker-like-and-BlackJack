#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"

class InventoryHolder
{
protected:
    int cardsLength;
    Card *cards;

public:
    InventoryHolder();  // ctor
    ~InventoryHolder(); // dtor
    virtual InventoryHolder operator+(const Card &);
    virtual InventoryHolder operator-(const Card &);
};

#endif