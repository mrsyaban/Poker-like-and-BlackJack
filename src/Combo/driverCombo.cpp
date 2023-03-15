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
    Card card1(Green,3);
    Card card2(Green,3);
    Card card3(Green,3);
    Card card4(Green,3);
    Card card5(Blue,3);
    Card card6(Yellow,3);
    Card card7(Red,3);

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
    sCombo.checkCombo();

    Combo combs;
    combs = sCombo.getHighestCombo();

    for (auto x : combs.getCombo()) {
        cout << x.getNumber() << " " << x.getColor() << endl;
    }

    return 0;
}
