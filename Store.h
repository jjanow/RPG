// Store.h

#ifndef STORE_H
#define STORE_H

#include "Weapon.h"
#include "Armor.h"
#include "FirePotion.h"
#include "HealPotion.h"
#include <string>

class Store
{
public:
	// Constructor.
	Store();

	// Methods
	void Enter(Player& player);
	bool checkMoney(Player& player, int cost);

private:
	// Data members.
	
};

#endif //STORE_H