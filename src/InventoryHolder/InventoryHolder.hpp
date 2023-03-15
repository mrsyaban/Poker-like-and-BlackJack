#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include "../Card/Card.hpp"
// #include "../Ability/Ability.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class InventoryHolder
{
    protected:
        vector<T> items;

    public:
        ~InventoryHolder()
        {
            while (!this->items.empty())
            {
                this->items.pop_back();
            }
            cout << "vector cards telah dikosongkan" << endl;
        }

        InventoryHolder(const InventoryHolder& other) {
            this->items = other.items;
        }

        InventoryHolder<T>& operator+(const T& other){
            items.push_back(other);
        }

        InventoryHolder<T>& operator-(const T& other){
            auto itr = this->items.begin();
            while (!(*itr == other)) {
                itr++;
            }
            items.erase(itr);

            return *this;
        }

        InventoryHolder<T>& operator=(InventoryHolder<T>& other){
            this->items = other.items;
            return *this;
        }

        vector<T>& getItems() {
            return this->items;
        }

        T& getTopItems() {
            return this->items;
        }

        typename vector<T>::iterator getTopItemsIterator() {
            return this->items.begin();
        }

        void add(InventoryHolder& other) {
            T temp = other.items.at(0);
            *this = *this + temp;
            other = other - temp;
        }   

        void exchange(InventoryHolder& other) {
            T temp = other.items.at(0);
            T temp2 = this->items.at(0);
            *this = *this + temp;
            *this = *this - temp2;
            other = other + temp2;
            other = other - temp;
        }   

        void deleteall() {
            this->deleteall();
        }

        void puttoback() {
            T temp = this->items.at(0);
            *this = *this - temp;
            *this = *this + temp;
        }
};

// template<>
// InventoryHolder<Ability>& InventoryHolder<Ability>::operator-(const Ability& other){
//     auto itr = this->items.begin();
//     while (itr->getType() != other.getType()) {
//         itr++;
//     }
//     items.erase(itr);
// }

#endif