#include <iostream>
#include "Ability.hpp"
#include "../Game/Game.hpp"

using namespace std;

Ability::Ability(string type) {
    available = true;
    this->type = type;
}


// ReRoll::ReRoll() : Ability("Reroll") {
    
// }

// ReRoll::~ReRoll() {
//     Ability::~Ability();
// }

// void ReRoll::Execute() {

// }

Quadruple::Quadruple() : Ability("Quadruple"){}

void Quadruple::Execute(Game& g) {
    g.getPoint().Quadruple();
}

Quarter::Quarter() : Ability("Quarter"){}

void Quarter::Execute(Game& g) {
    g.getPoint().Quarter();
}

// ReverseDirection::ReverseDirection(): Ability("Reverse") {
    
// }

// ReverseDirection::~ReverseDirection() {
//     Ability::~Ability();
// }

// void ReverseDirection::Execute() {

// }

// SwapCard::SwapCard(): Ability("Swap") {
    
// }

// SwapCard::~SwapCard() {
//     Ability::~Ability();
// }

// void SwapCard::Execute() {

// }

// Switch::Switch(): Ability("Switch") {
    
// }

// Switch::~Switch() {
//     Ability::~Ability();
// }

// void Switch::Execute() {

// }

// Abilityless::Abilityless(): Ability("Abilityless") {
    
// }

// Abilityless::~Abilityless() {
//     Ability::~Ability();
// }

// void Abilityless::Execute() {

// }