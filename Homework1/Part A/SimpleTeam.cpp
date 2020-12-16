//
//  SimpleTeam.cpp
//  CS 201 HW #1
//
//  Created by Bartu Atabek on 11/6/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "SimpleTeam.h"

Team::Team() {
    
}

Team::Team(string teamName, string teamColor) {
    setTeamName(teamName);
    setTeamColor(teamColor);
}

string Team::getTeamName() {
    return teamName;
}

string Team::getTeamColor() {
    return teamColor;
}

void Team::setTeamName(string name) {
    teamName = name;
}

void Team::setTeamColor(string color) {
    teamColor = color;
}
