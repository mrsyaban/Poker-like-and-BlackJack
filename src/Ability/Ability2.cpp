#include <iostream>
#include "Ability2.hpp"
using namespace std;

Ability::Ability() {
    this->available = true;
}

Ability::~Ability() {

}

ReRoll::ReRoll() {
    
}

ReRoll::~ReRoll() {

}

void ReRoll::executeAbility() {

}

/* Quadraple */
Quadruple::Quadruple(Point* _p) {
    this->point = _p;
}

void Quadruple::executeAbility() {
    point->Quadraple();
}

/* Quarter */
Quarter::Quarter(Point* _p) {
    this->point = _p;
}

void Quarter::executeAbility() {
    point->Quarter();
}

ReverseDirection::ReverseDirection() {
    
}

ReverseDirection::~ReverseDirection() {

}

void ReverseDirection::executeAbility() {

}

SwapCard::SwapCard() {
    
}

SwapCard::~SwapCard() {

}

void SwapCard::executeAbility() {

}

Switch::Switch() {
    
}

Switch::~Switch() {

}

void Switch::executeAbility() {

}

Abilityless::Abilityless() {
    
}

Abilityless::~Abilityless() {

}

void Abilityless::executeAbility() {

}