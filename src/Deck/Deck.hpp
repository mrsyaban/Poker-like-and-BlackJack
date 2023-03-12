#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
using namespace std;

class Deck: public InventoryHolder {
    protected:

    public:
        Deck();
        Deck& operator+(const Card&);
};

#endif