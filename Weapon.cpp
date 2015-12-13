#include "Weapon.h"
#include <string>

using namespace std;

Weapon::Weapon()
{
	mDamageRange.mLow = 0;
	mDamageRange.mHigh = 0;
	mEnchant = 0;
}

Weapon::Weapon(std::string name, std::string desc, std::string material, int weight, int value, int low, int high, int enchant)
{
	mName = name;
	mDesc = desc;
	mMaterial = material;
	mWeight = weight;
	mValue = value;
	mDamageRange.mLow = low;
	mDamageRange.mHigh = high;
	mEnchant = enchant;
}