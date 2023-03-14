#include "IO.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string retrieveInput(){
    string input;
    cout << "\033[0m" << "\033[1m\033[36m" << " ";
    cin >> input;
    cout << "\033[0m" << endl;
    return input;
}

string IO::turnInput(Player& player){
    cout << enterColor;
    cout << player.getNickname() << "'s turn >>> " << resetColor;
    string input = retrieveInput();

    // input validation
    vector<string> validString = {
        "NEXT",
        "HALF",
        "DOUBLE",
        "RE-ROLL",
        "QUADRUPLE",
        "QUARTER",
        "REVERSE",
        "SWAP CARD",
        "SWITCH",
        "ABILITYLESS"
    };

    if (find(validString.begin(), validString.end(), input) == validString.end()){
        inputException err;
        throw err;
    }

    return input;
}

void IO::splashScreen(){
    string spades = "\033[1;34m";
    string clubs = "\033[1;33m";
    string hearts = "\033[1;31m";
    string diamonds = "\033[1;32m";

    string splash = clubs +                                                                    
"                          .,;;;:::::::::::;;;;;;;,,,;;,.                                            \n"
"                          .olcoxxxxxxxxxxxxxxxxxkkkkOOO;                                            \n"
"                          .lc;lxxxxxxxxxxxxkkkOOO0000KKc                                            \n"
"                          .lc,cxxxxxxxkkkOOO000KKXXXXNNl....            "+spades+".'..                        \n"
+hearts+"                          .cl:"+clubs+"ldxkkkkOO000KKKXXNNNNNWWWd"+diamonds+",cooc:;'...    "+spades+"'llcl:,..                    \n"
+hearts+"                       ..,cdxl,"+clubs+":dkO000KKXXXNNNWWWWWWWWWx"+diamonds+";cdxxxxxdolc;,,"+spades+"cc':ddddl:'.                 \n"
+hearts+"                   ..,:ldkkO0Kd;"+clubs+":x0KXX0OOO0XWWWWWWWWWWWk"+diamonds+";lxxxxxxxxxxxkxxdolc"+spades+"oxxxxxoc;..             \n"
+hearts+"               ..,:lodxxkO00KXNOc"+clubs+"ckXXx:;,,;cOWWWWWWWWWWk"+diamonds+":okkkkOOOOOOOOO000l,c"+spades+"dxxxxxxxdl;'.          \n"
+hearts+"            .':ldxxxxxkOO0KXXNWWKo"+clubs+"lxOo'....'xNWWWWWWWWWk"+diamonds+"lx0000KKKKKKKXXXXO;,"+spades+"lxxxxxxxxxxxdl;'..      \n"
+hearts+"        ..,coxxxxxxxkkO0KKXNNWWWWNd"+clubs+"'.,......,;:xNWWWWWWk"+diamonds+"oOXXXXXNNNNNNNNNNd,"+spades+"cxOOOOkkkkkkkxxxxoc,\n"
+hearts+"     .';lodxxxxxxxxkOO0KXXNWWWWWWWNx."+clubs+"          'OWWWWWNk"+diamonds+"oxkKNWWWWWWWWWWWKcc"+spades+"k000000000000OOOOOOkd'\n"
+hearts+"    .:olldxxxxxxxkkO0KKXNNWWWWWWWWWWO'"+clubs+" ';'.    ,0WNNNNXd"+diamonds+",',c0WWWWWWWWWWWkc"+spades+"xXNNXXXXXXXXXXKKKKKKO:\n"
+hearts+"     .clccoxxxxxkOO0KXNNWNKOOOKWWWWWW0"+clubs+"oc;lxc,,cONNXXXKKl"+diamonds+"...';kNWWWWWWWMKll"+spades+"kOOxkNWNWWNNNNNNNNN0;\n"
+hearts+"      .:occdxxkkO0KKXNNWNx:,'';oKWWWWWK;"+clubs+".'kNXXXXKKKK00Oc"+diamonds+".....,dNWWWWWWWd."+spades+".....:0WWWWWWWWWWWW0;\n"
+hearts+"       .;oxxxkOO0KK0kxdkx;......lNWWWNN0"+clubs+"doOXKKK00OOOOkkc"+diamonds+".......oXWWWWW0,"+spades+"      .lKWWWWWWWWWW0, \n"
+hearts+"         'oxkOO0KXOc,''.........oNWWNNXKO"+clubs+"cdO0OOOkkkkxxx:"+diamonds+".....,lkNWWWWNl"+spades+"       ..cKWWWWWWWWO, \n"
+hearts+"          .oO00KXNx;'..........cKWWNXXK0Ok"+clubs+"olxkkxxxxdolo;"+diamonds+"..;oOXWWWNNNNO,"+spades+"..      .'xWWWWWWWx'\n"
+hearts+"           .o0KXNWXd,.........:KWNNXXK0Okkx"+clubs+"ocoxxxxxd:,cc"+diamonds+"l0NNNNXXXXXX0d"+spades+"c;;c'    .:KWWWWWNx.\n"
+hearts+"            .oKNNWWN0xolllc:,,kWNNXKK0Okkxxdl"+clubs+"coxxxxxc;ll"+diamonds+"kXXKKKKK000Ox"+spades+"dd;;O0l;;cxXWWWWWXx.\n"
+hearts+"             .lXWWWWWWWMWMWWXKXNXXK0OOkxxxoccl"+clubs+"clddddc:ll"+diamonds+"x000OOOOOOkx"+spades+"okXXKKNXXXNNXXXXX0;\n"
+hearts+"               cXWWWWWWWWWWWWNNXXK0Okkxxxxdoccl"+diamonds+"ccoooooodkkkkkkkkxxx"+spades+"loO000000KKKKKKK0x,\n"
+hearts+"                :KWWWWWWWWWWNNXK00Okkxxxxxxxocll"+diamonds+"cdkxxxxxxxxxxxxoodo"+spades+"cdkkOOOOOOOOOOOko\n"
+hearts+"                 ,0WWWWWWWNNXXK0Okkxxxxxxxxdl"+diamonds+"cclodxxxxxxxxxxxxdl:l"+spades+"clxxxxxxxxxkxxkx:\n"
+hearts+"                  'kWWWWNNXXK0OOkxxddxxxdc;'"+diamonds+"ccc,;::cloddxxxxddl:ll"+spades+"cdxxxxxxxxdccdo;\n"
+hearts+"                   .dXNNXKK0Okkxdddddo:,               "+diamonds+"',;;:clccl"+spades+";,codddddddc,;c,\n"
+hearts+"                    .l0K00Okxxddolc;'.                 "+diamonds+"........'"+spades+".....,:cooo:,:c'\n"
+hearts+"                     .:kOkxddoc;,.                                   "+spades+"...,;;:;\n"
+hearts+"                       ,odlc,...          "+" _       __"+clubs+"____  "+diamonds+"____"+spades+"__\n"
+hearts+"                        ....              "+ "| |     / /"+clubs+" __ \\"+diamonds+"/  _/ "+spades+"/\n"
+hearts+"                                          | | /| / / "+clubs+"/ / /"+diamonds+"/ // "+spades+"/ \n"
+hearts+"                                          | |/ |/ / "+clubs+"/_/ /"+diamonds+"/ //"+spades+"_/  \n"   
+hearts+"                                          |__/|__/"+clubs+"\\____/"+diamonds+"___"+spades+"(_)   \n" + resetColor;
                       
    cout << splash << endl;
}

string IO::mainMenu(){
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "          MAIN MENU           " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << " 1. Start " << endl;
    cout << wordColor << " 2. Exit" << endl;
    cout << endl;
    cout << enterColor << "Enter Command >>>"; 
    
    string command = retrieveInput();
    cout << resetColor << endl;
    return command; 
}

void IO::inputPlayerName(Game& game){
    string nick1, nick2, nick3, nick4, nick5, nick6, nick7;
    cout << wordColor << "Please enter player name :" << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    for (int i=1; i<=7; i++) {
        cout << enterColor<< "Player " << i <<" >>> "; game.addPlayer();
    }
    cout << resetColor << endl;
}

void IO::printTable(Table table){
    cout << wordColor << "            ♦ TABLE ♦         " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    for (int i=0; i<table.getNeff(); i++){
        int color = table.getItems(i).getColor();
        if (color == 0){
            cout << "\033[1m\033[32m";
        } else if (color == 1){
            cout << "\033[1m\033[34m";
        } else if (color == 2){
            cout << "\033[1m\033[33m";
        } else {
            cout << "\033[1m\033[31m";
        }
        cout << "  " << table.getItems(i).getNumber() << "  " << endl;
        cout << resetColor;
    }
}

void IO::printAbilitySuccess(const Player& player, vector<string> resPlayer = {}, vector<string> reversed = {}){
    string type = player.getAbility()->getType(); 
    cout << abilColor;
    // Re-Roll
    if ( type == "Re-Roll"){
        cout << "Replacing your current cards..." << endl;
        cout << "You got 2 new cards :" << endl;
        cout << "1. " << player.getCard(0).getNumber() << " " << player.getCard(0).getColor() << endl;
        cout << "2. " << player.getCard(1).getNumber() << " " << player.getCard(1).getColor() << endl;
    
    // Swap Card
    } else if (type == "Swap"){
        cout << player.getNickname() << " successfully performed SWAP CARD!" << endl;
        cout << resPlayer[0] << "'s Card and " << resPlayer[1] << "'s Card has been swapped!" << endl; 
    
    // Switch
    } else if (type == "Switch"){
        cout << player.getNickname() << " successfully performed SWITCH!" << endl;
        cout << "both of your cards has been switched with " << resPlayer[0];
        cout << "your current cards are : " 
        << player.getCard(0).getNumber() << "-" << player.getCard(1).getColor() << " & "
        << player.getCard(1).getNumber() << "-" << player.getCard(1).getColor();
    
    // Abiilityless
    } else if (type == "Abilityless"){
        cout << player.getNickname() << " successfully performed ABILITYLESS! " << endl;
        cout << resPlayer[0] << "'s Ability Card has been disabled";

    // Reverse
    } else if (type == "Reverse"){
        cout << player.getNickname() << " successfully performed REVERSE! " << endl;
        cout << "The rest of players order for this round: ";
        for (auto itr = resPlayer.begin(); itr != resPlayer.end(); itr++){
            cout << *itr;
            if (itr != resPlayer.end()-1){
                cout << " - ";
            }
        }
        cout << endl;
        cout << "Players order for next round: ";
        for (auto itr = reversed.begin(); itr != reversed.end(); itr++){
            cout << *itr;
            if (itr != resPlayer.end()-1){
                cout << " - ";
            }
        }
        cout << endl;
    }
    cout << resetColor;
}


void IO::printAbilitySuccess(const Player& player, const Point& poin = Point()){
    string type = player.getAbility()->getType(); 
    cout << abilColor;
    
    // Quadruple
    if (type == "Quadruple"){
        cout << player.getNickname() << " successfully performed QUADRUPLE! Game Point has been quadrupled from" << endl;
        cout << poin.getValue()/4 << " became " << poin.getValue() << "!" << endl;
    
    // Quarter
    } else if (type == "Quarter"){
        cout << player.getNickname() << " successfully performed QUARTER! Game Point has been quartered from" << endl;
        cout << poin.getValue()*4 << " became " << poin.getValue() << "!" << endl;
    }
    cout << resetColor;
}

void IO::printActionSuccess(const Player& player, const Point& poin, int type){
    cout << actnColor;
    if (type == 1){
        cout << "Turn given to the next player" << endl;
    } else if (type == 2){
        cout << player.getNickname() << " successfully performed DOUBLE! Game Point has been doubled from" << endl;
        cout << poin.getValue()/2 << " became " << poin.getValue() << "!" << endl;
    } else if (type == 3){
        cout << player.getNickname() << " successfully performed HALF! Game Point has been halved from" << endl;
        cout << poin.getValue()*2 << " became " << poin.getValue() << "!" << endl;
    }
}

int IO::selectCard(string playersNick){
    int choice;
    cout << abilColor;

    cout << "Please choose which " << playersNick << "'s cards you want to swap :" << endl;
    cout << "1. Right" << endl;
    cout << "2. Left" << endl;
    cout << "\033[5m" << "Your choice Number >>> " << resetColor; cin >> choice;

    if (choice<1 || choice >2){
        NumberInputException err;
        throw err;
    }
    return choice;
}

void printPlayer(string nick, const vector<pair<Player&, bool>>& listPlayer){
    int i=1;
    for (auto p: listPlayer){
        if (nick != p.first.getNickname()){
            cout << i << ". " << listPlayer[i].first.getNickname() << endl;
            i++;
        }
    }
}

vector<Player>& IO::selectPlayer(const Player& player, const vector<pair<Player&, bool>>& listPlayer) const{
    string type = player.getAbility()->getType(); 
    string player1, player2;
    vector<Player> resPlayers;
    playerException err;

    cout << abilColor;
    if (type == "Swap"){
        cout << "Silakan pilih pemain yang kartunya ingin anda tukar :" << endl;
        printPlayer(player.getNickname(), listPlayer);
        cout << "\033[5m" << "Player's Name 1 >>> " << resetColor; cin >> player1;
        cout << abilColor;
        cout << "\033[5m" << "Player's Name 2 >>> " << resetColor; cin >> player2;

        for (auto p_itr = listPlayer.begin(); p_itr != listPlayer.end(); p_itr++) {
            if (p_itr->first.getNickname() == player1 || p_itr->first.getNickname() == player2){
                resPlayers.push_back(p_itr->first);
            }
        }

        // Exception
        if (player1 == player2){
            throw err;
        }

    } else if (type == "Switch"){
        cout << "Silakan pilih pemain yang kartunya ingin anda tukar :" << endl;
        printPlayer(player.getNickname(), listPlayer);
        cout << "\033[5m" << "Player's Name >>> " << resetColor; cin >> player1;
        
        for (auto p_itr = listPlayer.begin(); p_itr != listPlayer.end(); p_itr++) {
            if (p_itr->first.getNickname() == player1){
                resPlayers.push_back(p_itr->first);
            }
        }

    } else if (type == "Abilityless"){
        cout << "Silakan pilih pemain yang kartunya ingin anda matikan :" << endl;
        printPlayer(player.getNickname(), listPlayer);
        cout << "\033[5m" << "Player's Name >>> " << resetColor; cin >> player1;
        
        for (auto p_itr = listPlayer.begin(); p_itr != listPlayer.end(); p_itr++) {
            if (p_itr->first.getNickname() == player1 || p_itr->first.getNickname() == player2){
                resPlayers.push_back(p_itr->first);
            }
        }
    }
    
    cout << resetColor;
    return resPlayers;
}

void printHelper(string nick){
    if (nick.length() > 12){
        for (int i=0; i<14; i++){
            cout << nick[i];
        }
    } else {
        int rest = 14 - nick.length();
        cout << nick;
        for (int i=0; i<rest; i++){
            cout << " ";
        }
    }
}

void printHelper(int poin){
    int rest = 12 - to_string(poin).length();
    cout << poin;
    for (int i=0; i<rest; i++){
        cout << " ";
    }
    
}

void IO::printEndGame(const vector<pair<Player&, bool>>& listPlayer){
    cout << wordColor;
    cout << "Game Over!" << resetColor << endl; 
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "│          LEADERBOARD       │" << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;

    for (int i=0; i<7; i++){
        cout << lineColor << "│" << resetColor;
        cout << wordColor << i+1 << "." << resetColor;
        cout << lineColor << "│" << resetColor;
        cout << wordColor; printHelper(listPlayer[i].first.getNickname()); cout << resetColor;
        cout << wordColor; printHelper(listPlayer[i].first.getPoint()); cout << resetColor;
        cout << lineColor << "│" << resetColor << endl;
    }
    cout << lineColor << "==============================" << resetColor << endl;
}

// void IO::printCard(Card card){
//     int color = card.getColor();
//     int n = card.getNumber();
//     if (color == 0){
//         cout << "\033[1m\033[32m";
//     } else if (color == 1){
//         cout << "\033[1m\033[34m";
//     } else if (color == 2){
//         cout << "\033[1m\033[33m";
//     } else {
//         cout << "\033[1m\033[31m";
//     }
//     cout << "┌───────┐" << endl;
//     cout << "│ ";
//     if (n>10){
//         cout << n;
//     } else {
//         cout << n << " ";
//     }
//     cout << "    │" << endl;
//     cout << "│       │" << endl;
//     cout << "│   ♦   │" << endl;
//     cout << "│       │" << endl;
//     cout << "│    ";
//     if (n>10){
//         cout << n;
//     } else {
//         cout << " " << n;
//     }
//     cout << " │" << endl;
//     cout << "└───────┘" << endl;
//     cout << resetColor;
// }

