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

void ReRoll::Execute() {

}

Quadruple::Quadruple(): Ability() {
    
}

Quadruple::~Quadruple() {
    Ability::~Ability();
}

void Quadruple::Execute() {

}

ReverseDirection::ReverseDirection(): Ability() {
    
}

ReverseDirection::~ReverseDirection() {
    Ability::~Ability();
}

void ReverseDirection::Execute() {

}

SwapCard::SwapCard(): Ability() {
    
}

SwapCard::~SwapCard() {
    Ability::~Ability();
}

void SwapCard::Execute() {

}

Switch::Switch(): Ability() {
    
}

Switch::~Switch() {
    Ability::~Ability();
}

void Switch::Execute() {

}

Abilityless::Abilityless(): Ability() {
    
}

Abilityless::~Abilityless() {
    Ability::~Ability();
}

void Abilityless::Execute() {

}