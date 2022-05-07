//
// Created by lucas on 27/04/2022.
//

#include "../doctest.h"
#include "Game.hpp"
#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"

const int nine=9;
using namespace coup;
using namespace std;

TEST_CASE("Basic Game"){
    Game game_1{};

    /* This player drew the "Duke" card, his name is Moshe
    and he is a player in game_1 */
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    vector<string> players = game_1.players();
    CHECK_EQ(players.at(0),"Moshe");
    CHECK_EQ(players.at(1),"Yossi");
    CHECK_EQ(players.at(2),"Meirav");
    CHECK_EQ(players.at(3),"Reut");
    CHECK_EQ(players.at(4),"Gilad");

    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    //duke turn

    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());

    for (int i = 0; i < nine; ++i) {
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }
    CHECK_EQ(duke.coins(),10);
    CHECK_EQ(assassin.coins(),10);
    CHECK_EQ(ambassador.coins(),10);
    CHECK_EQ(captain.coins(),10);
    CHECK_EQ(contessa.coins(),10);

    duke.coup(ambassador);
    assassin.coup(captain);
    CHECK_EQ(game_1.turn(),contessa.getName());
    CHECK_EQ(duke.coins(),3);
}