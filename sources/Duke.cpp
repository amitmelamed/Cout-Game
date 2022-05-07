//
// Created by lucas on 27/04/2022.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Duke.hpp"
#include "Game.hpp"
#include "../enums_header.hpp"


using namespace std;

const int mustCoup=10;

namespace coup{
    Duke::Duke(Game &game, string name) : Player(game,std::move(name)){
        setRole(duke);
    }
    void Duke::tax() {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        if(coins()>=mustCoup){
            throw runtime_error("Player must coup with 10 or more coins");
        }
        cout<<"tax by duke\n";
        this->setCoins(this->coins()+3);
        getGame()->nextTurn();
        Play thisPlay(false, *this,Duke_tax);
        getGame()->pushNextPlay(thisPlay);
    }
    void Duke::block(Player &player) {

        vector<Play> lastRound= this->getGame()->getLastRound();

        for (size_t i = 0; i < lastRound.size(); ++i) {
            if(lastRound.at(i).play==Foreign_aid && lastRound.at(i).playedBy==&player){
                player.setCoins(player.coins()-2);
                cout<<"block "<<player.getName()<<"\n";
                return;
            }
        }





        throw runtime_error("Duke can block only foreign aid\n");



    }

}