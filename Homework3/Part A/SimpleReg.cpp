//
//  SimpleReg.cpp
//  CS 201 HW#3
//
//  Created by Bartu Atabek on 12/1/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "SimpleReg.h"

// Default constructor for creating empty registration system
SimpleReg::SimpleReg() :teamNo(0), head(NULL) {
}

// Adds a new team to the register
void SimpleReg::addTeam(string teamName, string teamColor) {
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

// Removes the identified team from the register
void SimpleReg::removeTeam(string teamName) {
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

// Displays all the registered teams
void SimpleReg::displayAllTeams() {
    if (head == NULL)
        cout << "--EMPTY--" << endl;
    else
        for (Node* cur = head; cur != NULL; cur = cur->next)
            cout << cur->t.getTeamName() + ", " + cur->t.getTeamColor() << endl;
}

// Finds the team and returns its location if it exists
SimpleReg::Node* SimpleReg::findTeam(string teamName) {
    transform(teamName.begin(), teamName.end(), teamName.begin(), ::tolower);
    
    for(Node* cur = head; cur != NULL; cur = cur->next) {
        string tmp = cur->t.getTeamName();
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        
        if (tmp == teamName)
            return cur;
    }
    return NULL;
}
