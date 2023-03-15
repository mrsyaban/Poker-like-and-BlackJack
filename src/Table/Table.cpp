#include "Table.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

template <>
Table<Card>::Table(){
    neff = 0;
}

template <>
void Table<Card>::dealToTable(InventoryHolder<Card>& deck) {
    this->deleteall();
    this->neff = 0;
    this->add(deck);
    this->add(deck);
    this->add(deck);
    this->add(deck);
    this->add(deck);
}

template <>
void Table<Card>::openCard() {
    this->neff++;
}

template <>
void Table<Card>::getInfo() const {
    cout << "This is Table Card" << endl;
}

template <>
int Table<Card>::getNeff() const {
    return this->neff;
}

Card Table::getCard(int i) const {
    return this->items[i];
}