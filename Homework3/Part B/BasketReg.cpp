//
//  BasketReg.cpp
//  CS 201 HW#3
//
//  Created by Bartu Atabek on 12/3/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "BasketReg.h"

// default constructor
BasketReg::BasketReg() :head(NULL), teamNo(0) {
}

// destructor
BasketReg::~BasketReg() {
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
BasketReg::BasketReg(const BasketReg &systemToCopy) :teamNo(systemToCopy.teamNo) {
    if (systemToCopy.head == NULL)
        head = NULL;
    else {
        head = new Node;
        head->t = systemToCopy.head->t;
        Node *newPtr = head;
        
        for (Node *origPtr = systemToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

// overloaded assignment operator 
void BasketReg::operator=(const BasketReg &right) {
    if (&right != this) {
        teamNo = right.teamNo;
        
        Node* current = this->head;
        Node* temp;
        while(current != NULL) {
            temp = current->next;
            head = head->next;
            current->next = NULL;
            delete current;
            current = temp;
        }
        
        if (right.head != NULL) {
            head = new Node;
            head->t = right.head->t;
            Node *newPtr = head;
            
            for (Node *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
                newPtr->next = new Node;
                newPtr = newPtr->next;
                newPtr->t = origPtr->t;
            }
            newPtr->next = NULL;
        }
    }
}

// add a new team to the register
void BasketReg::addTeam(string teamName, string teamColor) {
    if (findTeam(teamName) == NULL) {
        Node* nodePtr = new Node;
        teamNo++;
        nodePtr->t = Team(teamName, teamColor);
        
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
        cout << "Warning: The team you want to add already exists!" << endl;
}

// remove selected team from the register
void BasketReg::removeTeam(string teamName) {
    Node* index = findTeam(teamName);
    
    if (index != NULL) {
        Node* cur;
        teamNo--;
        
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
        cout << "Warning: The team you want to remove does not exist!" << endl;
}

// displays all teams in the registers
void BasketReg::displayAllTeams() {
    if (head == NULL)
        cout << "--EMPTY--" << endl;
    else
        for (Node* cur = head; cur != NULL; cur = cur->next)
            cout << cur->t.getTeamName() + ", " + cur->t.getTeamColor() << endl;
}

// adds a player to the selected team with its position
void BasketReg::addPlayer(string teamName, string playerName, string playerPosition) {
    Node* index = findTeam(teamName);
    
    if (index != NULL)
        index->t.addPlayer(playerName, playerPosition);
    
    else
        cout << "Warning: The team does not exist!" << endl;
}

// removes the selected player from the selected team
void BasketReg::removePlayer(string teamName, string playerName) {
    Node* index = findTeam(teamName);
    
    if (index != NULL)
        index->t.removePlayer(playerName);
    
    else
        cout << "Warning: The team does not exist!" << endl;
}

// display detailed info about the selected team
void BasketReg::displayTeam(string teamName) {
    Node* index = findTeam(teamName);
    
    if (index != NULL) {
        cout << index->t.getTeamName() + ", " + index->t.getTeamColor() << endl;
        index->t.getPlayers();
    }
    else
        cout << teamName + "\n--EMPTY--" << endl;
}

// display detailed info about the selected player
void BasketReg::displayPlayer(string playerName) {
    bool exists = false;
    cout << playerName << endl;
    
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        if (cur->t.getPlayer(playerName)) {
            cout << ", " + cur->t.getTeamName() + ", " + cur->t.getTeamColor() << endl;
            exists = true;
        }
    }
    
    if (!exists)
        cout << "--EMPTY--" << endl;
}

// finds the selected team and returns it's index
BasketReg::Node* BasketReg::findTeam(string teamName) {
    transform(teamName.begin(), teamName.end(), teamName.begin(), ::tolower);
    
    for(Node* cur = head; cur != NULL; cur = cur->next) {
        string tmp = cur->t.getTeamName();
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        
        if (tmp == teamName)
            return cur;
    }
    return NULL;
}
