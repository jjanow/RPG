// FirePotion.h

#ifndef FIREPOTION_H
#define FIREPOTION_H

#include "Item.h"
#include "Range.h"
#include <string>

struct FirePotion : Item
{
	FirePotion();
	FirePotion(std::string name, std::string desc, std::string material, int weight, int value, int ldamage, int hdamage);
	
	int FireDamage(Range damage);

	Range mDamage;
};

#endif //FIREPOTION_H