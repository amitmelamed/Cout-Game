//
// Created by lucas on 26/04/2022.
//

#pragma once

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

#include <vector>
using namespace std;
namespace coup{
    class Captain:public Player{
    public:
        Captain(Game &game,string name);
        void steal(Player &player);
        void block(Player &player);

    };
}