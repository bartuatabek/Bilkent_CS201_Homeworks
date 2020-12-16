//
//  Team.cpp
//  CS 201 HW #1
//
//  Created by Bartu Atabek on 11/6/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Team.h"

// default constructor
Team::Team() {
    teamSize = 0;
    players = NULL;
}

// optional constructor
Team::Team(string teamName, string teamColor) {
    setTeamName(teamName);
    setTeamColor(teamColor);
    teamSize = 0;
    players = NULL;
}

// destructor
Team::~Team() {
    if (players) {
        for ( int i = 0 ; i < teamSize ; i++ )
            delete [] players[i] ;
        
        delete [] players;
    }
}

// copy constructor
Team::Team(const Team &teamToCopy)
:teamName(teamToCopy.teamName), teamColor(teamToCopy.teamColor), teamSize(teamToCopy.teamSize) {
    if (teamSize > 0) {
        players = new string*[teamSize];
        
        for (int i = 0; i < teamSize; i++)
            players[i] = new string[2];
        
        for (int i = 0; i < teamSize - 1; i++) {
            for (int j = 0; j < 2; j++)
                players[i][j] = teamToCopy.players[i][j];
        }
    }
    else
        players = NULL;
}

// overloaded assignment operator
void Team::operator=(const Team &right) {
    if (&right != this) {
        if (teamSize != right.teamSize) {
            if (teamSize > 0)
                delete [] players;
            teamSize = right.teamSize;
            if (teamSize > 0) {
                players = new string*[teamSize];
                
                for (int i = 0; i < teamSize; i++)
                    players[i] = new string[2];
            }
            else
                players = NULL;
        }
        for (int i = 0; i < teamSize - 1; i++) {
            for (int j = 0; j < 2; j++)
                players[i][j] = right.players[i][j];
        }
        
        teamName = right.teamName;
        teamColor = right.teamColor;
    }
}

// returns the team name
string Team::getTeamName() {
    return teamName;
}

// returrns the team color
string Team::getTeamColor() {
    return teamColor;
}

// returns the location of the team players
string** Team::getPlayers() {
    return players;
}

// returns the size of the team
int Team::getTeamSize() {
    return teamSize;
}

// sets the team name
void Team::setTeamName(string name) {
    teamName = name;
}

// sets the team color
void Team::setTeamColor(string color) {
    teamColor = color;
}

// adds a player to the team with it's position
void Team::addPlayer(string playerName, string position) {
    
    if (findPlayer(playerName) == -1) {
        string **temp = players;
        teamSize++;
        players = new string* [teamSize];
        
        for (int i = 0; i < teamSize; i++) {
            players[i] = new string[2];
        }
        
        for (int i = 0; i < teamSize - 1; i++) {
            for (int j = 0; j < 2; j++) {
                players[i][j] = temp[i][j];
            }
        }
        
        players[teamSize - 1][0] = playerName;
        players[teamSize - 1][1] = position;
        
        if (temp) {
            for ( int i = 0 ; i < teamSize - 1 ; i++ )
                delete [] temp[i];
            delete [] temp;
        }
    }
    else
        cout << "Warning: The player you want to add already in team!" << endl;
}

// removes the selected player from the team
void Team::removePlayer(string playerName) { 
    
    int index = findPlayer(playerName);
    
    if (index == -1)
        cout << "Warning: The player you want to remove does not exist!" << endl;
    
    else {
        string ** temp = players;
        teamSize--;
        
        players = new string* [teamSize];
        
        for (int i = 0; i < teamSize; i++) {
            players[i] = new string[2];
        }
        
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < 2; j++)
                players[i][j] = temp[i][j];
        }
        
        for (int i = index; i < teamSize; i++) {
            for (int j = 0; j < 2; j++)
                players[i][j] = temp[i + 1][j];
        }
        
        if (temp) {
            for ( int i = 0 ; i < teamSize + 1 ; i++ )
                delete [] temp[i] ;
            delete [] temp ;
        }
    }
}

// finds a specific player inside the team and returns it's index
int Team::findPlayer(string playerName) {
    
    for (int i = 0; i < teamSize; i++) {
        if (players[i][0].length() == playerName.length()) {
            for (int j = 0; j < playerName.length(); j++) {
                if (tolower(players[i][0][j]) != tolower(playerName[j]))
                    break;
            }
            return i;
        }
    }
    return -1;
}
