#include <iostream>
#include <string>

#include "Deck.h"
#include "Menu.h"

using namespace std;

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
		case '1': break;
		case '2': break;
		case '3': break;
		case '4': break;
		case '0': run = false; break;
		}
	}
	return 0;
}