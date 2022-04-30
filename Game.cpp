//
// Created by lucas on 27/04/2022.
//
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;
namespace coup{
    Game::Game() {
    }
    vector<string> Game::players() {
        vector <string> names;
        for(size_t i=0;i<playersList.size();i++){
            names.push_back(playersList.at(i)->getName());
        }
        return names;
    }
    string Game::turn() {
        return "not done\n";
    }
    string Game::winner() {
        return "not done\n";
    }

    void Game::addPlayer(Player *newPlayer) {
        playersList.push_back(newPlayer);
    }
}
