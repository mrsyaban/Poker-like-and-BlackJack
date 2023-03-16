#ifndef BLACKJACK_HPP_
#define BLACKJACK_HPP_

#include "../Card/Card.hpp"
#include "../Deck/Deck.hpp"
#include "../Player/Player.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Table/Table.hpp"
#include "../Point/Point.hpp"
#include "../IO/IO.hpp"


const map<int, string> cardToBJCard = {
    {1, "A"},
    {2, "2"},
    {3, "3"},
    {4, "4"},
    {5, "5"},
    {6, "6"},
    {7, "7"},
    {8, "8"},
    {9, "9"},
    {10, "10"},
    {11, "Jack"},
    {12, "Queen"},
    {13, "King"}
};

const map<string, int> getBJValue = {
    {"A", 11},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"Jack", 10},
    {"Queen", 10},
    {"King", 10}
};

class BlackjackPlayer : private Player {
    private:
        bool bust;

    public:
        Point getPoint();
        int getTotalCard();
        void hit(InventoryHolder&);
};

class Blackjack {
    private:
        Table dealer;
        Point pricePool;
        Deck<Card> deck;
        BlackJackPlayer bjPlayer;

    protected:

    public:
        Blackjack();
        void start();
        void hit();

};

#endif