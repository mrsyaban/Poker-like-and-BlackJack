#include <iostream>
#include "../Card/Card.hpp"
#include "SearchCombo.hpp"
using namespace std;

SearchCombo::SearchCombo() {}

SearchCombo::SearchCombo(Player player, Table table)
{
    this->cards.push_back(player.getCard(0));
    this->cards.push_back(player.getCard(1));

    for (int i = 0; i < 5; i++)
    {
        this->cards.push_back(table.getCard(i));
    }
    this->sortCards();
    this->checkCombo();
}

SearchCombo::~SearchCombo() {}

vector<Card> SearchCombo::getCards() const
{
    return this->cards;
}

void SearchCombo::setCards(vector<Card> cards)
{
    this->cards = cards;
}

vector<Combo> SearchCombo::getRecords() const
{
    return this->records;
}

void SearchCombo::setRecords(vector<Combo> records)
{
    this->records = records;
}

// vector<Card> SearchCombo::getComboCards() {
//     return this->combo.getCombo();
// }

void SearchCombo::sortCards()
{
    // for (unsigned int i = 0; i < this->cards.size() - 1; i++)
    // {
    //     int maxIndex = i;
    //     for (unsigned int j = i + 1; j < this->cards.size(); j++)
    //     {
    //         if (this->cards[j].getNumber() > this->cards[maxIndex].getNumber() || (this->cards[j].getNumber() == this->cards[maxIndex].getNumber() && this->cards[j].getColor() > this->cards[maxIndex].getColor()))
    //         {
    //             maxIndex = j;
    //         }
    //     }

    //     Card temp = this->cards[i];
    //     this->cards[i] = this->cards[maxIndex];
    //     this->cards[maxIndex] = temp;
    // }

    for (unsigned i = 0; i < this->cards.size(); i++) {
        int min_idx = i;
        for (unsigned j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[j].value() < this->cards[min_idx].value()) {
                min_idx = j;
            }
        }
        // swap(this->cards[i], this->cards[min_idx]);
        Card temp = this->cards[i];
        this->cards[i] = this->cards[min_idx];
        this->cards[min_idx] = temp;
    }
}

void SearchCombo::sortCards2() {
    int n = cards.size();

    // Sort the cards by type using selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (cards[j].getColor() < cards[minIndex].getColor()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(cards[i], cards[minIndex]);
        }
    }

    // Sort the cards by number within each getColor() using selection sort
    int startIndex = 0;
    for (int i = 1; i < n; i++) {
        if (cards[i].getColor() != cards[startIndex].getColor()) {
            // Sort the cards with the same getColor() using selection sort
            for (int j = startIndex; j < i - 1; j++) {
                int minIndex = j;
                for (int k = j + 1; k < i; k++) {
                    if (cards[k].getNumber() < cards[minIndex].getNumber()) {
                        minIndex = k;
                    }
                }
                if (minIndex != j) {
                    swap(cards[j], cards[minIndex]);
                }
            }
            startIndex = i;
        }
    }

    // Sort the cards with the same getColor() as the last group
    for (int j = startIndex; j < n - 1; j++) {
        int minIndex = j;
        for (int k = j + 1; k < n; k++) {
            if (cards[k].getNumber() < cards[minIndex].getNumber()) {
                minIndex = k;
            }
        }
        if (minIndex != j) {
            swap(cards[j], cards[minIndex]);
        }
    }
}

void SearchCombo::highCard()
{
    double max = 0;

    vector<Card> crd = {this->cards[this->cards.size() - 1]};
    Combo c;
    c.setCombo(crd);
    max += this->cards[this->cards.size() - 1].value();
    c.setScore(max);
    this->records.push_back(c);
}

void SearchCombo::pair()
{
    this->sortCards();
    double max = 0;
    unsigned int i = 0;

    vector<Card> temp;
    Combo c;
    while (i < this->cards.size() - 1)
    {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber())
        {
            max = this->cards[i + 1].value() + 1.39;

            temp.insert(temp.end(), this->cards[i]);
            temp.insert(temp.end(), this->cards[i + 1]);
        }
        i++;
    }

    if (temp.size() > 1)
    {
        c.setScore(max);
        c.setCombo(temp);
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::twoPair()
{
    this->sortCards();
    double max = 0;
    int countPair = 0;

    vector<Card> pairs, temp;
    Combo c;

    int count[13] = {0};
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        count[this->cards[i].getNumber()]++;
    }

    for (int i = 0; i <= 12; i++)
    {
        if (count[i] == 2)
        {
            pairs.push_back(this->cards[i]);
            pairs.push_back(this->cards[i + 1]);
            countPair++;
        }
    }
    if (countPair >= 2)
    {
        temp.push_back(pairs[pairs.size() - 4]);
        temp.push_back(pairs[pairs.size() - 3]);
        temp.push_back(pairs[pairs.size() - 2]);
        temp.push_back(pairs[pairs.size() - 1]);

        max += c.getCombo()[c.getCombo().size() - 1].value() + c.getCombo()[c.getCombo().size() - 3].value() + 4.14;
    }

    if (temp.size() > 1)
    {
        c.setCombo(temp);
        c.setScore(max);
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::threeOfAKind()
{
    this->sortCards();
    double max = 0;
    unsigned int i = 1, countThree = 0;

    vector<Card> temp, three;
    Combo c;

    while (i < this->cards.size() - 1)
    {
        if ((this->cards[i].getNumber() == this->cards[i + 1].getNumber()) && (this->cards[i].getNumber() == this->cards[i - 1].getNumber()) && i > 1 && i < 6)
        {

            three.insert(three.end(), this->cards[i]);
            three.insert(three.end(), this->cards[i + 1]);
            three.insert(three.end(), this->cards[i - 1]);

            countThree++;
        }
        i++;
    }

    if (countThree >= 1)
    {
        c.setCombo(three);
        max += c.getCombo()[c.getCombo().size() - 1].value() + 8.22;

        c.setScore(max);
        this->records.push_back(c);
    }
}

void SearchCombo::straight()
{
    double max = 0;

    vector<Card> straight;
    Combo c;

    int count[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        count[this->cards[i].getNumber()-1]++;
    }

    for (int i = 12; i >= 4; i--) {
        if (count[i] >= 1 && count[i-1] >= 1 && count[i-2] >= 1 && count[i-3] >= 1 && count[i-4] >= 1) {
            straight.push_back(this->cards[i]);
            straight.push_back(this->cards[i-1]);
            straight.push_back(this->cards[i-2]);
            straight.push_back(this->cards[i-3]);
            straight.push_back(this->cards[i-4]);
            break;
        }
    }

    if (straight.size() > 1)
    {
        c.setCombo(straight);

        max += c.getCombo()[4].value();

        max += 12.3;
        c.setScore(max);
        this->records.push_back(c);
    }   
}

void SearchCombo::flush()
{
    this->sortCards();
    double max = 0;
    int count = 0;
    unsigned int j = 0, i = 0;
    vector<Card> temp, flushCards;
    vector<bool> flush;

    Combo c;

    for (auto x : flush)
    {
        x = false;
    }

    while (i < this->cards.size())
    {
        while (j < this->cards.size() && j > i)
        {
            if (this->cards[i].getColor() == this->cards[j].getColor())
            {
                flush[i] = true;
                flush[j] = true;
                count += 1;
            }
            j++;
        }
        i++;
    }

    if (count >= 5)
    {
        for (i = 0; i < this->cards.size(); i++)
        {
            if (flush[i] == true)
            {
                flushCards.push_back(this->cards[i]);
            }
        }

        temp.push_back(flushCards[flushCards.size() - 5]);
        temp.push_back(flushCards[flushCards.size() - 4]);
        temp.push_back(flushCards[flushCards.size() - 3]);
        temp.push_back(flushCards[flushCards.size() - 2]);
        temp.push_back(flushCards[flushCards.size() - 1]);

        

        // for (auto x : this->getComboCards()) {
        //     max += x.value();
        // }

        max += c.getCombo()[c.getCombo().size() - 1].value();

        max += 18.15;

        
    }

    if (temp.size() > 1)
    {
        c.setCombo(temp);
        c.setScore(max);
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::fullHouse()
{
    this->sortCards();
    double max = 0;
    int countThree = 0, countPair = 0;

    vector<Card> copyCards = this->cards;
    vector<Card> temp, three, pair;
    Combo c;

    for (unsigned int i = 0; i < copyCards.size() - 2; i++)
    { // Detecting three of a kind
        if (this->cards[i] == this->cards[i + 1] && this->cards[i] == this->cards[i + 2])
        {
            three.insert(three.end(), this->cards[i]);
            three.insert(three.end(), this->cards[i + 1]);
            three.insert(three.end(), this->cards[i + 2]);
            countThree++;

            copyCards.erase(copyCards.begin() + i, copyCards.begin() + i + 3);

            for (unsigned int j = 0; j < copyCards.size(); j++)
            { // Then detecting pair
                if (cards[j] == cards[j + 1])
                {
                    pair.insert(pair.end(), this->cards[j]);
                    pair.insert(pair.end(), this->cards[j + 1]);
                    countPair++;
                }
            }
        }
    }

    if (countPair >= 1 && countThree >= 1)
    {
        temp.push_back(three[three.size() - 3]);
        temp.push_back(three[three.size() - 2]);
        temp.push_back(three[three.size() - 1]);
        temp.push_back(pair[pair.size() - 2]);
        temp.push_back(pair[pair.size() - 1]);

        c.setCombo(temp);

        // for (auto x : this->getComboCards()) {
        //     max += x.value();
        // }

        max += c.getCombo()[c.getCombo().size() - 1].value();

        max += 24.04;

        c.setScore(max);
    }

    if (temp.size() > 1)
    {
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::fourOfKind()
{
    this->sortCards();
    double max = 0;
    int countFour = 0;
    unsigned int i = 0;

    vector<Card> temp, four;
    Combo c;

    while (i < this->cards.size() - 3)
    {
        if ((this->cards[i].getNumber() == this->cards[i + 1].getNumber()) && (this->cards[i + 1].getNumber() == this->cards[i + 2].getNumber()) && (this->cards[i + 2].getNumber() == this->cards[i + 3].getNumber()) && i + 3 < 7)
        {
            four.insert(four.end(), this->cards[i]);
            four.insert(four.end(), this->cards[i + 1]);
            four.insert(four.end(), this->cards[i + 2]);
            four.insert(four.end(), this->cards[i + 3]);

            countFour++;
        }
        i++;
    }

    if (countFour >= 1)
    {
        temp.push_back(four[four.size() - 4]);
        temp.push_back(four[four.size() - 3]);
        temp.push_back(four[four.size() - 2]);
        temp.push_back(four[four.size() - 1]);

        c.setCombo(temp);

        // for (auto x : this->combo) {
        //     max += x.value();
        // }

        max += c.getCombo()[c.getCombo().size() - 1].value();

        max += 30.67;

        c.setScore(max);
    }

    if (temp.size() > 1)
    {
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::straightFlush()
{
    this->sortCards2();
    double max = 0;
    unsigned int i = 0;
    Combo c;
    vector<Card> straight;

    while (i < this->cards.size())
    {
        if (i + 4 < 7)
        {
            if (this->cards[i].getNumber() + 1 == this->cards[i + 1].getNumber() &&
                this->cards[i].getNumber() + 2 == this->cards[i + 2].getNumber() &&
                this->cards[i].getNumber() + 3 == this->cards[i + 3].getNumber() &&
                this->cards[i].getNumber() + 4 == this->cards[i + 4].getNumber())
            {

                if (this->cards[i].getColor() == this->cards[i + 1].getColor() &&
                    this->cards[i].getColor() == this->cards[i + 2].getColor() &&
                    this->cards[i].getColor() == this->cards[i + 3].getColor() &&
                    this->cards[i].getColor() == this->cards[i + 4].getColor())
                {

                    straight.insert(straight.end(), this->cards[i]);
                    straight.insert(straight.end(), this->cards[i + 1]);
                    straight.insert(straight.end(), this->cards[i + 2]);
                    straight.insert(straight.end(), this->cards[i + 3]);
                    straight.insert(straight.end(), this->cards[i + 4]);
                }
            }
        }
        i++;
    }

    if (straight.size() >= 5)
    {
        c.setCombo(straight);

        // for (auto x : this->combo) {
        //     max += x.value();
        // }

        max += straight[4].value();

        max += 36.05;

        c.setScore(max);
    }

    if (straight.size() > 1)
    {
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::checkCombo()
{
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

Combo SearchCombo::getHighestCombo()
{
    return getHighest(this->getRecords());
}