//
//  Team.h
//  CS 201 HW #3
//
//  Created by Bartu Atabek on 12/1/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#ifndef Team_h
#define Team_h

#include <string>
using namespace std;
#include "Team.h"
#include "Player.h"

class Team {
public:
    Team();
    Team(string teamName, string teamColor);
    Team(const Team &teamToCopy);
    ~Team();
    void operator=(const Team &right);
    
    string getTeamName();
    string getTeamColor();
    int getTeamSize();
    bool getPlayer(string playerName);
    void getPlayers();
    
    void setTeamName(string teamName);
    void setTeamColor(string teamColor);
    void addPlayer(string playerName, string position);
    void removePlayer(string playerName);
    
private:
    struct Node {
        Player p;
        Node* next;
    };
    int teamSize;
    string teamName;
    string teamColor;
    Node* head;
    Node* findPlayer(string playerName);
};
#endif
