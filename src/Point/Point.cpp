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
int Point::getValue() const{
    return this->value;
}

void Point::setValue(int val) {
    this->value = val;
}

/* value modification from player skills */
void Point::Half(){
    this->value *= 0.5;
}

void Point::Double(){
    this->value *= 2;
}

void Point::Quadraple(){
    this->value *= 4;
}

void Point::Quarter(){
    this->value *= 0.25;
}

/* void */