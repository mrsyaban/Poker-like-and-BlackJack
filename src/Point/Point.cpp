#include "Point.hpp"

// default ctor, value = 64
Point::Point(){
    this->value = 64;
} 

// ctor
Point::Point(int val){
    this->value = val;
} 

// getter / setter (don't set value directly, use for resetting game point only)
// use Add instead for adding value
long long Point::getValue() const{
    return this->value;
}

void Point::setValue(int val) {
    this->value = val;
}

/* value modification from player skills */
void Point::Half(){
    if (this->value < 2) return; // at least 2 to halve 
    this->value *= 0.5;
}

void Point::Double(){
    if (this->value > 4294967296) return; // max point
    this->value *= 2;
}

void Point::Quadruple(){
    if (this->value > 4294967296) return; // max point
    this->value *= 4;
}

void Point::Quarter(){
    if (this->value < 4) return; // at least 4 to quarter
    this->value *= 0.25;
}

void Point::Add(long long val){
    if (this->value > 4294967296) return; // max point
    this->value += val;
}

/* void */