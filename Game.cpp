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
    /**
     * Constructor Game
     */
    Game::Game() {
        gameEnd=false;
        gameLive= false;
        playerTurn= nullptr;
    }
    /**
     * players() return vector of strings represents the ALIVE players in the current game
     * @return
     */
    vector<string> Game::players() {
        vector <string> names;
        for(size_t i=0;i<playersList.size();i++){
            names.push_back(playersList.at(i)->getName());
        }
        return names;
    }
    /**
     * returns the current players name that plays.
     * @return
     */
    string Game::turn() {
        return playerTurn->getName();
    }
    /**
     * If the game is Done-return the winner's name
     * @return
     */
    string Game::winner() {
        return "not done\n";
    }

    /**
     * Add new player to the current game.
     * @param newPlayer
     */
    void Game::addPlayer(Player *newPlayer) {
        if(playersList.empty()){
            playerTurn=newPlayer;
        }
        playersList.push_back(newPlayer);
    }


    void Game::increaseTurn() {


    }
    void Game::increasePlayers() {
        amountOfPlayers++;
    }
}
