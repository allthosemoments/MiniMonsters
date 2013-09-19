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

	printDebugMenu();
	cout << " -> ";

	char in;
	cin >> in;
}