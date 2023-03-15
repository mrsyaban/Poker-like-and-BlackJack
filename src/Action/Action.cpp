#include "Action.hpp"
#include "../Game/Game.hpp"
#include "../IO/IO.hpp"
#include "../Player/Player.hpp"

/* Next Action */
Next::Next() {}
void Next::Execute(Game& g) {
    // do nothing

    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printActionSuccess(owner, g.getPoint(), 1);
}

/* Double Action */
Double::Double() {}
void Double::Execute(Game& g) {
    g.getPoint().Double();

    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printActionSuccess(owner, g.getPoint(), 2);
}

/* Half Action */
Half::Half() {}
void Half::Execute(Game& g) {
    g.getPoint().Half();

    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printActionSuccess(owner, g.getPoint(), 3);
}