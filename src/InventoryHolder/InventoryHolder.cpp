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
    while (itr->getType() != other.getType()) {
        itr++;
    }
    items.erase(itr);
}

InventoryHolder<class T>& InventoryHolder<class T>::operator=(InventoryHolder& other){
    this->items = other.items;
    return *this;
}

template <class T>
void InventoryHolder<class T>::add(InventoryHolder& other) {
    T temp = other.items.at(0);
    this->items = this->items + temp;
    other.items = other.items - temp;
}   

template <class T>
void InventoryHolder<class T>::exchange(InventoryHolder& other) {
    T temp = other.items.at(0);
    T temp2 = this->items.at(0);
    this->items = this->items + temp;
    this->items = this->items - temp2;
    other.items = other.items + temp2;
    other.items = other.items - temp;
}   

template <class T>
void InventoryHolder<class T>::deleteall() {
    this->items.clear();
}

template <class T>
void InventoryHolder<class T>::puttoback() {
    T temp = other.items.at(0);
    this->items = this->items - temp;
    this->items = this->items + temp;
}

template class InventoryHolder<Card>;
template class InventoryHolder<Ability>;
// either : pindahin hpp atau bikin instance satu satu
