#include <iostream>
#include <vector>
#include "Combo.hpp"
#include "SearchCombo.hpp"
#include "../Card/Card.hpp"
using namespace std;

// int main() {
//     vector<int> nums = {6,4,9,3,1,8,9,4,6,0};
// vector<int> combo = {3,4,5};

//     combo = nums;

//     for (auto x : combo) {
//         cout << x << " ";
//     }
// }

int main() {
    Card card1(Green,13);
    Card card2(Blue,12);
    Card card3(Yellow,13);
    Card card4(Red,12);
    Card card5(Yellow,11);
    Card card6(Red,10);
    Card card7(Yellow,9);

    vector<Card> cards;
    cards.push_back(card1);
    cards.push_back(card2);
    cards.push_back(card3);
    cards.push_back(card4);
    cards.push_back(card5);
    cards.push_back(card6);
    cards.push_back(card7);

    SearchCombo sCombo;
    sCombo.setCards(cards);
    sCombo.sortCards();

    Combo combs;

    for (auto x : sCombo.getCards()) {
        if (x.getColor() == 0) {
            cout << x.getNumber() << " Green"  << endl;
        } else if (x.getColor() == 1) {
            cout << x.getNumber() << " Blue"  << endl;
        } else if (x.getColor() == 2) {
            cout << x.getNumber() << " Yellow"  << endl;
        } else {
            cout << x.getNumber() << " Red"  << endl;
        } 
    }

    sCombo.checkCombo();
    combs = sCombo.getRecords()[sCombo.getRecords().size()-1];


    cout << "\n\nCombo :\n";

    for (auto x : combs.getCombo()) {
        if (x.getColor() == 0) {
            cout << x.getNumber() << " Green"  << endl;
        } else if (x.getColor() == 1) {
            cout << x.getNumber() << " Blue"  << endl;
        } else if (x.getColor() == 2) {
            cout << x.getNumber() << " Yellow"  << endl;
        } else {
            cout << x.getNumber() << " Red"  << endl;
        }
    }

    return 0;
}
