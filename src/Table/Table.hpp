#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdlib.h>
#include "../InventoryHolder/InventoryHolder.hpp"
using namespace std;

class Table: public InventoryHolder {
    private:
        int neff;
    
    public:
        Table();

};

#endif