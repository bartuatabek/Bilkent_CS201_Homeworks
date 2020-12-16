//
//  SimpleTeam.cpp
//  CS 201 HW #3
//
//  Created by Bartu Atabek on 12/1/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "SimpleTeam.h"

// default constructor
Team::Team() {
}

// optional constructor
Team::Team(string teamName, string teamColor) {
    setTeamName(teamName);
    setTeamColor(teamColor);
}

// returns the team name
string Team::getTeamName() {
    return teamName;
}

// returns the team color
string Team::getTeamColor() {
    return teamColor;
}

// sets the team name
void Team::setTeamName(string name) {
    teamName = name;
}

// sets the team color
void Team::setTeamColor(string color) {
    teamColor = color;
}
