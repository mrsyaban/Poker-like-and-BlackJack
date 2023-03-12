#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"
#include <vector>
#include <algorithm>
using namespace std;

class InventoryHolder
{
protected:
    vector<Card> cards;

public:
    virtual ~InventoryHolder(); // dtor
    void addCard(const Card&);
    void delCard(const Card&);
    vector<Card>& getCards();
    virtual InventoryHolder& operator+(const Card &) = 0;
    virtual InventoryHolder& operator-(const Card &) = 0;
    virtual InventoryHolder& operator=(InventoryHolder &) = 0;
};

#endif