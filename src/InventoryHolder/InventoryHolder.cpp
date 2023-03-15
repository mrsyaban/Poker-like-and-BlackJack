#include "InventoryHolder.hpp"
#include <iostream>
using namespace std;

template <class T>
InventoryHolder<T>::~InventoryHolder()
{
    while (!this->items.empty())
    {
        this->items.pop_back();
    }
    cout << "vector cards telah dikosongkan" << endl;
}

template <class T>
InventoryHolder<T>& InventoryHolder<T>::operator+(const T& other){
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

template <class T>
InventoryHolder<T>& InventoryHolder<T>::operator=(InventoryHolder<T>& other){
    this->items = other.items;
    return *this;
}

template <class T>
vector<T>& InventoryHolder<T>::getItems() {
    return this->items;
}

template <class T>
T& InventoryHolder<T>::getTopItems() {
    return this->items;
}

template <class T>
typename vector<T>::iterator InventoryHolder<T>::getTopItemsIterator() {
    return this->items.begin();
}

template <class T>
void InventoryHolder<T>::add(InventoryHolder& other) {
    T temp = other.items.at(0);
    *this = *this + temp;
    other = other - temp;
}   

template <class T>
void InventoryHolder<T>::exchange(InventoryHolder& other) {
    T temp = other.items.at(0);
    T temp2 = this->items.at(0);
    *this = *this + temp;
    *this = *this - temp2;
    other = other + temp2;
    other = other - temp;
}   

template <class T>
void InventoryHolder<T>::deleteall() {
    this->deleteall();
}

template <class T>
void InventoryHolder<T>::puttoback() {
    T temp = this->items.at(0);
    *this = *this - temp;
    *this = *this + temp;
}


template class InventoryHolder<Card>;
template class InventoryHolder<Ability>;
// either : pindahin hpp atau bikin instance satu satu


template class InventoryHolder<ReRoll>;
template class InventoryHolder<Quadruple>;
template class InventoryHolder<Quarter>;
template class InventoryHolder<ReverseDirection>;
template class InventoryHolder<SwapCard>;
template class InventoryHolder<Switch>;
template class InventoryHolder<Abilityless>;