//
// Created by lucas on 27/04/2022.
//
#include "Contessa.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    Contessa::Contessa(Game &game, string name): Player(game,std::move(name)) {
        setRole(contessa);

    }
    void Contessa::block(Player &player) {
        vector<Play> lastRound= this->getGame()->getLastRound();

        for (size_t i = 0; i < lastRound.size(); ++i) {
            if(lastRound.at(i).play==Assassin_coup && lastRound.at(i).playedBy==&player){
                getGame()->revivePlayer(lastRound.at(i).playedOn);
                cout<<"block "<<player.getName()<<"\n";
                return;
            }
        }
        throw runtime_error("Contessa can block only Assassin coup\n");

    }
}
