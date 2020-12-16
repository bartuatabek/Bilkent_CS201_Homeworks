//
//  SimpleReg.cpp
//  CS 201 HW #1
//
//  Created by Bartu Atabek on 11/6/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "SimpleReg.h"

SimpleReg::SimpleReg() {
    teamNo = 0;
    teams = NULL;
}

void SimpleReg::addTeam(string teamName, string teamColor) {
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

void SimpleReg::removeTeam(string teamName) {
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

void SimpleReg::displayAllTeams() {
    if (teamNo == 0)
        cout << "--EMPTY--" << endl;
    else {
        for (int i = 0; i < teamNo; i++) {
            cout << teams[i].getTeamName() + ", " + teams[i].getTeamColor() << endl;
        }
    }
}

int SimpleReg::findTeam(string teamName) {
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
