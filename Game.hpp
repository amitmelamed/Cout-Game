//
// Created by lucas on 02/05/2022.
//

#ifndef COUT_GAME_GAME_HPP
#define COUT_GAME_GAME_HPP

#include <vector>
#include "Player.hpp"
#include "enums_header.hpp"

using namespace std;
namespace coup{
    class Game{
        // -----Variables-----
        vector<Player*> onlinePlayers;
        Player *currentPlayer;
        GameState gameState;
        Player *currentGameWinner;

    public:
        // -----Constructors-----
        Game();

        // -----Getters-----
        vector<string> players() const;
        string turn() const;
        string winner() const;
        Player *currentPlayerTurn();

        // -----Setters-----
        void setGameState(GameState state);

        // -----Actions-----
        void addPlayer(Player *);
        void nextTurn();
        void killPlayer(Player *);
    };
}
#endif //COUT_GAME_GAME_HPP
