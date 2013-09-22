#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "Deck.h"
#include "Stadium.h"
#include "Player.h"

using namespace std;

const int HAND_SIZE = 5;
const int RIVER_SIZE = 5;

class Game
{
	public:
		Game() {};
		~Game() {};
		Deck mainDeck;
		Deck mainDiscard;
		Deck river;
		Deck villains;

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
				// pre-turn setup
				bool turnEnd = false;
				if(mainDeck.size() > RIVER_SIZE)
				{
					river.draw( RIVER_SIZE, &mainDeck );
				}
				else
				{
					int difference = RIVER_SIZE - mainDeck.size();
					mainDeck.discardAll( &river );
					mainDiscard.discardAll( &mainDeck );
					mainDeck.shuffle();
					river.draw( difference, &mainDeck );
				}
				Player* currentPlayer = &players[ playerTurn ];
				if(currentPlayer->deck.size() >= HAND_SIZE)
				{
					currentPlayer->hand.draw( HAND_SIZE, &currentPlayer->deck );
				}
				else
				{
					int difference = HAND_SIZE - currentPlayer->deck.size();
					currentPlayer->deck.discardAll( &currentPlayer->hand );
					currentPlayer->graveyard.discardAll( &currentPlayer->deck );
					currentPlayer->deck.shuffle();
					currentPlayer->hand.draw( difference, &currentPlayer->deck );
				}

				// actions during a player's turn
				while( !turnEnd )
				{
					cout << "Player" << playerTurn + 1 << " ";
					currentPlayer->printInfo();
					cout << endl;
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
					case '6': startFight( currentPlayer ); break;
					case '7': cout << "---- Empty method ----" << endl; break;
					case '0': gameEnd = true;
					case '8': turnEnd = true; break;
					case 'A': mainDeck.print(); break;
					case 'B': players[ playerTurn ].deck.print(); break;
					case 'C': villains.print();
					case 'D': mainDiscard.print(); break;
					case 'E':
						cout << "Player" << playerTurn + 1 << ", "; 
						currentPlayer->printInfo(); cout << endl << endl;
						break;
					}
				}
				// post-turn cleanup
				river.discardAll( &mainDiscard );
				currentPlayer->hand.discardAll( &currentPlayer->graveyard );
				currentPlayer->limbo.discardAll( &currentPlayer->graveyard );
				playerTurn = ( playerTurn + 1 ) % playerCount;
			}
		}

		// ----------------
		// gameplay methods
		// ----------------
		void startFight( Player* p )
		{
			cout << "Pick the card you wish to target." << endl;
			river.printNumberList();
			int targetIndex = requestNumber(1, river.size());

			Deck target;
			target.add(river.takeByIndex( targetIndex ));

			cout << "Pick a card to play, or enter 0 to return to the menu." << endl;
			Deck inPlay;
			bool quit = false;
			while(!quit && inPlay.sumAttack() < target.peek(0).getDefense())
			{
				p->hand.printNumberList();
				int playIndex = requestNumber(0, p->hand.size() );

				if
					(playIndex == 0) quit = true;
				else
					inPlay.add( p->hand.takeByIndex(playIndex));
			}

			if(quit) 
			{
				inPlay.discardAll( &p->hand );
			}
			else
			{
				inPlay.discardAll( &p->limbo );
				p->graveyard.add( target.takeByIndex( 0 ) );
			}
		}

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
				"````````````````````````````````" << endl <<
				"1. View Hand            A. Main Deck" << endl <<
				"2. View River           B. Player Deck" << endl <<
				"3. View Villain         C. Villain Deck" << endl <<
				"4. View Limbo           D. MainDiscard" << endl <<
				"5. View Graveyard       E. Player Info" << endl <<
				"6. Target River" << endl <<
				"7. Target Villain" << endl << 
				"8. End Turn" << endl << endl <<
				"0. Quit Game" << endl;
		}

};

#endif
