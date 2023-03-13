#include <iostream>
#include <string>
using namespace std;

class IO {
    private: 
        string input;        

    public :
        void setInput(string);

        void splashScreen();
        void inputPlayerName();
        void mainMenu();
        bool isValid();
};