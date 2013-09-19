#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Deck.h"

class Player
{
	private:
		Player();
		int life;
		int score;
		Deck deck;
		Deck hand;
		Deck limbo;
		Deck graveyard;
public:
	Player( int li )
	{
		life = li;
		score = 0;
		deck.loadPlayerDeck();
	}


}

#endif