#include "GameEngine.hpp"
#include <iostream>
using namespace std;

void GameEngine::start() {
    //input pilih game
    Game g;
    Blackjack b;

    IO io;
    string mainMenu = "";
    io.splashScreen();
    io.mainMenuTitle();

    // read input
    while (mainMenu == "") {
        try
        {
            mainMenu = io.mainMenu();
        }
        catch (BaseException &e)
        {
            std::cout << e.what() << endl;
        }
    }
    
    while(mainMenu != "0"){
        if (mainMenu == "1"){
            g.start();
        } else {
            b.start();
        }
        io.mainMenuTitle();
        mainMenu = io.mainMenu();
    }
    
    io.printThankYou();
}