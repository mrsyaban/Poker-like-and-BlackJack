#include "Table.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Table::Table(){
    neff = 0;
}

void Table::dealToTable(InventoryHolder<Card>& deck) {
    this->deleteall();
    this->neff = 0;
    this->add(deck);
    this->add(deck);
    this->add(deck);
    this->add(deck);
    this->add(deck);
}

void Table::openCard() {
    this->neff++;
}

void Table::getInfo() const {
    cout << "This is Table Card" << endl;
}

int Table::getNeff() const {
    return this->neff;
Card Table::getCard(int position) const {
    return this->items[position];
}