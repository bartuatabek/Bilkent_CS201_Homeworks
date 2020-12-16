//
//  Player.cpp
//  CS 201 HW#3
//
//  Created by Bartu Atabek on 12/3/17.
//  Copyright © 2017 Bartu Atabek. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Player.h"

// default constructor
Player::Player() :playerName(""), position("") {
}

// optional constructor
Player::Player(string playerName, string position) {
    setPlayerName(playerName);
    setPosition(position);
}

// copy constructor
Player::Player(const Player &playerToCopy) :playerName(playerToCopy.playerName), position(playerToCopy.position){
}

// overloaded assignment operator
void Player::operator=(const Player &right) {
    if (&right != this) {
        playerName = right.playerName;
        position = right.position;
    }
}

// returns player name
string Player::getPlayerName() {
    return playerName;
}

// returns players position
string Player::getPosition() {
    return position;
}

// sets the player's name
void Player::setPlayerName(string playerName) {
    this->playerName = playerName;
}

// sets the player's position
void Player::setPosition(string position) {
    this->position = position;
}
