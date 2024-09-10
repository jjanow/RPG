#include "HealPotion.h"
#include "Player.h"
#include <string>

HealPotion::HealPotion(std::string name, std::string desc, std::string material, int weight, int value, int healhp, int healsp)
{
	mName = name;
	mDesc = desc;
	mMaterial = material;
	mWeight = weight;
	mValue = value;
	mHealHP = healhp;
	mHealSP = healsp;	
}

void HealPotion::Heal(Player& player)
{
	player.mHitPoints += mHealHP;
	if (player.mHitPoints > player.mMaxHitPoints)
	{
		player.mHitPoints = player.mMaxHitPoints;
	}

	player.mSpellPoints += mHealSP;
	if (player.mSpellPoints > player.mMaxSpellPoints)
	{
		player.mSpellPoints = player.mMaxSpellPoints;
	}
}