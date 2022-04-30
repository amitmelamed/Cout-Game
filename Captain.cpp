//
// Created by lucas on 27/04/2022.
//
#include "Captain.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace coup{
    Captain::Captain(Game &game, string name) : Player(game,name){
        playerRole="Captain";
    }
    void Captain::steal(Player player) {
        cout<<"steal from "<<player.getName()<<"\n";

    }

    void Captain::block(Player player) {
        cout<<"block "<<player.getName()<<"\n";
    }
}
