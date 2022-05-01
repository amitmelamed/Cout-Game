//
// Created by lucas on 26/04/2022.
//

#pragma once

#include "Player.hpp"
#include "Duke.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;
namespace coup{
    class Assassin:public Player{
    public:
        Assassin(Game &game,string name);
        void coup(Player rival);
    };
}