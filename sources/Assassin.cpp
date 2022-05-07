//
// Created by lucas on 27/04/2022.
//
#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

const int seven=7;

namespace coup{
    Assassin::Assassin(Game &game, string name) : Player(game,std::move(name)){
        setRole(assassin);
    }
    void Assassin::coup(Player &rival)  {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }





        bool rivalExist= false;
        for (size_t i = 0; i < getGame()->onlinePlayers.size(); ++i) {
            if(getGame()->onlinePlayers.at(i)==&rival){
                rivalExist= true;
            }
        }
        if(!rivalExist) {
            throw runtime_error("rival not exist\n");
        }



        //if assassins have 7 coins or more he will preform regular unblockable coup
        if(coins()>=seven){
            this->setCoins(coins()-seven);
            getGame()->killPlayer(&rival);
            getGame()->nextTurn();

            Play thisPlay(false, *this,Coup,rival);
            getGame()->pushNextPlay(thisPlay);
            return;

        }

        //case he have less than 7 more than 3
        if(coins()>=3){
            setCoins(coins()-3);
            getGame()->killPlayer(&rival);
        } else {
            throw runtime_error("Assassin Coup require 3 coins\n");
        }
        getGame()->nextTurn();

        Play thisPlay(true, *this,Assassin_coup,rival);
        getGame()->pushNextPlay(thisPlay);
    }
}
