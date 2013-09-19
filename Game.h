#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "string"
using namespace std;

class Game
{
	public:
		Game();
		Deck mainDeck;
		Deck mainDiscard;
		Deck river;
		Deck villains;

		// functions

};

#endif