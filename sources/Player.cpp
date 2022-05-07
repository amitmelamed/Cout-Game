//
// Created by lucas on 02/05/2022.
//
#include "Player.hpp"
#include "Game.hpp"
#include "../enums_header.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>


using namespace std;

int const seven=7;
int const ten=10;

namespace coup{
    /**
     * Constructor get current game and name
     * if the game have already started or even finished throw error
     * @param game
     * @param name
     */
    Player::Player(Game & game, string playerName) {
        this->name=move(playerName);
        this->game=&game;
        coinsCount=0;
        this->alive= true;
        currentRole= null_player;
        indexAtOnlinePlayers= -1;
        game.addPlayer(this);
    }

    /**
     * Getters
     * get Name,role coins and game
     */
    string Player::getName() const {
        return name;
    }

    string Player::role() const {
        switch (currentRole)
        {
            case ambassador:   return "Ambassador";
            case assassin:   return "Assassin";
            case duke: return "Duke";
            case captain: return "Captain";
            case contessa: return "Contessa";
            default:      return "undefined role";
        }
    }

    int Player::coins() const {
        return coinsCount;
    }

    Game *Player::getGame() const {
        return game;
    }
    /**
     * Setters:
     * setRole
     */

    void Player::setRole(Roles r) {
        this->currentRole=r;
    }

    void Player::setCoins(int num) {
        this->coinsCount=num;
    }

    /**
     * Increase coins by 1.
     * cannot be blocked.
     */
    void Player::income() {
        if(game->getGameState()==PreGame){
            game->setGameState(Live);
        }

        if(game->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }

        if(coins()>=ten){
            throw runtime_error("Player must coup with 10 or more coins");
        }

        if(game->onlinePlayers.size()<=1){
            throw runtime_error("only one player live");
        }

        coinsCount++;
        game->nextTurn();

        Play thisPlay(false, *this,Income);
        getGame()->pushNextPlay(thisPlay);


    }

    /**
     * increase coins by 2.
     * can be blocked.
     */
    void Player::foreign_aid() {
        if(game->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        if(coins()>=ten){
            throw runtime_error("Player must coup with 10 or more coins");
        }

        if(game->onlinePlayers.size()<=1){
            throw runtime_error("only one player live");
        }

        coinsCount+=2;
        game->nextTurn();

        Play thisPlay(true, *this,Foreign_aid);
        getGame()->pushNextPlay(thisPlay);
    }
    /**
     * Eliminate other player
     * can be done by pay 7 coins.
     */
    void Player::coup(Player & rival) {
        if(game->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        bool rivalExist= false;
        for (size_t i = 0; i < game->onlinePlayers.size(); ++i) {
            if(game->onlinePlayers.at(i)==&rival) {
                rivalExist = true;
            }
        }
        if(!rivalExist) {
            throw runtime_error("rival not exist\n");
        }

        if(coinsCount>=seven){
            coinsCount-=seven;
            game->killPlayer(&rival);
        } else {
            throw runtime_error("Coup require 7 coins\n");
        }
        game->nextTurn();

        Play thisPlay(false, *this,Coup,rival);
        getGame()->pushNextPlay(thisPlay);
    }

}
