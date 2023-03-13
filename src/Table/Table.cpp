#include "Table.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Table::Table(){
    neff = 0;
}

void Table::getInfo() const {
    cout << "This is Table Card" << endl;
}