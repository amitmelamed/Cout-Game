//
// Created by lucas on 27/04/2022.
//
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Player.hpp"

using namespace std;
namespace coup{
    /**
     * Constructor
     * get current game
     * get Name
     * set coins to 0
     * called from inherited constructor that use setRole also
     * @param game
     * @param name
     */
    Player::Player(Game & game, string name) {
        this->setName(name);
        this->setCoins(0);
        game.addPlayer(this);
        game.increasePlayers();
    }

    /**
     * getters and setters
     */
    void Player::setCoins(int num) {
        this->coinsCount=num;
    }
    void Player::setRole(string role) {
        this->playerRole=role;
    }
    void Player::setName(string name) {
        this->name=name;
    }
    string Player::role() {
        return playerRole;
    }
    string Player::getName() {
        return name;
    }
    int Player::getCoinsCount() {
        return coinsCount;
    }
    string Player::coins() {
        string s = std::to_string(coinsCount);
        return s;
    }

    /**
     * Coup action uses 7 coins.
     * Coup kills the rival.
     * Coup action can be block by several roles.
     * @param rival
     */
    void Player::coup(Player rival) {
        if(getCoinsCount()<7){
            throw std::invalid_argument("coup require 7 coins");
        }
        game->increaseTurn();
    }
    /**
     * Income action increase the coins count by One.
     */
    void Player::income() {
        coinsCount++;
        cout<<"income\n";




    }
    /**
     * Foreign Aid increase the coins count by Two.
     * Can be blocked.
     */
    void Player::foreign_aid() {
        coinsCount+=2;
        cout<<"foreign aid\n";
        game->increaseTurn();

    }


}
