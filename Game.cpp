#include <iostream>

#include "Deck.h"
#include "Game.h"
#include "Player.h"
using namespace std;

Game::Game()
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
		while( !turnEnd )
		{
			printDebugMenu();
			cout << " -> ";

			river.draw( 5, &mainDeck );

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