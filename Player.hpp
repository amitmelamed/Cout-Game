//
// Created by lucas on 02/05/2022.
//

#ifndef COUT_GAME_PLAYER_HPP
#define COUT_GAME_PLAYER_HPP

#include <iostream>
#include "enums_header.hpp"


using namespace std;
namespace coup{
    class Game;
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
        void income();
        void foreign_aid();
        virtual void coup(Player&);
    };
}


#endif //COUT_GAME_PLAYER_HPP
