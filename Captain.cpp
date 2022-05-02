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
        setRole(captain);
    }
    void Captain::steal(Player player) {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        cout<<"steal from "<<player.getName()<<"\n";
        getGame()->nextTurn();
    }

    void Captain::block(Player player) {
        cout<<"block "<<player.getName()<<"\n";
    }
}
