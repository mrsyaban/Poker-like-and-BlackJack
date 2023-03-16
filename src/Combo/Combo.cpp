#include <iostream>
#include "Combo.hpp"
#include "../ArrayUtil/ArrayUtil.hpp"
using namespace std;

Combo::Combo() : score(0) {}

Combo::~Combo() {}

double Combo::value() const {return this->score;}

void Combo::setScore(double number) {this->score = number;}

vector<Card> Combo::getCombo() const {return this->combo;}

void Combo::setCombo(Combo other) {
    this->combo = other.combo;
    this->score = other.score;
}

void Combo::setCombo(vector<Card> combo) {this->combo = combo;}

bool Combo::operator<(const Combo& other) {
    if (this->value() < other.value()) {
        return true;
    } else {
        return false;
    }
}

bool Combo::operator>(const Combo& other) {
    if (this->value() > other.value()) {
        return true;
    } else {
        return false;
    }
}

bool Combo::operator==(const Combo& other) {
    if (this->value() == other.value()) {
        if (this->combo.size() == other.getCombo().size()) {
            bool same = true;
            unsigned int i = 0;

            while (same && i < this->combo.size()) {
                if (this->combo[i] == other.getCombo()[i]) {
                    i++;
                } else {
                    same = false;
                }
            }

            return same;
        } else {
            return false;
        }
    } else {
        return false;
    }
}