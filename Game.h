#ifndef GAME_H
#define GAME_H

#include <iostream>

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

		// ----------------
		// gameplay setup
		// ----------------
		int requestNumber( int floor, int ceiling )
		{
			bool inRange = false;
			int n = 0;
			while( !inRange )
			{
				cout << " -> ";

				char in;
				cin >> in;
				
				n = in - 48;
				if( n >= floor && n <= ceiling ) inRange = true;
			}
			return n;
		}

		int difficultyToLife( int d )
		{
			int n = 0;
			switch ( d )
			{
			case 1: n = 20; break;
			case 2: n = 16; break;
			case 3: n = 8; break;
			default: cout << "ERROR"; n = 0; break;
			}
			return n;
		}

		// --------
		// debugging
		// --------
		void printDebugMenu()
		{
			cout << "Menu               Debug" << endl << 
				"````````````````````````" << endl <<
				"1. Player Hand     A. Main Deck" << endl <<
				"2. The River       B. Player Deck" << endl <<
				"3. Graveyard       C. Villain Deck" << endl;
		}

};

#endif