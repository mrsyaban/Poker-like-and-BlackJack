#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include "../Combo/Combo.hpp"
#include <string>


class Player : public InventoryHolder<Card> {
    private:
        string nickName;
        Ability& handAbility;
        int handPoint;
        Combo highestCombo;

    public:
        Player(); // ctor

        /* Operator Overloading*/
        friend bool operator<(const Player& p1, const Player& p2);
        friend bool operator>(const Player& p1, const Player& p2);

        /* Accessor */
        Card getCard(int position) const;
        int getPoint() const;
        Combo getHighestCombo() const;
        void getInfo() const;
        string getNickname() const;

        /* Setter */
        void setHighestCombo(Combo);
        void setNickName(string);

        /* Utility Function*/
        void addPoint(int );

};

#endif