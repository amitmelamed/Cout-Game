//
// Created by lucas on 27/04/2022.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Duke.hpp"

using namespace std;

namespace coup{
    Duke::Duke(Game &game, string name) : Player(game,name){
        setRole("Duke");
    }
    void Duke::tax() {
        cout<<"tax by duke\n";
    }
    void Duke::block(Player player) {
        cout<<"block "<<player.getName()<<"\n";
    }

}