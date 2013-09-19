#include <iostream>

#include "Deck.h"
#include "Game.h"
#include "Player.h"
using namespace std;

Game::Game()
{
	cout << "How many players for this game?" << endl;
	int playerCount = requestNumber(1, 4);
	cout << "playerCount - " << playerCount << endl;

	cout << "Pick a difficulty level: 1, 2, or 3." << endl;
	int difficulty = requestNumber(1, 3);
	cout << "difficulty - " << difficulty << endl;

	Player players[ 4 ];
	mainDeck.loadMainDeck();
	villains.loadVillainDeck();

	for( int i = 0; i < playerCount; i++ )
		players[i] = Player( difficultyToLife(difficulty) );

	for( int i = 0; i < playerCount; i++ )
	{
		cout << " Player" << i + 1 << ", life: " << players[i].getLife();
	}

	char in;
	cin >> in;
}