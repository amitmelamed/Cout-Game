//
// Created by lucas on 27/04/2022.
//

#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"

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
    CHECK_EQ(game_1.turn(),"Moshe");
    duke.income();
    CHECK_EQ(game_1.turn(),"Yossi");
    assassin.income();
    CHECK_EQ(game_1.turn(),"Meirav");
    ambassador.income();
    CHECK_EQ(game_1.turn(),"Reut");
    captain.income();
    CHECK_EQ(game_1.turn(),"Gilad");
    contessa.income();
    //duke turn
    CHECK_THROWS(assassin.income());

    CHECK_EQ(duke.coins(),"1");
    CHECK_EQ(assassin.coins(),"1");
    CHECK_EQ(ambassador.coins(),"1");
    CHECK_EQ(captain.coins(),"1");
    CHECK_EQ(contessa.coins(),"1");

    duke.tax();
    CHECK_EQ(duke.coins(),"4");
    assassin.income();
    ambassador.transfer(duke,assassin);
    CHECK_EQ(duke.coins(),"3");
    CHECK_EQ(assassin.coins(),"3");
    captain.steal(assassin);
    CHECK_EQ(assassin.coins(),"1");
    CHECK_EQ(assassin.coins(),"3");
    contessa.income();
    CHECK_EQ(contessa.coins(),"2");
}
TEST_CASE("Role Check"){
    Game game_1{};


    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    CHECK_EQ(duke.role(),"Duke");
    CHECK_EQ(assassin.role(),"Assassin");
    CHECK_EQ(ambassador.role(),"Ambassador");
    CHECK_EQ(captain.role(),"Captain");
    CHECK_EQ(contessa.role(),"Contessa");
}
