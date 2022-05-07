//
// Created by lucas on 02/05/2022.
//

#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <bits/stdc++.h>


using namespace coup;
using namespace std;


const int maxPlayers=6;
const int minPlayers=2;

namespace coup{
    /**
     * Constructor for play class
     * @param canBeBlocked
     * @param playedBy
     * @param playType
     */
    Play::Play(bool canBeBlocked, Player &playedBy, PlayList playType) {
        this->canBeBlocked=canBeBlocked;
        this->playedBy=&playedBy;
        this->play=playType;
        this->playedOn= nullptr;
    }
    Play::Play(bool canBeBlocked, Player &playedBy, PlayList playType, Player &playedOn) {
        this->canBeBlocked=canBeBlocked;
        this->playedBy=&playedBy;
        this->play=playType;
        this->playedOn= &playedOn;
    }
    /**
     * Constructor set game state to PREGAME
     * set currentPlayer to nullptr which is default and will be change in the first player added.
     */
    Game::Game() {
        gameState=PreGame;
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
     * return The last play info.
     * @return
     */
    Play Game::getLastPlay() {
        return playList.at(playList.size()-1);
    }

    GameState Game::getGameState() {
        return gameState;
    }

    vector<Play> Game::getLastRound() {
        vector<Play> lastRound;
        if(playList.size()<onlinePlayers.size()){
            return playList;
        }
        for (size_t i = 0; i < onlinePlayers.size(); ++i) {
            lastRound.push_back(this->playList.at(playList.size()-1-i));
        }
        return lastRound;
    }


    /**
     *
     * @param state
     */
    void Game::setGameState(GameState state) {
        if((state==Live && onlinePlayers.size()<minPlayers) || (state==Live && onlinePlayers.size()>maxPlayers)){
            throw runtime_error("Game can be played with only 2-6 players.");
        }
        gameState=state;
    }

    void Game::pushNextPlay(Play play) {
        playList.push_back(play);
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
        if(onlinePlayers.size()>=maxPlayers){
            throw runtime_error("Cannot add more players. limit is 6");
        }
        if(onlinePlayers.empty()) {
            currentPlayer = player;
        }
        onlinePlayers.push_back(player);
        player->indexAtOnlinePlayers=(int )onlinePlayers.size()-1;
    }

    void Game::revivePlayer(Player * player) {
        onlinePlayers.insert(onlinePlayers.begin()+player->indexAtOnlinePlayers,player);
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
     * Kills player.
     * Happens after LEGAL coup action.
     */
    void Game::killPlayer(Player * p) {
        bool flag= false;
        for (size_t i = 0; i < onlinePlayers.size(); ++i) {
            if(onlinePlayers.at(i)==p){
                flag= true;
            }
        }
        if(!flag){
            throw runtime_error("player not found\n");
        }
        onlinePlayers.erase(find(onlinePlayers.begin(),onlinePlayers.end(),p));
        if(onlinePlayers.size()==1){
            setGameState(Finished);
            currentGameWinner=onlinePlayers.at(0);
        }
    }
}