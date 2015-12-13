// Armor.h

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include <string>

struct Armor : Item
{
	Armor::Armor();
	Armor::Armor(std::string mName, std::string desc, std::string material, int weight, int value, int deflect, int absorb, int enchant);

	int mDeflect;
	int mAbsorb;
	int mEnchant;
};

#endif //WEAPON_H