//
// Created by lucas on 27/04/2022.
//
#include "Contessa.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    Contessa::Contessa(Game &game, string name): Player(game,name) {
        setRole(contessa);

    }
    void Contessa::block(Player player) {
        cout<<"block "<<player.getName()<<"\n";
    }
}
