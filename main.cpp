#include <iostream>
#include <string>

#include "Deck.h"
#include "Game.h"
#include "Menu.h"

using namespace std;

int gameStart( int playerCount )
{
	Game game;
	return 0;
}

int main()
{
	printLogo();

	bool run = true;
	while ( run )
	{
		printMenu();

		char command;
		cin >> command;
		switch( command )
		{
		case '1': printGamePrompt();
			int pc; cin >> pc; 
			gameStart( pc ); break;
		case '2': printStory(); break;
		case '3': printInstructions(); break;
		case '4': printAbout(); break;
		case '0': run = false; break;
		}
	}
	return 0;
}