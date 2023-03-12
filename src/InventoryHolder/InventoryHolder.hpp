#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class InventoryHolder
{
private:
    vector<T> items;

public:
    virtual ~InventoryHolder(); // dtor
    void addCard(const T&);
    void delCard(const T&);
    // Rencana: pure virtual nya bakal info
    virtual InventoryHolder& operator+(const Card&);
    virtual InventoryHolder& operator-(const Card&);
    virtual InventoryHolder& operator=(const InventoryHolder&);
};

#endif