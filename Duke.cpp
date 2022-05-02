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
        setRole(duke);
    }
    void Duke::tax() {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        cout<<"tax by duke\n";
        getGame()->nextTurn();
    }
    void Duke::block(Player player) {
        cout<<"block "<<player.getName()<<"\n";
    }

}