#include "InventoryHolder.hpp"
#include <iostream>
using namespace std;

template <class T>
InventoryHolder<T>::~InventoryHolder()
{
    while (!this->cards.empty())
    {
        this->cards.pop_back();
    }
    cout << "vector cards telah dikosongkan" << endl;
}

InventoryHolder<class T>& InventoryHolder<class T>::operator+(const T& other){
    items.push_back(other);
}

template<>
InventoryHolder<Card>& InventoryHolder<Card>::operator-(const Card& other){
    auto itr = this->items.begin();
    while (!(*itr == other)) {
        itr++;
    }
    items.erase(itr);
}

template<>
InventoryHolder<Ability>& InventoryHolder<Ability>::operator-(const Ability& other){
    auto itr = this->items.begin();
    while (*itr.getType() != other.getType()) {
        itr++;
    }
    items.erase(itr);
}

InventoryHolder<class T>& InventoryHolder<class T>::operator=(InventoryHolder& other){
    this->items = other.items;
    return *this;
}
        

template class InventoryHolder<Card>;
template class InventoryHolder<Ability>;
// either : pindahin hpp atau bikin instance satu satu
