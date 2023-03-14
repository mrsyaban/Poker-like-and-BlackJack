#include "../Game/Game.hpp"
#include "../Exception/exception.h"


class IO {
    private:         
        const string lineColor = "\033[1m\033[33m";
        const string resetColor = "\033[0m";
        const string wordColor = "\033[1m\033[36m";
        const string inputColor = "\033[1m\033[36m";
        const string enterColor = "\033[5m\033[1m\033[33m";
        const string abilColor;
    public :    
        static string retrieveInput();
        
        void splashScreen();
        string mainMenu();  
        void inputPlayerName(Game& game);
        void printTable(Table);
        
        void printAbilitySuccess(const Player& , const vector<string>& );
        void printAbilitySuccess(const Player& ,const Point& );

        vector<string> selectPlayer(const Player& , const vector<pair<Player&, bool>>& );
        vector<int> selectCard(const vector<string> );

        void printEndGame(const vector<pair<Player&, bool>>&);
};