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
        const string actnColor;
    public :    
        static string retrieveInput();

        void isValid(string input);
        
        void splashScreen();
        string mainMenu();  
        void inputPlayerName(Game& game);
        void printTable(Table);
        
        void printAbilitySuccess(const Player& , const vector<string>& );
        void printAbilitySuccess(const Player& ,const Point& );
        void printActionSuccess(const Player& ,const Point&, int );

        vector<string> selectPlayer(const Player& , const vector<pair<Player&, bool>>& );
        vector<int> selectCard(const vector<string> );

        void printEndGame(const vector<pair<Player&, bool>>&);


};