// Monster.cpp

#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Random.h"
using namespace std;

Monster::Monster(const std::string& name, int hp, int acc,
		int xpReward, int armor, int gold, const std::string& weaponName,
		int lowDamage, int highDamage)
{
	mName      = name;
	mHitPoints = hp;
	mAccuracy  = acc;
	mExpReward = xpReward;
	mArmor     = armor;
	mGoldReward = gold;
	mWeapon.mName = weaponName;
	mWeapon.mDamageRange.mLow  = lowDamage;
	mWeapon.mDamageRange.mHigh = highDamage;
}

bool Monster::isDead()
{
	return mHitPoints <= 0;
}

int Monster::getXPReward()
{
	return mExpReward;
}

int Monster::getGoldReward()
{
	return mGoldReward;
}

std::string Monster::getName()
{
	return mName;
}

int Monster::getArmor()
{
	return mArmor;
}

void Monster::attack(Player& player)
{
	cout << "A " << mName << " attacks you " 
		<< "with a " << mWeapon.mName << endl;

	Random randomGenerator; // Create an instance of the new Random class

	// Test to see if the monster hit the player.
	int roll = randomGenerator.getRandomNumber(0, 20);
	
	if( roll < (mAccuracy - player.getArmorDeflect()) )
	{
		// Generate a damage value based on the weapons range.
		int damage = randomGenerator.getRandomNumber(mWeapon.mDamageRange.mLow, mWeapon.mDamageRange.mHigh);

		// Subtract the player's armor from damage to
		// simulate armor weakening the attack.  Note that
		// if the armor > damage this results in a negative
		// number.
		int totalDamage = damage - player.getArmorAbsorb();

		// If totalDamage <= 0, then we say that, although
		// the attack hit, it did not penetrate the armor.
		if( totalDamage <= 0 )
		{
			cout << "The monster's attack failed to "
				<< "penetrate your armor. [Damage: " << totalDamage << " | Roll: " << roll << "]" << endl;
		}
		else
		{
			cout << "You are hit for " << totalDamage 
				<< " damage! [Roll: " << roll << "]" << endl;

			// Subtract from players hitpoints.
			player.takeDamage(totalDamage);
		}
	}
	else
	{
		cout << "The " << mName << " missed! [Roll: " << roll << "]" << endl;
	}
	cout << endl;
}

void Monster::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Monster::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}