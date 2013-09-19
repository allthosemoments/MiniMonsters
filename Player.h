#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Deck.h"

class Player
{
	private:
		int life;
		int score;
	public:
		Player()
		{
			life = 0;
			score = 0;
		}
		Player( int li )
		{
			life = li;
			score = 0;
			deck.loadPlayerDeck();
		}
		Deck deck;
		Deck hand;
		Deck limbo;
		Deck graveyard;

		// getters
		int getLife()  { return life; }
		int getScore() { return score; }

};

#endif