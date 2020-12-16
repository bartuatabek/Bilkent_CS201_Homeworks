//
//  BasketReg.cpp
//  CS 201 HW #1
//
//  Created by Bartu Atabek on 11/19/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "BasketReg.h"

// default constructor
BasketReg::BasketReg() {
    teamNo = 0;
    teams = NULL;
}

// destructor
BasketReg::~BasketReg() {
    if (teams)
        delete [] teams;
}

// copy constructor
BasketReg::BasketReg(const BasketReg &systemToCopy)
:teamNo(systemToCopy.teamNo) {
    if (teamNo > 0) {
        teams = new Team[teamNo];
        for (int i = 0; i < teamNo; i++)
            teams[i] = systemToCopy.teams[i];
    }
    else
        teams = NULL;
}

// overloaded assignment operator
void BasketReg::operator=(const BasketReg &right) {
    if (&right != this) {
        if (teamNo != right.teamNo) {
            if (teamNo > 0)
                delete [] teams;
            teamNo = right.teamNo;
            if (teamNo > 0)
                teams = new Team[teamNo];
            else
                teams = NULL;
        }
        for (int i = 0; i < teamNo; i++)
            teams[i] = right.teams[i];
    }
}

// add a new team to the register
void BasketReg::addTeam(string teamName, string teamColor) { // edit roster
    if (findTeam(teamName) == -1) {
        Team *temp = teams;
        teamNo++;
        teams = new Team[teamNo];
        
        for (int i = 0; i < teamNo - 1; i++) {
            teams[i] = temp[i];
        }
        
        teams[teamNo - 1].setTeamName(teamName);
        teams[teamNo - 1].setTeamColor(teamColor);
        
        if (temp != NULL)
            delete []temp;
    }
    else
        cout << "Warning: The team you want to add already exists!" << endl;
}

// remove selected team from the register
void BasketReg::removeTeam(string teamName) {
    if (teamNo > 0) {
        int index = findTeam(teamName);
        
        if (index == -1) {
            cout << "Warning: The team you want to remove does not exist!" << endl;
        }
        else {
            Team *temp = teams;
            teamNo--;
            teams = new Team[teamNo];
            
            for (int i = 0; i < teamNo; i++) {
                if (i != index)
                    teams[i] = temp[i];
                else
                    teams[i] = temp[i + 1];
            }
            
            if (temp != NULL)
                delete []temp;
        }
    }
}

// displays all teams in the registers
void BasketReg::displayAllTeams() {
    if (teamNo == 0)
        cout << "--EMPTY--" << endl;
    else {
        for (int i = 0; i < teamNo; i++) {
            cout << teams[i].getTeamName() + ", " + teams[i].getTeamColor() << endl;
        }
    }
}

// adds a player to the selected team with its position
void BasketReg::addPlayer(string teamName, string playerName, string playerPosition) {
    if (teamNo > 0) {
        int index = findTeam(teamName);
        
        if (index == -1)
            cout << "Warning: The team does not exist!" << endl;
        
        else
            teams[index].addPlayer(playerName, playerPosition);
    }
}

// removes the selected player from the selected team
void BasketReg::removePlayer(string teamName, string playerName) {
    if (teamNo > 0) {
        int index = findTeam(teamName);
        
        if (index == -1)
            cout << "Warning: The team does not exist!" << endl;
        
        else
            teams[index].removePlayer(playerName);
    }
}

// display detailed info about the selected team
void BasketReg::displayTeam(string teamName) {
    int index = findTeam(teamName);
    
    if (index == -1)
        cout << teamName + ", \n--EMPTY--" << endl;
    else {
        cout << teams[index].getTeamName() + ", " + teams[index].getTeamColor() << endl;
        for (int i = 0; i < teams[index].getTeamSize(); i++) {
            cout << teams[index].getPlayers()[i][0] + ", " + teams[index].getPlayers()[i][1] << endl;
        }
    }
    
}

// display detailed info about the selected player
void BasketReg::displayPlayer(string playerName) { // fuck
    cout << playerName << endl;
    
    bool found = false;
    
    for (int i = 0; i < teamNo; i++) {
        string** players = teams[i].getPlayers();
        
        for (int j = 0; j < teams[i].getTeamSize(); j++) {
            if (players[j][0] == playerName) {
                cout << players[j][1] + ", " + teams[i].getTeamName() + ", " + teams[i].getTeamColor() << endl;
                found = true;
            }
        }
    }
    
    if (!found)
        cout << "--EMPTY--" << endl;
}

// finds the selected team and returns it's index
int BasketReg::findTeam(string teamName) {
    for (int i = 0; i < teamNo; i++) {
        if (teams[i].getTeamName().size() == teamName.size()) {
            for (int j = 0; j < teamName.size(); ++j) {
                if (tolower(teams[i].getTeamName()[j]) != tolower(teamName[j]))
                    return -1;
            }
            return i;
        }
    }
    return -1;
}
