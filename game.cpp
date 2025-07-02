// game.cpp

#include "Map.h"
#include "Player.h"
#include "Spell.h"
#include "Random.h"
#include "Store.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "getkb.h"

using namespace std;

int main()
{
	srand( (int)time(0) );

	Map gameMap;

	Player mainPlayer;

	mainPlayer.createClass();

	int key;

	// Begin adventure.
	bool done = false;
	while( !done )
	{
		// Each loop cycle we output the player position and 
		// a selection menu.

		gameMap.printPlayerPos();
	
		/*int selection = 1;*/
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Equip Items 5) Quit: ";
		key = getkbe();
		//cin >> selection;

		Monster* monster = 0;
		/*switch( selection )*/
		switch( key )
		{
		case '1':
			gameMap.movePlayer();

			if (gameMap.getPlayerXPos() == 1 && gameMap.getPlayerYPos() == 1)
			{
				Store store;
				store.Enter(mainPlayer);
			}

			// Check for a random encounter.  This function
			// returns a null pointer if no monsters are
			// encountered.
			monster = gameMap.checkRandomEncounter();

			// 'monster' not null, run combat simulation.
			if( monster != 0 )
			{
				// Loop until a 'break' statement.
				while( true )
				{
					// Display hitpoints.
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;

					// Player's turn to attack first.
					bool runAway = mainPlayer.attack(*monster);

					if( runAway )
						break;

					if( monster->isDead() )
					{
						mainPlayer.victory(monster->getXPReward(), monster->getGoldReward());
						mainPlayer.levelUp();
						break;
					}

					monster->attack(mainPlayer);

					if( mainPlayer.isDead() )
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from
				// checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid
				// memory leaks.
				delete monster;
				monster = 0;
			}

			break;
		case '2':
			// Check for a random encounter.  This function
			// returns a null pointer if no monsters are
			// encountered.
			monster = gameMap.checkRandomEncounter();

			// 'monster' not null, run combat simulation.
			if( monster != 0 )
			{
				// Loop until a 'break' statement.
				while( true )
				{
					// Display hitpoints.
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;

					// Player's turn to attack first.
					bool runAway = mainPlayer.attack(*monster);

					if( runAway )
						break;

					if( monster->isDead() )
					{
						mainPlayer.victory(monster->getXPReward(), monster->getGoldReward());
						mainPlayer.levelUp();
						break;
					}

					monster->attack(mainPlayer);

					if( mainPlayer.isDead() )
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from
				// checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid
				// memory leaks.
				delete monster;
				monster = 0;
			}
			mainPlayer.rest();
			break;
		case '3':
			mainPlayer.viewStats();
			break;
		case '4':
			mainPlayer.equipItems();
			break;
		case '5':
			done = true;
			break;
		}
	}	
}