//
// Created by lucas on 27/04/2022.
//
#include "Assassin.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    Assassin::Assassin(Game &game, string name) : Player(game,name){
        this->setRole("Assassin");
    }
    void Assassin::coup(Player rival) {
        if(getCoinsCount()<3){
            throw std::invalid_argument("assassins coup require 3 coins");
        }
    }
}
