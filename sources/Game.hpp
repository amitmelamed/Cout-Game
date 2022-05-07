//
// Created by lucas on 02/05/2022.
//

#ifndef COUT_GAME_GAME_HPP
#define COUT_GAME_GAME_HPP

#include <vector>
#include "Player.hpp"
#include "../enums_header.hpp"

using namespace std;
namespace coup{
    class Play{
    public:
        bool canBeBlocked;
        Player *playedBy;
        PlayList play;
        Player *playedOn;
        Play(bool canBeBlocked,Player& playedBy,PlayList playType,Player& playedOn);
        Play(bool canBeBlocked,Player& playedBy,PlayList playType);
    };
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
        Player *currentPlayer;
        GameState gameState;
        Player *currentGameWinner;
        vector<Play> playList;



    public:
        vector<Player*> onlinePlayers;

        // -----Constructors-----
        Game();

        // -----Getters-----
        vector<string> players() const;
        string turn() const;
        string winner() const;
        Player *currentPlayerTurn();
        Play getLastPlay();
        vector<Play> getLastRound();
        GameState getGameState();

        // -----Setters-----
        void setGameState(GameState state);
        void pushNextPlay(Play);

        // -----Actions-----
        void addPlayer(Player *);
        void nextTurn();
        void killPlayer(Player *);
        void revivePlayer(Player *);
    };
}
#endif //COUT_GAME_GAME_HPP
