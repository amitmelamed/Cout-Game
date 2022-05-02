//
// Created by lucas on 02/05/2022.
//
#include "Player.hpp"
#include "Game.hpp"
#include "enums_header.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
namespace coup{
    /**
     * Constructor get current game and name
     * if the game have already started or even finished throw error
     * @param game
     * @param name
     */
    Player::Player(Game & game, string name) {
        this->name=name;
        this->game=&game;
        coinsCount=0;
        this->alive= true;
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
        if(game->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        cout<<"income\n";
        coinsCount++;
        game->nextTurn();
    }

    /**
     * increase coins by 2.
     * can be blocked.
     */
    void Player::foreign_aid() {
        if(game->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        cout<<"foreign aid\n";
        coinsCount+=2;
        game->nextTurn();
    }
    /**
     * Eliminate other player
     * can be done by pay 7 coins.
     */
    void Player::coup(Player & rival) {
        if(game->currentPlayerTurn()!= this){
            throw runtime_error("not player turn\n");
        }
        cout<<"regular coup\n";
        if(coinsCount>7){
            coinsCount-=7;
            game->killPlayer(&rival);
        } else {
            throw runtime_error("Coup require 7 coins\n");
        }
        game->nextTurn();
    }

}
