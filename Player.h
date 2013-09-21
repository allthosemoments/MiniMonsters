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
		Deck deck;
		Deck hand;
		Deck limbo;
		Deck graveyard;
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
		~Player() { }

		// getters
		int getLife()  { return life; }
		int getScore() { return score; }

		// setters
		void burn( int n ) { life -= n; }
		void heal( int n ) { life += n; }

		// printers
		void printInfo()
		{
			std::cout << "Life: " << life << ", Score: " << score << endl; 
		}

};

#endif
