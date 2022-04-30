//
// Created by lucas on 26/04/2022.
//

#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;
namespace coup{

    class Player;
    class Game{
    public:
        vector<Player*> playersList;
        Game();
        vector<string> players();
        string turn();
        string winner();
        void addPlayer(Player *player);
    };
}