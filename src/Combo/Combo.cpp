#include <iostream>
#include "../Card/Card.hpp"
#include "Combo.hpp"
using namespace std;

Combo::Combo() : score(0) {}

Combo::Combo(SearchCombo combo) {
    this->combo = combo.getComboCards();
    this->score = 0;
}

Combo::~Combo() {}

double Combo::value() const {return this->score;}

void Combo::setScore(double number) {this->score = number;}

vector<Card> Combo::getCombo() const {return this->combo;}

void Combo::setCombo(vector<Card> combo) {this->combo = combo;}

vector<Card> Combo::sortCombo() {
    for (int i = 0; i < this->combo.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < this->combo.size(); j++) {
            if (this->combo[j].getNumber() > this->combo[maxIndex].getNumber() || (this->combo[j].getNumber() == this->combo[maxIndex].getNumber() && this->combo[j].getColor() > this->combo[maxIndex].getColor())) {
                maxIndex = j;
            }
        }
        Card temp = this->combo[i];
        this->combo[i] = this->combo[maxIndex];
        this->combo[maxIndex] = temp;
    }
}

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
            int i = 0;

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