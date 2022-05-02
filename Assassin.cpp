//
// Created by lucas on 27/04/2022.
//
#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    Assassin::Assassin(Game &game, string name) : Player(game,name){
        setRole(assassin);
    }
    void Assassin::coup(Player &rival)  {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }

        if(coins()>3){
            setCoins(coins()-3);
            getGame()->killPlayer(&rival);
        } else {
            throw runtime_error("Coup require 7 coins\n");
        }
        getGame()->nextTurn();
    }
}
