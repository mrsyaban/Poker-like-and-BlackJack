#ifndef ACTION_HPP
#define ACTION_HPP

#include "../Game/Game.hpp"
#include "../IO/IO.hpp"

/* Abstract class Action */
class Action {
    public:
        virtual void Execute(Game&) = 0;
};

/* Next Action */
class Next : public Action {
    public:
        Next();
        void Execute(Game&);
};

/* Double Action */
class Double : public Action {
    public:
        Double();
        void Execute(Game&);
};

/* Half Action */
class Half : public Action {
    public:
        Half();
        void Execute(Game&);
};

#endif