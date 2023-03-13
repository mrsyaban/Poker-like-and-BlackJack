#include "../Game/Game.hpp"

#include <iostream>
#include <string>
using namespace std;

class IO {
    private:         
        const string lineColor = "\033[1m\033[33m";
        const string resetColor = "\033[0m";
        const string wordColor = "\033[1m\033[36m";
        const string inputColor = "\033[1m\033[36m";
        const string enterColor = "\033[5m\033[1m\033[33m";


    public :    
        static string retrieveInput();
        void splashScreen();
        string mainMenu();  
        void inputPlayerName(Game& game);
        bool isValid();
        void addPlayer();
};