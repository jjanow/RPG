#include "Armor.h"
#include<string>

Armor::Armor()
{
	mDeflect = 0;
	mAbsorb = 0;
	mEnchant = 0;
}

Armor::Armor(std::string name, std::string desc, std::string material, int weight, int value, int deflect, int absorb, int enchant)
{
	mName = name;
	mDesc = desc;
	mMaterial = material;
	mWeight = weight;
	mValue = value;
	mDeflect = deflect;
	mAbsorb = absorb;
	mEnchant = enchant;
}