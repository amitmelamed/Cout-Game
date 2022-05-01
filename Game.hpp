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
        //-----variables-----
        vector<Player*> playersList;
        bool gameEnd;
        bool gameLive;
        Player *playerTurn;
        size_t amountOfPlayers;


    public:
        //-----constructors-----
        Game();

        //-----getters and setters-----
        vector<Player*> getPlayersList;
        void increasePlayers();

        //-----functions-----
        vector<string> players();
        string turn();
        string winner();
        void addPlayer(Player *player);
        void removePlayer(Player *player);
        void increaseTurn();

    };
}