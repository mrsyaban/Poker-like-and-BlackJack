#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <vector>
#include <algorithm>
#include "../Card/Card.hpp"
#include "../Player/Player.hpp"
#include "../Table/Table.hpp"
#include "../ObjectWithValue/ObjectWithValue.hpp"

class Combo : public ObjectWithValue<double> {
    private:
        double score;
        vector<Card> cards;
        vector<Card> combo;

    public:
        Combo(); // ctor
        Combo(Player player, Table table); // constructor
        ~Combo(); // destructor

        double value() const; // Score Getter
        void setScore(double number); // Setter
        vector<Card> getCombo(); // Combo Getter
        void setCombo(vector<Card>); // Combo Getter
        vector<Card> getCards(); // Cards Getter
        void setCards(vector<Card>); // Cards Setter

        int length(); // Length of Hand Card and Table Card
        vector<Card> sortCards(); // Sorting cards berdasarkan angka masih
        
        void highCard(); 
        void pair();
        void twoPair();
        void threeOfAKind();
        void straight();
        void flush();
        void fullHouse();
        void fourOfKind();
        void straightFlush();

        void checkCombo();

        bool operator<(const Combo& other);
};

#endif