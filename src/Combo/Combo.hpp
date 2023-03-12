#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <vector>
#include <algorithm>
#include "./Card/Card.hpp"
#include "./ObjectWithValue/ObjectWithValue.hpp"

class Combo : public ObjectWithValue<double> {
    private:
        double score;
        vector<Card> cards;
        vector<Card> combo;
    public:
        Combo(); // constructor
        ~Combo(); // destructor

        void setScore(float number); // Setter
        float getScore(); // Score Getter
        vector<Card> getCombo(); // Combo Getter

        int length(); // Length of Hand Card and Table Card
        vector<Card> sortCards();
        
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
};

#endif