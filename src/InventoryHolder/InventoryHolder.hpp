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
    InventoryHolder();          // ctor
    virtual ~InventoryHolder(); // dtor
    void addCard(const Card&);
    virtual InventoryHolder& operator+(const Card &) = 0;
    //friend vector<Card> operator-(vector<Card>, const Card &);
};

#endif