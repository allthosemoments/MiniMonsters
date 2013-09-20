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
				Player* currentPlayer = &players[ playerTurn ];
				currentPlayer->hand.draw( 5, &currentPlayer->deck );

				// actions during a player's turn
				while( !turnEnd )
				{
					printDebugMenu();
					cout << " -> ";

					char command;
					cin >> command;
					switch( command )
					{
					case '1': currentPlayer->hand.print(); break;
					case '2': river.print(); break;
					case '3': villains.peek(0).print(); break;
					case '4': currentPlayer->limbo.print(); break;
					case '5': currentPlayer->graveyard.print(); break;
					case '6':
					case '7': cout << "Empty method." << endl << endl;
					case '0': gameEnd = true;
					case '8': turnEnd = true; break;
					case 'A': mainDeck.print(); break;
					case 'B': players[ playerTurn ].deck.print(); break;
					case 'C': villains.print();
					case 'D':
						cout << "Player" << playerTurn + 1 << ", "; 
						currentPlayer->printInfo(); cout << endl << endl;
						break;
					}
				}

				// post-turn wrap-up
				currentPlayer->hand.discardAll( &currentPlayer->graveyard );
				playerTurn = ( playerTurn + 1 ) % playerCount;
			}
		}

		// --------
		// debugging
		// --------
		void printDebugMenu()
		{
			cout << "Menu               Debug" << endl << 
				"````````````````````````````````" << endl <<
				"1. View Hand            A. Main Deck" << endl <<
				"2. View River           B. Player Deck" << endl <<
				"3. View Villain         C. Villain Deck" << endl <<
				"4. View Limbo           D. Player Info" << endl <<
				"5. View Graveyard" << endl <<
				"6. Target River" << endl <<
				"7. Target Villain" << endl << 
				"8. End Turn" << endl << endl <<
				"0. Quit Game" << endl;
		}

};

#endif