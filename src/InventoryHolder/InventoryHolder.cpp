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

// template <class T>
// void InventoryHolder<T>::addCard(const Card& c) {
//     this->cards.push_back(c);
// }

// template <class T>
// void InventoryHolder<T>::delCard(const Card& c) {
//     auto cardAt = this->cards.begin();
//     this->cards.erase(cardAt);
// }

// either : pindahin hpp atau bikin instance satu satu