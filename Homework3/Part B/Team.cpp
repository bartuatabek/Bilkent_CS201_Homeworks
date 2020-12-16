//
//  Team.cpp
//  CS 201 HW#3
//
//  Created by Bartu Atabek on 12/3/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Team.h"

// default constructor
Team::Team() :teamSize(0), head(NULL) {
}

// optional constructor
Team::Team(string teamName, string teamColor) :teamSize(0), head(NULL) {
    setTeamName(teamName);
    setTeamColor(teamColor);
}

// destructor
Team::~Team() {
    Node* current = this->head;
    while(current != NULL) {
        Node* temp = current->next;
        head = head->next;
        current->next = NULL;
        delete current;
        current = temp;
    }
}

// copy constructor
Team::Team(const Team &teamToCopy) :teamName(teamToCopy.teamName), teamColor(teamToCopy.teamColor), teamSize(teamToCopy.teamSize) {
    if (teamToCopy.head == NULL)
        head = NULL;
    else {
        head = new Node;
        head->p = teamToCopy.head->p;
        Node *newPtr = head;
        
        for (Node *origPtr = teamToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->p = origPtr->p;
        }
        newPtr->next = NULL;
    }
}

// overloaded assignment operator
void Team::operator=(const Team &right) {
    if (&right != this) {
        teamName = right.teamName;
        teamColor = right.teamColor;
        
        Node* current = this->head;
        Node* temp;
        while(current != NULL) {
            temp = current->next;
            head = head->next;
            current->next = NULL;
            delete current;
            current = temp;
        }
        
        if(right.head != NULL) {
            head = new Node;
            head->p = right.head->p;
            Node *newPtr = head;
            
            for (Node *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
                newPtr->next = new Node;
                newPtr = newPtr->next;
                newPtr->p = origPtr->p;
            }
            newPtr->next = NULL;
        }
    }
}

// returns the team name
string Team::getTeamName() {
    return teamName;
}

// returns the team color
string Team::getTeamColor() {
    return teamColor;
}

// returns the size of the team
int Team::getTeamSize() {
    return teamSize;
}

// returns whether the player exists in the team or not
bool Team::getPlayer(string playerName) {
    if (findPlayer(playerName) != NULL) {
        cout << findPlayer(playerName)->p.getPosition();
        return true;
    }
    else
        return false;
}

// returns the head node of the players list
void Team::getPlayers() {
    for (Node* cur = head; cur != NULL; cur = cur->next)
        cout << cur->p.getPlayerName() + ", " + cur->p.getPosition() << endl;
}

// sets the team name
void Team::setTeamName(string teamName) {
    this->teamName = teamName;
}

// sets the team color
void Team::setTeamColor(string teamColor) {
    this->teamColor = teamColor;
}

// adds a player to the team with it's position
void Team::addPlayer(string playerName, string position) {
    if (findPlayer(playerName) == NULL) {
        Node* nodePtr = new Node;
        teamSize++;
        nodePtr->p = Player(playerName, position);
        
        if (head == NULL) {
            nodePtr->next = NULL;
            head = nodePtr;
        }
        else {
            Node *cur = head;
            while (cur->next != NULL)
                cur = cur->next;
            nodePtr->next = cur->next;
            cur->next = nodePtr;
        }
    }
    else
        cout << "The player already exists!" << endl;
}

// removes the selected player from the team
void Team::removePlayer(string playerName) {
    Node* index = findPlayer(playerName);
    
    if (index != NULL) {
        Node* cur;
        teamSize--;
        
        if (index == head) {
            cur = head;
            head = head->next;
        }
        else {
            Node* prev = NULL;
            
            for (Node* tmp = head; tmp != NULL; tmp = tmp->next) {
                if (tmp->next == index) {
                    prev = tmp;
                    break;
                }
            }
            
            cur = prev->next;
            prev->next = cur->next;
        }
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
    else
        cout << "The player does not exist!" << endl;
}

// finds a specific player inside the team and returns it's index
Team::Node* Team::findPlayer(string playerName) {
    transform(playerName.begin(), playerName.end(), playerName.begin(), ::tolower);
    
    for(Node* cur = head; cur != NULL; cur = cur->next) {
        string tmp = cur->p.getPlayerName();
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        
        if (tmp == playerName)
            return cur;
    }
    return NULL;
}
