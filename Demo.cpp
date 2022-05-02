/**
 * Demo program for Coup exercise
 *
 * @author: Tal Zichlinsky
 * @since: 2022-02
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {

	Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();

	/*
		prints:
		Moshe
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for(string name : players){
		cout << name << endl;
	}

	// prints Moshe
	cout << game_1.turn() << endl;

	// throws no exceptions
    for (int i = 0; i < 50; ++i) {
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }
    duke.coup(assassin);
    ambassador.coup(captain);
    contessa.coup(duke);
    ambassador.coup(contessa);



    vector<string> s=game_1.players();

    for (size_t i = 0; i < s.size(); ++i) {
        cout<<s.at(i)<<endl;
    }

}

