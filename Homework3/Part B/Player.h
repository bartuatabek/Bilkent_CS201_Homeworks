//
//  Player.h
//  CS 201 HW#3
//
//  Created by Bartu Atabek on 12/3/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <string>
using namespace std;
#include "Player.h"

class Player {
public:
    Player();
    Player(string playerName, string position);
    Player(const Player &playerToCopy);
    void operator=(const Player &right);
    
    string getPlayerName();
    string getPosition();
    
    void setPlayerName(string playerName);
    void setPosition(string position);
    
private:
    string playerName;
    string position;
};
#endif

