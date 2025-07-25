// Map.cpp

#include "Map.h"
#include "getkb.h"
#include <iostream>
#include "Random.h"
using namespace std;

Map::Map()
{
	// Player starts at origin (0, 0)
	mPlayerXPos = 0;
	mPlayerYPos = 0;
}

int  Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int  Map::getPlayerYPos()
{
	return mPlayerYPos;
}

void Map::movePlayer()
{	
	int selection = 1;
	cout << "1) North, 2) East, 3) South, 4) West: ";
	selection = getkb();

	// Update coordinates based on selection.
	switch( selection )
	{
	case '1': // North
		mPlayerYPos++;
		break;
	case '2': // East
		mPlayerXPos++;
		break;
	case '3': // South
		mPlayerYPos--;
		break;
	default: // West
		mPlayerXPos--;
		break;
	}
	cout << endl;
}

Monster* Map::checkRandomEncounter()
{
	int roll = Random::random(0, 20);

	Monster* monster = 0;

	if( roll <= 16 )
	{
		// No encounter, return a null pointer.
		return 0;
	}
	else if(roll == 17)
	{
		monster = new Monster("Orc", 10, 8, 200, 1, Random::random(5,10),
			"Short Sword", 2, 7);

		cout << "You encountered an Orc!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if(roll == 18)
	{
		monster = new Monster("Goblin", 6, 6, 100, 0, Random::random(1,5),
			"Dagger", 1, 5);

		cout << "You encountered a Goblin!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if(roll == 19)
	{
		monster = new Monster("Ogre", 20, 12, 500, 2, Random::random(10,20),
			"Club", 3, 8);

		cout << "You encountered an Ogre!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if(roll == 20)
	{
		monster = new Monster("Orc Lord", 25, 15, 2000, 5, Random::random(40,70),
			"Two Handed Sword", 5, 20);

		cout << "You encountered an Orc Lord!!!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}

	return monster;
}

void Map::printPlayerPos()
{
	cout << "Player Position = [" << mPlayerXPos << ", " 
		<< mPlayerYPos << "]" << endl << endl;
}