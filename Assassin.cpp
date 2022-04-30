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
        playerRole="Assassin";
    }
    void Assassin::coup(Player player) {
        cout<<"assassin coup "<<player.getName()<<"n";
    }
}
