// Spell.h

#ifndef SPELL_H
#define SPELL_H

#include "Range.h"
#include <string>

struct Spell
{
	std::string mName;
	Range       mDamageRange;	
	int         mMagicPointsRequired;
	int			mArmorBuff;
	int			mAccuracyBuff;
};

#endif //SPELL_H