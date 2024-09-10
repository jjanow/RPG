// HealPotion.h

#ifndef HEALPOTION_H
#define HEALPOTION_H

#include "Item.h"
#include "Player.h"
#include "Range.h"
#include <string>

struct HealPotion : Item
{	
	HealPotion();
	HealPotion(std::string name, std::string desc, std::string material, int weight, int value, int healhp, int healsp);
	void Heal(Player& player);

	int mHealHP;
	int mHealSP;	
};

#endif //HEALPOTION_H