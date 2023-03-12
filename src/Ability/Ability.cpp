#include <iostream>
#include "Ability.hpp"
using namespace std;

Ability::Ability() {
    this->available = true;
}

Ability::~Ability() {

}

ReRoll::ReRoll() {
    
}

ReRoll::~ReRoll() {
    Ability::~Ability();
}

void ReRoll::executeAbility() {

}

Quadruple::Quadruple(): Ability() {
    
}

Quadruple::~Quadruple() {
    Ability::~Ability();
}

void Quadruple::executeAbility() {

}

ReverseDirection::ReverseDirection(): Ability() {
    
}

ReverseDirection::~ReverseDirection() {
    Ability::~Ability();
}

void ReverseDirection::executeAbility() {

}

SwapCard::SwapCard(): Ability() {
    
}

SwapCard::~SwapCard() {
    Ability::~Ability();
}

void SwapCard::executeAbility() {

}

Switch::Switch(): Ability() {
    
}

Switch::~Switch() {
    Ability::~Ability();
}

void Switch::executeAbility() {

}

Abilityless::Abilityless(): Ability() {
    
}

Abilityless::~Abilityless() {
    Ability::~Ability();
}

void Abilityless::executeAbility() {

}