//
// Created by lucas on 02/05/2022.
//

#ifndef COUT_GAME_PLAYER_HPP
#define COUT_GAME_PLAYER_HPP

#include <iostream>
#include "enums_header.hpp"


using namespace std;
namespace coup{
    //Define game class
    class Game;
    /**
     * The player class represent a player in the current Game.
     * each player have Name.
     * each Player have pointer to his Current Game.
     * each Player have amount of coins.
     * Players have 5 different Roles:Ambassador,Assassin,Captain,Contessa and Duke
     */
    class Player{
    private:
        // -----Variables-----
        string name;
        Game *game;
        int coinsCount;
        Roles currentRole;
        bool alive;
    public:
        // -----Constructors-----
        Player(Game &,string);

        // -----Getters-----
        bool isAlive();
        string getName() const;
        string role() const;
        int coins() const;
        Game* getGame() const;

        // -----Setters-----
        void setRole(Roles);
        void setCoins(int);


        //-----Actions-----
        //Income action-get one coin-Cannot be blocked.
        void income();
        //foreign_aid-get two coins-Can be blocked by Duke.
        void foreign_aid();
        //Coup another player. Cost 7 coins. Cannot be blocked.
        virtual void coup(Player&);
    };
}


#endif //COUT_GAME_PLAYER_HPP
