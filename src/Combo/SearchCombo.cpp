#include <iostream>
#include "../Card/Card.hpp"
#include "SearchCombo.hpp"
using namespace std;

SearchCombo::SearchCombo() {}

SearchCombo::SearchCombo(Player player, Table table) {
    this->cards.push_back(player.getItems(0));
    this->cards.push_back(player.getItems(1));

    for (int i = 0; i < 5; i++) {
        this->cards.push_back(table.getItems(i));
    }

    this->sortCards();
}

SearchCombo::~SearchCombo() {}

Combo SearchCombo::getCombo() const {
    return this->combo;
}

void SearchCombo::setCombo(Combo combo) {
    this->combo = combo;
}

vector<Card> SearchCombo::getCards() const {
    return this->cards;
}

void SearchCombo::setCards(vector<Card> cards) {
    this->cards = cards;
}

vector<Combo> SearchCombo::getRecords() const {
    return this->records;
}

void SearchCombo::setRecords(vector<Combo> records) {
    this->records = records;
}

vector<Card> SearchCombo::getComboCards() const {
    return this->combo.getCombo();
}


vector<Card> SearchCombo::sortCards() {
    for (int i = 0; i < this->cards.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[j].getNumber() > this->cards[maxIndex].getNumber() || (this->cards[j].getNumber() == this->cards[maxIndex].getNumber() && this->cards[j].getColor() > this->cards[maxIndex].getColor())) {
                maxIndex = j;
            }
        }
        Card temp = this->cards[i];
        this->cards[i] = this->cards[maxIndex];
        this->cards[maxIndex] = temp;
    }
}

vector<Card> SearchCombo::sortCombo() {
    for (int i = 0; i < this->cards.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < this->getComboCards().size(); j++) {
            if (this->getComboCards()[j].getNumber() > this->getComboCards()[maxIndex].getNumber() || (this->getComboCards()[j].getNumber() == this->getComboCards()[maxIndex].getNumber() && this->getComboCards()[j].getColor() > this->getComboCards()[maxIndex].getColor())) {
                maxIndex = j;
            }
        }
        Card temp = this->getComboCards()[i];
        this->getComboCards()[i] = this->getComboCards()[maxIndex];
        this->getComboCards()[maxIndex] = temp;
    }
}

void SearchCombo::highCard() {
    int max = 0;

    this->getComboCards().push_back(this->cards[this->cards.size() - 1]);
    max += this->cards[this->cards.size() - 1].value();

    this->records.push_back(this->combo);
}

void SearchCombo::pair() {
    int max = 0;
    int i = 0;

    vector<Card> temp;

    while (i < this->cards.size() - 1) {
        if (this->cards[i].getNumber() == this->cards[i+1].getNumber()) {
            max = this->cards[i+1].value() + 1.39;
            
            temp.insert(temp.end(), this->cards[i]);
            temp.insert(temp.end(), this->cards[i+1]);

            this->combo.setScore(max);
            this->getComboCards() = temp;
        }
        i++;
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::twoPair() {
    int max = 0;
    int countPair = 0;

    vector<Card> pairs, temp;

    int count[14] = {0};
    for (int i = 0; i < this->cards.size(); i++) {
        count[this->cards[i].getNumber()]++;
    }

    for (int i = 0; i <= 14; i++) {
        if (count[i] == 2) {
            pairs.push_back(this->cards[i]);
            pairs.push_back(this->cards[i+1]);
            countPair++;
        }
    }
    if (countPair >= 2) {
        temp.push_back(pairs[pairs.size()-4]);
        temp.push_back(pairs[pairs.size()-3]);
        temp.push_back(pairs[pairs.size()-2]);
        temp.push_back(pairs[pairs.size()-1]);

        this->getComboCards() = temp;

        max += this->getComboCards()[this->getComboCards().size()-1].value() +  this->getComboCards()[this->getComboCards().size()-3].value() + 4.14;
        this->combo.setScore(max);
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::threeOfAKind() {
    int max = 0;
    int i = 0, countThree = 0;

    vector<Card> temp, three;

    while (i < this->cards.size()) {
        if ( (this->cards[i].getNumber() == this->cards[i+1].getNumber()) &&  (this->cards[i].getNumber() == this->cards[i-1].getNumber()) && i > 1 && i < 6) {

           three.insert(three.end(), this->cards[i]);
           three.insert(three.end(), this->cards[i+1]);
           three.insert(three.end(), this->cards[i-1]);

            countThree++;
        }
        i++;
    }

    if (countThree >= 1) {
        temp.push_back(three[three.size()-3]);
        temp.push_back(three[three.size()-2]);
        temp.push_back(three[three.size()-1]);

        this->getComboCards() = temp;
        max += this->getComboCards()[this->getComboCards().size()-1].value() + this->getComboCards()[this->getComboCards().size()-2].value() + this->getComboCards()[this->getComboCards().size()-3].value() + 8.22;

        this->combo.setScore(max);
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }
}

void SearchCombo::straight() {
    int max = 0;
    int i = 0;
    int countStraight = 0;

    vector<Card> temp, straight;

    while (i < this->cards.size()) {
        if ( i + 4 < 7 ) {
            if (this->cards[i].getNumber() + 1 == this->cards[i+1].getNumber() && 
                this->cards[i].getNumber() + 2 == this->cards[i+2].getNumber() &&
                this->cards[i].getNumber() + 3 == this->cards[i+3].getNumber() &&
                this->cards[i].getNumber() + 4 == this->cards[i+4].getNumber()) {

                straight.insert(straight.end(), this->cards[i]);
                straight.insert(straight.end(), this->cards[i+1]);
                straight.insert(straight.end(), this->cards[i+2]);
                straight.insert(straight.end(), this->cards[i+3]);
                straight.insert(straight.end(), this->cards[i+4]);

                countStraight++;
            }
        }
        i++;
    }

    if (countStraight >= 1) {
        temp.push_back(straight[straight.size()-5]);
        temp.push_back(straight[straight.size()-4]);
        temp.push_back(straight[straight.size()-3]);
        temp.push_back(straight[straight.size()-2]);
        temp.push_back(straight[straight.size()-1]);

        this->getComboCards() = temp;

        // for (auto x : this->combo) {
        //     max += x.value();
        // }

        max += this->getComboCards()[this->getComboCards().size()-1].value();

        max += 12.3;

        this->combo.setScore(max);
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::flush() {
    int max = 0, count = 0;
    int j = 0, i = 0;
    vector<Card> temp, flushCards;
    vector<bool> flush;

    for (auto x : flush) {
        x = false;
    }

    while (i < this->cards.size()) {
        while (j < this->cards.size() && j > i) {
            if (this->cards[i].getColor() == this->cards[j].getColor()) {
                flush[i] = true;
                flush[j] = true;
                count += 1;
            }
        }
        j++;
    }
    i++;
    
    if (count >= 5) {
        for (i = 0; i < this->cards.size(); i++) {
            if (flush[i] == true) {
                flushCards.push_back(this->cards[i]);
            }
        }

        temp.push_back(flushCards[flushCards.size()-5]);
        temp.push_back(flushCards[flushCards.size()-4]);
        temp.push_back(flushCards[flushCards.size()-3]);
        temp.push_back(flushCards[flushCards.size()-2]);
        temp.push_back(flushCards[flushCards.size()-1]);

        this->getComboCards() = temp;

        // for (auto x : this->getComboCards()) {
        //     max += x.value();
        // }

        max += this->getComboCards()[this->getComboCards().size()-1].value();

        max += 18.15;

        this->combo.setScore(max);
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::fullHouse() {
    int max = 0, countThree = 0, countPair = 0;

    vector<Card> copyCards = this->cards;
    vector<Card> temp, three, pair;

    for (int i = 0; i < copyCards.size() - 2; i++) { // Detecting three of a kind
        if (this->cards[i] == this->cards[i+1] && this->cards[i] == this->cards[i+2]) {
            three.insert(three.end(), this->cards[i]);
            three.insert(three.end(), this->cards[i+1]);
            three.insert(three.end(), this->cards[i+2]);
            countThree++;

            copyCards.erase(copyCards.begin() + i, copyCards.begin() + i + 3);

            for (int j = 0; j < copyCards.size(); j++) { // Then detecting pair
                if (cards[j] == cards[j+1]) {
                    pair.insert(pair.end(), this->cards[j]);
                    pair.insert(pair.end(), this->cards[j+1]);
                    countPair++;
                }
            }
        }
    }

    if (countPair >= 1 && countThree >= 1) {
        temp.push_back(three[three.size()-3]);
        temp.push_back(three[three.size()-2]);
        temp.push_back(three[three.size()-1]);
        temp.push_back(pair[pair.size()-2]);
        temp.push_back(pair[pair.size()-1]);

        this->getComboCards() = temp;

        // for (auto x : this->getComboCards()) {
        //     max += x.value();
        // }

        max += this->getComboCards()[this->getComboCards().size()-1].value();

        max += 24.04;

        this->combo.setScore(max);
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::fourOfKind() {
    int max = 0, countFour = 0;
    int i = 0;

    vector<Card> temp, four;

    while (i < this->cards.size()) {
        if ( (this->cards[i].getNumber() == this->cards[i+1].getNumber()) &&  (this->cards[i].getNumber() == this->cards[i-1].getNumber()) && i + 3 < 7) {
            max = this->cards[i].value() + this->cards[i+1].value() + this->cards[i+2].value() + + this->cards[i+3].value();

            four.insert(four.end(), this->cards[i]);
            four.insert(four.end(), this->cards[i+1]);
            four.insert(four.end(), this->cards[i+2]);
            four.insert(four.end(), this->cards[i+3]);

            countFour++;
        }
        i++;
    }

    if (countFour >= 1) {
        temp.push_back(four[four.size()-4]);
        temp.push_back(four[four.size()-3]);
        temp.push_back(four[four.size()-2]);
        temp.push_back(four[four.size()-1]);

        this->getComboCards() = temp;

        // for (auto x : this->combo) {
        //     max += x.value();
        // }

        max += this->getComboCards()[this->getComboCards().size()-1].value();

        max += 30.67;

        this->combo.setScore(max);
    } 

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::straightFlush() {
    int max = 0;
    int i = 0;

    vector<Card> temp, straight;

    while (i < this->cards.size()) {
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
                }
            }
        }
        i++;
    }

    if (temp.size() >= 5) {
        straight.push_back(temp[temp.size()-5]);
        straight.push_back(temp[temp.size()-4]);
        straight.push_back(temp[temp.size()-3]);
        straight.push_back(temp[temp.size()-2]);
        straight.push_back(temp[temp.size()-1]);

        this->getComboCards() = straight;

        // for (auto x : this->combo) {
        //     max += x.value();
        // }

        max += this->getComboCards()[this->getComboCards().size()-1].value();

        max += 36.05;

        this->combo.setScore(max);
    }

    if (temp.size() > 1) {
        records.push_back(this->combo);
    }

    this->sortCombo();
}

void SearchCombo::checkCombo() {
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

Combo SearchCombo::getHighestCombo() {
    return getHighest(this->getRecords());
}