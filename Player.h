// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Armor.h"
#include "Monster.h"
#include "Spell.h"
#include <string>
#include <vector>

class Player
{
public:
	// Constructor.
	Player();

	// Methods
	bool isDead();

	int  getArmorDeflect();
	int  getArmorAbsorb();

	void takeDamage(int damage);

	void createClass();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStats();
	void victory(int xp, int gold);
	void gameover();
	void displayHitPoints();
	void castSpell(int selectSpell, Monster* monster);
	void equipItems();
 
//private:
	// Data members.
	std::string mName;
	std::string mClassName;
	std::string mRace;
	int         mAccuracy;
	int         mHitPoints;
	int         mMaxHitPoints;
	int			mSpellPoints;
	int			mMaxSpellPoints;
	int         mExpPoints;
	int         mNextLevelExp;
	int         mLevel;	
	int			mGold;
	int			mShieldDur;
	int			mAccuracyDur;
	std::vector<Weapon> mWeapon;
	std::vector<Armor> mArmor;
	std::vector<Spell> mSpells;
	std::vector<Item> mInventory;
	Spell		mFireball;
	Spell		mMissile;
	Spell		mShield;
	Spell		mMAccuracy;
};

#endif //PLAYER_H