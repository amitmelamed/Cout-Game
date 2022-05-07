//
// Created by lucas on 27/04/2022.
//
#include "Captain.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

const int mustCoup=10;

namespace coup{
    Captain::Captain(Game &game, string name) : Player(game,std::move(name)){
        setRole(captain);
    }
    void Captain::steal(Player &player) {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        if(coins()>=mustCoup){
            throw runtime_error("Player must coup with 10 or more coins");
        }
        cout<<"steal from "<<player.getName()<<"\n";
        if(player.coins()==0){
            getGame()->nextTurn();

            Play thisPlay(true, *this,Captain_steal,player);
            getGame()->pushNextPlay(thisPlay);
            return;
        }
        if(player.coins()==1){
            player.setCoins(player.coins()-1);
            this->setCoins(this->coins()+1);
            getGame()->nextTurn();

            Play thisPlay(true, *this,Captain_steal,player);
            getGame()->pushNextPlay(thisPlay);
            return;
        }
        player.setCoins(player.coins()-2);
        this->setCoins(this->coins()+2);

        getGame()->nextTurn();

        Play thisPlay(true, *this,Captain_steal,player);
        getGame()->pushNextPlay(thisPlay);
    }

    void Captain::block(Player &player) {

        vector<Play> lastRound= this->getGame()->getLastRound();

        for (size_t i = 0; i < lastRound.size(); ++i) {
            if(lastRound.at(i).play==Captain_steal && lastRound.at(i).playedBy==&player){
                lastRound.at(i).playedBy->setCoins(lastRound.at(i).playedBy->coins()-2);
                lastRound.at(i).playedOn->setCoins(lastRound.at(i).playedOn->coins()+2);

                cout<<"block "<<player.getName()<<"\n";
                return;
            }
        }
        throw runtime_error("Capitan can block only Captain steal\n");
    }
}
