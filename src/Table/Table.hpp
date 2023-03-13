#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdlib.h>
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;

class Table: public InventoryHolder<Card> {
    private:
        int neff;
    
    public:
        Table();
        void getInfo() const;

};

#endif