//
// Created by lucas on 27/04/2022.
//

#include "Ambassador.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{

    Ambassador::Ambassador(Game &game, string name) : Player(game,name){
        playerRole="Ambassador";
    }

    void Ambassador::transfer(Player from, Player to) {
        cout<<"transfer from "<<from.getName()<<" to"<<to.getName()<<"\n";
    }

    void Ambassador::block(Player player) {
        cout<<"block "<<player.getName()<<"\n";
    }
}