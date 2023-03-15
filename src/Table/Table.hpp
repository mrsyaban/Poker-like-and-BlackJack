#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdlib.h>
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;


class Table: public InventoryHolder<Card> {
    protected:
        int neff;
    
    public:
        Table();
        void dealToTable(InventoryHolder<Card>&);
        void openCard();
        

        /* Getter */
        void getInfo() const;
        int getNeff() const;

};

#endif