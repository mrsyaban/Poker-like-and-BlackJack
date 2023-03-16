#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <vector>
#include <algorithm>
#include "../Card/Card.hpp"
// #include "../Player/Player.hpp"
// #include "../Table/Table.hpp"
#include "../ObjectWithValue/ObjectWithValue.hpp"
// #include "../Exception/exception.h"
// #include "../ArrayUtil/ArrayUtil.hpp"
// #include "SearchCombo.hpp"

class Combo : public ObjectWithValue<double> {
    private:
        double score;
        vector<Card> combo;

    public:
        Combo(); // ctor
        //Combo(SearchCombo combo); // constructor
        ~Combo(); // destructor

        double value() const; // Score Getter
        void setScore(double number); // Setter
        vector<Card> getCombo() const; // Combo Getter
        void setCombo(Combo); // Combo Setter
        void setCombo(vector<Card>); // Combo Setter

        bool operator<(const Combo& other);
        bool operator>(const Combo& other);
        bool operator==(const Combo& other);

};

#endif