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
        Combo combo;
        vector<Combo> records;

    public:
        SearchCombo(); // ctor
        SearchCombo(Player player, Table table); // constructor
        ~SearchCombo(); // destructor

       
        Combo getCombo() const; // Combo Getter
        void setCombo(Combo); // Combo Getter
        vector<Card> getCards() const; // Cards Getter
        void setCards(vector<Card>); // Cards Setter
        vector<Combo> getRecords() const; // Records Getter
        void setRecords(vector<Combo>); // Records Setter

        vector<Card> getComboCards() const; // Combo Cards getter

        vector<Card> sortCards(); // Sorting cards by number and color
        vector<Card> sortCombo(); // Sorting combo by number and color
        
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