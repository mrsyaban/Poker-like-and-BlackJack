#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"
#include <vector>
#include <algorithm>
using namespace std;

class InventoryHolder
{
private:
    vector<Card> cards;

public:
    virtual ~InventoryHolder(); // dtor
    void addCard(const Card&);
    void delCard(const Card&);
    virtual InventoryHolder& operator+(const Card &) = 0;
    virtual InventoryHolder& operator-(const Card &) = 0;
    virtual InventoryHolder& operator=(const InventoryHolder &) = 0;
};

#endif