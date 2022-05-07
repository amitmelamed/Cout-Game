//
// Created by lucas on 27/04/2022.
//

#include "Ambassador.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

const int mustCoup=10;



namespace coup{

    Ambassador::Ambassador(Game &game, string name) : Player(game,std::move(name)){
        setRole(ambassador);
    }

    void Ambassador::transfer(Player &from, Player &to) {
        if(getGame()->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        if(from.coins()<=0){
            throw runtime_error("cant transfer zero coins\n");

        }
        if(coins()>=mustCoup){
            throw runtime_error("Player must coup with 10 or more coins");
        }
        from.setCoins(from.coins()-1);
        to.setCoins(to.coins()+1);



        cout<<"transfer from "<<from.getName()<<" to"<<to.getName()<<"\n";
        getGame()->nextTurn();

        Play thisPlay(false, *this,Ambassador_transfer);
        getGame()->pushNextPlay(thisPlay);
    }

    void Ambassador::block(Player &player) {
        if(this->getGame()->getLastPlay().play!=Captain_steal){
            throw runtime_error("Ambassador can block only Captain steal\n");
        }
        getGame()->getLastPlay().playedBy->setCoins(getGame()->getLastPlay().playedBy->coins()-2);
        getGame()->getLastPlay().playedOn->setCoins(getGame()->getLastPlay().playedOn->coins()+2);


    }
}