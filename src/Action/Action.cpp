#include "Action.hpp"

/* Next Action */
Next::Next() {}
void Next::Execute(Game& g) {
    // do nothing
}

/* Double Action */
Double::Double() {}
void Double::Execute(Game& g) {
    g.getPoint().Double();
}

/* Half Action */
Half::Half() {}
void Half::Execute(Game& g) {
    g.getPoint().Half();
}