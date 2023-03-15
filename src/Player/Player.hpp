#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include "../Combo/Combo.hpp"
#include <string>


class Player : public InventoryHolder<Card> {
    private:
        const string nickName;
        Ability* handAbility;
        int handPoint;
        Combo highestCombo;

    public:
        Player(string); // ctor

        /* Operator Overloading*/
        friend bool operator<(const Player& p1, const Player& p2);
        friend bool operator>(const Player& p1, const Player& p2);
        friend bool operator==(const Player& p1, const Player& p2);

        /* Accessor */
        string getNickname() const;
        Ability* getAbility() const;
        int getPoint() const;
        Combo getHighestCombo() const;

        Card getCard(int position) const;
        void getInfo() const;

        /* Setter */
        void setHighestCombo(Combo);
        void setAbility(Ability&);
        void dealToPlayer(InventoryHolder<Card>&);

        /* Utility Function*/
        void addPoint(int );

};

#endif