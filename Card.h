#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;
enum aspect{ SCAR, ARTI, EARTH, WIND, FIRE, WATER, BOLT, LEAF };

class Card
{
	private:
		Card() { };
		string title;
		aspect type;
		int stats[2][3];
		string abilityText;
		string flavorText;
	public:
		Card(string ti, aspect ty, int att, int def, int pts, string ab, string fl)
		{
			title = ti;
			type = ty;
			stats[0][0] = att; stats[1][0] = att;
			stats[0][1] = def; stats[1][1] = def;
			stats[0][2] = pts; stats[1][2] = pts;
			abilityText= ab;
			flavorText = fl;
		}
		~Card() {};

		// operators
		bool operator== (Card oth)
		{
			if ( (getTitle() ) == ( (oth.getTitle()) ) ) return true;
			return false;
		}

		// getters
		string getTitle()    { return title; }
		aspect getType()     { return type; }
		int getAttack()      { return stats[0][0]; }
		int getBaseAttack()  { return stats[1][0]; }
		int getDefense()     { return stats[0][1]; }
		int getBaseDefense() { return stats[1][1]; }
		int getValue()       { return stats[0][2]; }
		string getAbility()  { return abilityText; }
		string getFlavor()   { return flavorText; }

		// setters
		void buffAttack( int b )   { stats[0][0] += b; }
		void buffDefense( int b )  { stats[0][1] += b; }
		void scaleAttack( int s )  { stats[0][0] *= s; }
		void scaleDefense( int s ) { stats[0][1] *= s; }
		void setAttack( int x )    { stats[0][0]  = x; }
		void setDefense( int x )   { stats[0][1]  = x; }
		void resetAD()
		{
			setAttack( getBaseAttack() );
			setDefense( getBaseDefense() );
		}
		
		// printers
		void print()
		{
			cout  << title << " ["; printType(); cout 
				<< "] A:" << stats[0][0] 
				<< " / D:" << stats[0][1] 
				<< " / V:" << stats[0][2] << endl;
			cout << abilityText << endl;
			cout << flavorText << endl;
		}

		void printStats()
		{
			cout << "A:" << stats[0][0] 
				<< " / D:" << stats[0][1] 
				<< " / V:" << stats[0][2];
		}

		void printType()
		{
			switch( type )
			{
			case SCAR: cout << "Scar"; break;
			case ARTI: cout << "Artifact"; break;
			case EARTH: cout << "Earth"; break;
			case WIND: cout << "Wind"; break;
			case FIRE: cout << "Fire"; break;
			case WATER: cout << "Water"; break;
			case BOLT: cout << "Electric"; break;
			case LEAF: cout << "Leaf"; break;
			}
		}
};

#endif