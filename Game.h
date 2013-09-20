#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "Deck.h"
#include "Player.h"

using namespace std;

class Game
{
	public:
		Game() {};
		~Game() {};
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
		
		// --------------------------------
		// the main attraction
		// --------------------------------
		void gameplay()
		{
			cout << "How many players for this game? (1 - 4)" << endl;
			int playerCount = requestNumber(1, 4);

			cout << "Pick a difficulty level: 1, 2, or 3." << endl;
			int difficulty = requestNumber(1, 3);

			mainDeck.loadMainDeck();
			villains.loadVillainDeck();

			Player players[4];
			for( int i = 0; i < playerCount; i++ )
				players[i] = Player( difficultyToLife(difficulty) );
			int playerTurn = 0;

			bool gameEnd = false;
			while( !gameEnd )
			{
				bool turnEnd = false;
				river.draw( 5, &mainDeck );
				while( !turnEnd )
				{
					printDebugMenu();
					cout << " -> ";


					char command;
					cin >> command;
					switch( command )
					{
					case '2': river.print(); break;
					case '4': turnEnd = true; break;
					case '0': gameEnd = true; turnEnd = true; break;
					case 'A': mainDeck.print(); break;
					case 'B': players[ playerTurn ].deck.print(); break;
					case 'C': villains.print();
					case 'D':
						cout << "Player" << playerTurn + 1 << ", "; 
						players[ playerTurn ].printInfo(); cout << endl;
						break;
					}
				}
				playerTurn = ( playerTurn + 1 ) % playerCount;
			}
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
				"3. Graveyard       C. Villain Deck" << endl <<
				"4. End Turn        D. Player Info" << endl << endl <<
				"0. Quit Game" << endl;
		}

};

#endif