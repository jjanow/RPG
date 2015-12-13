// Weapon.h

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Range.h"
#include <string>

struct Weapon : Item
{
public:
	Weapon();
	Weapon(std::string name, std::string desc, std::string material, int weight, int value, int low, int high, int enchant);

	Range       mDamageRange;
	int			mEnchant;
};

#endif //WEAPON_H