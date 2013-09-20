#ifndef STADIUM_H
#define STADIUM_H

#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"

using namespace std;

class Stadium
{
	private:
		Deck inplay;
	public:
		Stadium() {};
		~Stadium() {};

	// --------
	// launch the battle
	// --------
	void startFight( Player p, int n, Deck d )
	{
		cout << endl << 
			"inside the battle method" << endl << endl;
	}
};

#endif
