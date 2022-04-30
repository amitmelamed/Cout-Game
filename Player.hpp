//
// Created by lucas on 26/04/2022.
//
#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Game.hpp"

using namespace std;

namespace coup{

    /**
     * The player class represent player in the game.
     * each players have amount od coins.
     * each player have a name and Role.
     */
    class Game;
    class Player{

    protected:
        Game *game;
        int coinsCount;
        string name;
        string playerRole;
    public:
        string getName();
        Player(Game &game,string name);
        void income();
        void foreign_aid();
        void coup(Player rival);
        string role();
        string coins();
    };
}
