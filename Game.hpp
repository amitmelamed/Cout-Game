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
    /**
     * The Game class represent A Live Coup Game.
     * To use The Game, First Build a Game object.
     * Then add Players to it by creating Players objects using our Game in their Constructor.
     * after adding all The Players, Begin to play by playing the first player turn.
     * after The Game has started we will not be able to add any Players.
     * After The Players Coup each other and One remain, he will be Winner and the Game will end.
     *
     * Online Players-Represent All the Live Players(by pointing to them).
     * Current Player-Pointer to Players turn.
     * GameState-represent the current Game situation:PreGame,Live or finished.
     * currentGameWinner-Pointer to the Last Man Standing.
     */

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
