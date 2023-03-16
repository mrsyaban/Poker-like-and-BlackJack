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
    Card card1(Green,8);
    Card card2(Blue,2);
    Card card3(Green,2);
    Card card4(Red,9);
    Card card5(Blue,6);
    Card card6(Yellow,4);
    Card card7(Red,11);

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
    sCombo.sortCards2();
    sCombo.checkCombo();

    Combo combs;
    combs = sCombo.getHighestCombo();

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
