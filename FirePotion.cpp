#include "Random.h"
#include "FirePotion.h"
#include <string>

FirePotion::FirePotion(std::string name, std::string desc, std::string material, int weight, int value, int ldamage, int hdamage)
{
	mName = name;
	mDesc = desc;
	mMaterial = material;
	mWeight = weight;
	mValue = value;
	mDamage.mLow = ldamage;
	mDamage.mHigh = hdamage;
}

int FirePotion::FireDamage(Range damage)
{
	int dmg = Random(damage.mLow, damage.mHigh);
	return dmg;
}