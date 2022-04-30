//
// Created by lucas on 26/04/2022.
//
#pragma once

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace coup{
    class Contessa:public Player{
    public:
        Contessa(Game &game,string name);
        void block(Player player);

    };
}