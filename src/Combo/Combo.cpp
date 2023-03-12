#include <iostream>
#include "./Card/Card.hpp"
#include "Combo.hpp"
using namespace std;

Combo::Combo() {
    this->sortCards();
    this->score = 0;
}

Combo::~Combo() {}

void Combo::setScore(float number) {
    this->score = number;
}

float Combo::getScore() {
    return this->score;
}

vector<Card> Combo::getCombo() {return this->combo;}

int Combo::length() {
    return cards.size();
}

vector<Card> Combo::sortCards() {
    for (int i = 1; i < this->cards.size(); i++) {
        int key = this->cards[i].getNumber();
        int j = i - 1;
        while (j >= 0 && this->cards[j].getNumber() > key) {
            this->cards[j+1] = this->cards[j];
            j--;
        }
        this->cards[j+1].setNumber(key);
    }
}

void Combo::highCard() {
    int max = 0;

    vector<Card> temp;

    for (int i = 0; i < length(); i++) {
        if (this->cards[i].value() > max) {
            max = this->cards[i].value();
            temp.insert(temp.begin(), this->cards[i]);
            this->setScore(max);
            this->combo = temp;
        }
    }
}

void Combo::pair() {
    int max = 0;
    int i = 0;

    vector<Card> temp;

    while (i < this->length() - 1) {
        if (this->cards[i].getNumber() == this->cards[i+1].getNumber()) {
            max = this->cards[i].value() + this->cards[i+1].value() + 1.39;
            
            temp.insert(temp.end(), this->cards[i]);
            temp.insert(temp.end(), this->cards[i+1]);

            this->setScore(max);
            this->combo = temp;
        }
        i++;
    }
}

void Combo::twoPair() {
    int max = 0;

    vector<Card> pairs;

    int count[14] = {0};
    for (int i = 0; i < this->cards.size(); i++) {
        count[this->cards[i].getNumber()]++;
    }

    for (int i = 0; i <= 14; i++) {
        if (count[i] == 2) {
            pairs.push_back(this->cards[i]);
            pairs.push_back(this->cards[i+1]);

            max += pairs[i].value() + pairs[i+1].value();

            this->setScore(max);
            this->combo = pairs;
        }
    }
}

void Combo::threeOfAKind() {
    int max = 0;
    int i = 0;

    vector<Card> temp;

    while (i < this->length()) {
        if ( (this->cards[i].getNumber() == this->cards[i+1].getNumber()) &&  (this->cards[i].getNumber() == this->cards[i-1].getNumber()) && i > 1 && i < 6) {
            max = this->cards[i].value() + this->cards[i+1].value() + this->cards[i-1].value();

            temp.insert(temp.end(), this->cards[i]);
            temp.insert(temp.end(), this->cards[i+1]);
            temp.insert(temp.end(), this->cards[i-1]);

            this->setScore(max);
            this->combo = temp;
        }
        i++;
    }
}

void Combo::straight() {
    int max = 0;
    int i = 0;

    vector<Card> temp;

    while (i < this->length()) {
        if ( i + 4 < 7 ) {
            if (this->cards[i].getNumber() + 1 == this->cards[i+1].getNumber() && 
                this->cards[i].getNumber() + 2 == this->cards[i+2].getNumber() &&
                this->cards[i].getNumber() + 3 == this->cards[i+3].getNumber() &&
                this->cards[i].getNumber() + 4 == this->cards[i+4].getNumber()) {

                max = this->cards[i].value() + this->cards[i+1].value() + this->cards[i+2].value() + this->cards[i+3].value() + this->cards[i+4].value();

                temp.insert(temp.end(), this->cards[i]);
                temp.insert(temp.end(), this->cards[i+1]);
                temp.insert(temp.end(), this->cards[i+2]);
                temp.insert(temp.end(), this->cards[i+3]);
                temp.insert(temp.end(), this->cards[i+4]);

                this->setScore(max);
                this->combo = temp;
            }
        }
        i++;
    }
}

void Combo::flush() {
    int max = 0, count = 0;
    int j = 0, i = 0;
    vector<Card> temp;

    while (i < this->length()) {
        while (j < this->length() && j > i) {
            if (this->cards[i].getColor() == this->cards[j].getColor()) {
                temp.insert(temp.begin(), this->cards[i]);
                count += 1;

                if (count <= 5) {
                    temp.insert(temp.end(), this->cards[j]);
                }
            }

            if (count == 5) {
                for (auto x : temp) {
                    max += x.value();
                }
                this->combo = temp;
                this->setScore(max);
            }
            j++;
        }
        i++;
    }
}

void Combo::fullHouse() {
    int max = 0;

    vector<Card> copyCards = this->cards;
    vector<Card> temp;

    for (int i = 0; i < copyCards.size() - 2; i++) {
        if (this->cards[i] == this->cards[i+1] && this->cards[i] == this->cards[i+2]) {
            temp.insert(temp.end(), this->cards[i]);
            temp.insert(temp.end(), this->cards[i+1]);
            temp.insert(temp.end(), this->cards[i+2]);

            max += this->cards[i].value() + this->cards[i+1].value() + this->cards[i+2].value();

            copyCards.erase(copyCards.begin() + i, copyCards.begin() + i + 3);

            for (int j = 0; j < copyCards.size(); j++) {
                if (cards[j] == cards[j+1]) {
                    temp.insert(temp.end(), this->cards[j]);
                    temp.insert(temp.end(), this->cards[j+1]);

                    max += this->cards[j].value() + this->cards[j+1].value();
                    this->combo = temp;
                }
            }
        }
    }
}

void Combo::fourOfKind() {
    int max = 0;
    int i = 0;

    vector<Card> temp;

    while (i < this->length()) {
        if ( (this->cards[i].getNumber() == this->cards[i+1].getNumber()) &&  (this->cards[i].getNumber() == this->cards[i-1].getNumber()) && i + 3 < 7) {
            max = this->cards[i].value() + this->cards[i+1].value() + this->cards[i+2].value() + + this->cards[i+3].value();

            temp.insert(temp.end(), this->cards[i]);
            temp.insert(temp.end(), this->cards[i+1]);
            temp.insert(temp.end(), this->cards[i+2]);
            temp.insert(temp.end(), this->cards[i+3]);

            this->setScore(max);
            this->combo = temp;
        }
        i++;
    }

}

void Combo::straightFlush() {
    int max = 0;
    int i = 0;

    vector<Card> temp;

    while (i < this->length()) {
        if ( i + 4 < 7 ) {
            if (this->cards[i].getNumber() + 1 == this->cards[i+1].getNumber() && 
                this->cards[i].getNumber() + 2 == this->cards[i+2].getNumber() &&
                this->cards[i].getNumber() + 3 == this->cards[i+3].getNumber() &&
                this->cards[i].getNumber() + 4 == this->cards[i+4].getNumber()) {

                if (this->cards[i].getColor() == this->cards[i+1].getColor() &&
                    this->cards[i].getColor() == this->cards[i+2].getColor() &&
                    this->cards[i].getColor() == this->cards[i+3].getColor() &&
                    this->cards[i].getColor() == this->cards[i+4].getColor() ) {

                    max = this->cards[i].value() + this->cards[i+1].value() + this->cards[i+2].value() + this->cards[i+3].value() + this->cards[i+4].value();

                    temp.insert(temp.end(), this->cards[i]);
                    temp.insert(temp.end(), this->cards[i+1]);
                    temp.insert(temp.end(), this->cards[i+2]);
                    temp.insert(temp.end(), this->cards[i+3]);
                    temp.insert(temp.end(), this->cards[i+4]);

                    this->setScore(max);
                    this->combo = temp;
                }
            }
        }
        i++;
    }

}

void Combo::checkCombo() {
    this->highCard();
    this->pair();
    this->twoPair();
    this->threeOfAKind();
    this->straight();
    this->flush();
    this->fullHouse();
    this->fourOfKind();
    this->straightFlush();
}