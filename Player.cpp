//
// Created by lucas on 27/04/2022.
//
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup{

    Player::Player(Game & game, string name) {
        this->name=name;
        game.addPlayer(this);
    }

    void Player::coup(Player rival) {
        cout<<"player coup\n";
    }

    string Player::coins() {
        return "no done coins\n";
    }

    void Player::foreign_aid() {
        cout<<"foreign aid\n";

    }

    void Player::income() {
        cout<<"income\n";
    }

    string Player::role() {
        return playerRole;
    }

    string Player::getName() {
        return this->name;
    }

}
