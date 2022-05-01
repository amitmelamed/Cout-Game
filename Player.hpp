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

    private:
        //-----variables-----
        int coinsCount;
        string name;
        string playerRole;
    protected:
    public:
        Game *game;
        //-----constructors-----
        Player(Game &game,string name);

        //-----getters and setters-----
        string role();
        int getCoinsCount();
        string coins();
        string getName();
        void setRole(string role);
        void setCoins(int num);
        void setName(string name);

        //-----Actions-----
        void income();
        void foreign_aid();
        void coup(Player rival);

    };
}
