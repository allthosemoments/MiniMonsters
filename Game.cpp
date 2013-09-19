#include <iostream>

#include "Deck.h"
#include "Game.h"
using namespace std;

Game::Game()
{
	//int players[];
	mainDeck.loadMainDeck();
	villains.loadVillainDeck();

	villains.print();

	cout << "inside the game";

	char in;
	cin >> in;
}