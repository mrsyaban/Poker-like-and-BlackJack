#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdlib.h>
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;

template <class T>
class Table: public InventoryHolder<T> {
    protected:
        int neff;
    
    public:
        Table();
        void dealToTable(InventoryHolder<T>&);
        void openCard();
        

        /* Getter */
        void getInfo() const;
        int getNeff() const;

};

#endif