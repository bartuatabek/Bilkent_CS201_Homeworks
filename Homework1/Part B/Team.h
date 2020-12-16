//
//  Team.h
//  CS 201 HW #1
//
//  Created by Bartu Atabek on 11/6/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#ifndef Team_h
#define Team_h

#include <string>
using namespace std;
#include "Team.h"

class Team {
public:
    Team();
    Team(string teamName, string teamColor);
    Team(const Team &teamToCopy);
    ~Team();
    void operator=(const Team &right);
    
    string getTeamName();
    string getTeamColor();
    string** getPlayers();
    int getTeamSize();
    
    void setTeamName(string teamName);
    void setTeamColor(string teamColor);
    void addPlayer(string playerName, string position);
    void removePlayer(string playerName);
    
private:
    int teamSize;
    string teamName;
    string teamColor;
    string **players;
    int findPlayer(string playerName);
};
#endif
