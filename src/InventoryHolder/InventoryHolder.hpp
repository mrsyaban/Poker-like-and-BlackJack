#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class InventoryHolder
{
    protected:
        vector<T> items;

    public:
        ~InventoryHolder(); // dtor
        InventoryHolder<class T>& operator+(const T&);
        InventoryHolder<class T>& operator-(const T&);
        InventoryHolder<class T>& operator=(InventoryHolder&);
        void add(InventoryHolder&);
        void exchange(InventoryHolder&);
        void deleteall();
        void puttoback();
        virtual void getInfo() const = 0;
};

#endif