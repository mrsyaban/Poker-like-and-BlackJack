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
        InventoryHolder<T>& operator+(const T&);
        InventoryHolder<T>& operator-(const T&);
        InventoryHolder<T>& operator=(InventoryHolder&);
        vector<T>& getItems();
        T& getTopItems();
        typename vector<T>::iterator getTopItemsIterator();
        void add(InventoryHolder&);
        void exchange(InventoryHolder&);
        void deleteall();
        void puttoback();
        T getItems(int i);
        virtual void getInfo() const = 0;
};

#endif