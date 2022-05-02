//
// Created by lucas on 02/05/2022.
//

#include "Game.hpp"
#include "Player.hpp"

using namespace coup;
using namespace std;

namespace coup{
    /**
     * Constructor set game state to PREGAME
     * set currentPlayer to nullptr which is defult and will be change in the first player added.
     */
    Game::Game() {
        setGameState(PreGame);
        currentPlayer= nullptr;
        currentGameWinner = nullptr;
    }

    /**
    * players() return vector of strings represents the ALIVE players in the current game
    * @return
    */
    vector<string> Game::players() const{
        vector <string> names;
        for(size_t i=0;i<onlinePlayers.size();i++){
            names.push_back(onlinePlayers.at(i)->getName());
        }
        return names;
    }

    /**
     * return the current turn player name
     * @return
     */
    string Game::turn() const {
        return currentPlayer->getName();
    }

    string Game::winner() const {
        if(gameState!=Finished){
            throw runtime_error("Game not finished-There is no WINNER");
        }
        return currentGameWinner->getName();
    }

    /**
     * return the currentPlayer turn
     * @return
     */
    Player *Game::currentPlayerTurn() {
        return currentPlayer;
    }


    /**
     *
     * @param state
     */
    void Game::setGameState(GameState state) {
        gameState=state;
    }

    /**
     * addPlayer adding new player to the game.
     * adding to onlinePlayers vector which contains pointers to the players.
     * if we adding player for the first time we will set first turn to him.
     * players can be added ONLY IN PREGAME.
     * @param player
     */
    void Game::addPlayer(Player* player) {
        if(gameState!=PreGame){
            throw runtime_error("cannot add players while game is run or finished");
        }
        if(onlinePlayers.empty()) {
            currentPlayer = player;
        }
        onlinePlayers.push_back(player);
    }

    /**
     * increase turn, happens after every action of player.
     */
    void Game::nextTurn() {
        if(gameState==PreGame){
            gameState=Live;
        }
        size_t i=0;
        while (currentPlayer!=onlinePlayers.at(i)){
            i++;
        }
        i++;
        i=i%onlinePlayers.size();
        currentPlayer=onlinePlayers.at(i);
    }

    /**
     * kills player.
     * happens after coup action.
     */
    void Game::killPlayer(Player * p) {
        onlinePlayers.erase(find(onlinePlayers.begin(),onlinePlayers.end(),p));
    }
}