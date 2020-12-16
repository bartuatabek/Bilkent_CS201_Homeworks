//
//  SimpleTeam.h
//  CS 201 HW #3
//
//  Created by Bartu Atabek on 12/1/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#ifndef SimpleTeam_h
#define SimpleTeam_h

#include <string>
using namespace std;
#include "SimpleTeam.h"

class Team {
public:
    Team();
    Team(string teamName, string teamColor);
    
    string getTeamName();
    string getTeamColor();
    
    void setTeamName(string teamName);
    void setTeamColor(string teamColor);
    
private:
    string teamName;
    string teamColor;
};
#endif
