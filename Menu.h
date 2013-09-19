#include <iostream>

using namespace std;

void printLogo()
{
	cout << 
		"    ___   ___      ___   ___" << endl <<
		"   /   | /  /     /   | /  /" << endl <<
		"  /    |/   /    /    |/   /" << endl <<
		" /  /|   /  /   /  /|   /  /" << endl <<
		"/__/ |__/|__/  /__/ |__/|__/" << endl <<
		"Mini Monsters, by Jared Black" << endl;
}

void printMenu()
{
	cout << endl <<
		"1. Start Game" << endl <<
		"2. Storyline" << endl <<
		"3. Instructions" << endl <<
		"4. About" << endl << endl <<
		"0. Exit Game" << endl << endl << 
		"-> ";
}

void printAbout()
{
	cout << endl << "-- About the game. --" << endl << endl;
}

void printInstructions()
{
	cout << endl << 
		"At the beginning of every turn you will draw five cards from your deck. " <<
		"Your " << endl << "deck will initially have only ten cards, but five " << 
		"new cards will be dealt from the " << endl << "main deck each turn, and " <<
		"you can use your hand to add these cards to your discard " << endl << 
		"pile. Once your deck runs out of cards your discard pile will be " << 
		"shuffled and " << endl << "become your new deck." << endl << endl;
	cout << "Be careful though, there are also six villains who do not " << 
		"intend to let you defeat " << endl << "them so easily. They attack at " <<
		"different times, but all of them are ready with " << endl << "attacks " << 
		"that lower your health and add scar cards to your deck. The scar cards " << 
		"will" << endl << "make it harder to get to your better cards or put " << 
		"together combos." << endl << endl;
}

void printStory()
{
	cout << endl << "-- The story of Valencia. --" << endl << endl;
}