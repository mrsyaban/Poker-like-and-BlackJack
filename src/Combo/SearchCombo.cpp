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

    vector<Card> temp, pair;
    Combo c;
    while (i < this->cards.size() - 1)
    {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber())
        {
            max = this->cards[i + 1].value() + 1.39;

            temp.push_back(this->cards[i]);
            temp.push_back(this->cards[i + 1]);
        }
        i++;
    }

    if (temp.size() >= 2)
    {
        pair.push_back(temp[temp.size()-1]);
        pair.push_back(temp[temp.size()-2]);
        c.setScore(max);
        c.setCombo(pair);
        records.push_back(c);
    }

    // this->sortCombo();
}

void SearchCombo::twoPair()
{
    this->sortCards();
    double max = 0;
    unsigned int i = 0;

    vector<Card> temp, pair;
    Combo c;
    while (i < this->cards.size() - 1)
    {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber())
        {
            max = this->cards[i + 1].value() + 1.39;

            temp.push_back(this->cards[i]);
            temp.push_back(this->cards[i + 1]);
        }
        i++;
    }

    if (temp.size() >= 4)
    {
        pair.push_back(temp[temp.size()-1]);
        pair.push_back(temp[temp.size()-2]);
        pair.push_back(temp[temp.size()-3]);
        pair.push_back(temp[temp.size()-4]);
        c.setScore(max);
        c.setCombo(pair);
        records.push_back(c);
    }
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
        max = c.getCombo()[c.getCombo().size() - 1].value() + 8.22;
        c.setScore(max);
        this->records.push_back(c);
    }
}

void SearchCombo::straight()
{
    this->sortCards();
    double max = 0;

    vector<Card> straight, temp;
    Combo c;

    int count[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        count[this->cards[i].getNumber()-1]++;
    }

    for (int i = 12; i >= 4; i--) {
        if (count[i] >= 1 && count[i-1] >= 1 && count[i-2] >= 1 && count[i-3] >= 1 && count[i-4] >= 1) {
            int maksindeks = this->cards.size()-1;
            int found = 0;
            while (found != 5) {
                if (this->cards[maksindeks].getNumber() == i-found+1) {
                    straight.push_back(this->cards[maksindeks]);
                    found++;
                }
                maksindeks--;
            }
            break;
        }
    }

    if (straight.size() > 1)
    {
        c.setCombo(straight);
        max = c.getCombo()[4].value();
        max += 12.3;
        c.setScore(max);
        this->records.push_back(c);
    }
}

void SearchCombo::flush()
{
    this->sortCards2();
    double max = 0;

    vector<Card> flush, temp;
    Combo c;

    int count[4] = {0, 0, 0, 0};
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        count[this->cards[i].getColor()]++;
    }

    for (int i = 3; i >= 0; i--) {
        if (count[i] >= 5) {
            int found = 0;
            int maksindeks = this->cards.size()-1;
            while (found != 5) {
                if (this->cards[maksindeks].getColor() == i) {
                    flush.push_back(this->cards[maksindeks]);
                    found++;
                }
                maksindeks--;
            }
            break;
        }
    }

    if (flush.size() > 1)
    {
        c.setCombo(flush);

        max = c.getCombo()[0].value();
        max += 12.3;
        c.setScore(max);
        this->records.push_back(c);
    }
}

void SearchCombo::fullHouse()
{
    this->sortCards();
    double max = 0;
    bool thereIs3OfAKind, thereIsAPair;

    vector<Card> copyCards = this->cards;
    vector<Card> temp, three, pair;
    Combo c;

    int count[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        count[this->cards[i].getNumber()-1]++;
    }

    for (int i = 12; i >= 0; i--) {
        if (count[i] >= 3) {
            thereIs3OfAKind = true;
        } else if (count[i] >= 2) {
            thereIsAPair = true;
        }

        if (thereIs3OfAKind && thereIsAPair) {
            break;
        }
    }

    if (thereIs3OfAKind && thereIsAPair) {
        while (thereIs3OfAKind) {
            for (int i = 12; i >= 0; i--) {
                int found = 0;
                int maksindeks = this->cards.size()-1;
                if (count[i] >= 3) {
                    while (found != 3) {
                        if (this->cards[maksindeks].getNumber() == i+1) {
                            cout << this->cards[maksindeks].getNumber();
                            three.push_back(this->cards[maksindeks]);
                            found++;
                        }
                        maksindeks--;
                    }
                    thereIs3OfAKind = false;
                    count[i] = 0;
                    break;
                }
            }
        }

        while (thereIsAPair) {
            for (int i = 12; i >= 0; i--) {
                int found = 0;
                int maksindeks = this->cards.size()-1;
                if (count[i] >= 2) {
                    while (found != 2) {
                        if (this->cards[maksindeks].getNumber() == i+1) {
                            pair.push_back(this->cards[maksindeks]);
                            found++;
                        }
                        maksindeks--;
                    }
                    thereIsAPair = false;
                    count[i] = 0;
                    break;
                }
            }
        }
    }

    if (pair.size() >= 1 && three.size() >= 1)
    {
        temp.push_back(three[0]);
        temp.push_back(three[1]);
        temp.push_back(three[2]);
        temp.push_back(pair[0]);
        temp.push_back(pair[1]);

        c.setCombo(temp);

        // for (auto x : this->getComboCards()) {
        //     max += x.value();
        // }

        max = c.getCombo()[0].value();

        max += 24.04;

        c.setScore(max);
    }

    if (temp.size() > 1)
    {
        records.push_back(c);
    }
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

        max = c.getCombo()[c.getCombo().size() - 2].value() + c.getCombo()[c.getCombo().size() - 5].value();

        max += 30.67;

        c.setScore(max);
    }

    if (temp.size() > 1)
    {
        records.push_back(c);
    }

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

        max = straight[4].value();

        max += 36.05;

        c.setScore(max);
    }

    if (straight.size() > 1)
    {
        records.push_back(c);
    }

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