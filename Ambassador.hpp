//
// Created by lucas on 26/04/2022.
//

#pragma once

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace coup{
    class Ambassador:public Player{
    public:
        Ambassador(Game &game,string name);
        void transfer(Player from, Player to);
        void block(Player player);
    };
}