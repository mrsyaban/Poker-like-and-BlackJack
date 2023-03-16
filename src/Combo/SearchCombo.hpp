#ifndef _SEARCH_COMBO_HPP_
#define _SEARCH_COMBO_HPP_

#include <vector>
#include <algorithm>
#include "../Card/Card.hpp"
#include "../Player/Player.hpp"
#include "../Table/Table.hpp"
#include "../ObjectWithValue/ObjectWithValue.hpp"
#include "../Exception/exception.h"
#include "../ArrayUtil/ArrayUtil.hpp"
#include "Combo.hpp"

class SearchCombo {
    private:
        vector<Card> cards;
        vector<Combo> records;

    public:
        SearchCombo(); // ctor
        SearchCombo(Player player, Table table); // constructor
        ~SearchCombo(); // destructor

        /* Getter */
        Combo getCombo() const; // Combo Getter
        vector<Card> getCards() const; // Cards Getter
        vector<Combo> getRecords() const; // Records Getter

        /* Setter */
        void setCombo(Combo); // Combo Setter
        void setCards(vector<Card>); // Cards Setter
        void setRecords(vector<Combo>); // Records Setter

        //vector<Card> getComboCards(); // Combo Cards getter

        void sortCards(); // Sorting cards by number and color
        void sortCards2(); // Sorting combo by number and color
        bool compareCards(Card, Card);
        
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

        // bool operator<(const Combo& other);
        // bool operator>(const Combo& other);
        // bool operator==(const Combo& other);

        Combo getHighestCombo();
};


#endif