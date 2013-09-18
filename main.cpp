#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"

using namespace std;

int main()
{
	cout << "Hello darkness my old friend" << endl << endl;
	char c;

	Deck mainDeck;
	mainDeck.loadMainDeck();

	Deck playerOne;
	playerOne.loadPlayerDeck();
	playerOne.print();

	Deck villains;
	villains.loadVillainDeck();
	villains.print();

	cin >> c;
	return 0;
}