//
// Created by lucas on 26/04/2022.
//

#pragma once

#include "Player.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace coup{
    class Duke:public Player{
    public:
        Duke(Game &game,string name);
        void tax();
        void block(Player &player);
    };
}