#include <iostream>

#include "Deck.h"
#include "Game.h"
using namespace std;

Game::Game()
{
	cout << "How many players for this game?" << endl;
	int playerCount = requestNumber(1, 4);
	cout << "playerCount - " << playerCount << endl;

	cout << "Pick a difficulty level: 1, 2, or 3." << endl;
	int difficulty = requestNumber(1, 3);
	cout << "difficulty - " << difficulty << endl;

	int players[ 4 ];
	mainDeck.loadMainDeck();
	villains.loadVillainDeck();
}