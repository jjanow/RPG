// Player.cpp

#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Random.h"
#include <string>
#include "Spell.h"
#include "HealPotion.h"
#include "FirePotion.h"
#include "getkb.h"

using namespace std;

Player::Player()
{
	mName         = "Default";
	mClassName    = "Default";
	mAccuracy     = 0;
	mHitPoints    = 0;
	mMaxHitPoints = 0;
	mExpPoints    = 0;
	mNextLevelExp = 0;
	mLevel        = 0;
	mGold         = 0;
	mShieldDur    = 0;
	mAccuracyDur  = 0;
	
	vector<Weapon> mWeapon;
	vector<Armor> mArmor;
	vector<Spell> mSpells;
	vector<Item> mInventory;
	
	mFireball.mName = "Fireball";
	mFireball.mArmorBuff = 0;	
	mFireball.mAccuracyBuff = 0;
	mFireball.mMagicPointsRequired = 10;
	mFireball.mDamageRange.mLow = 1;
	mFireball.mDamageRange.mHigh = 8;
	
	mMissile.mName = "Missile";
	mMissile.mArmorBuff = 0;	
	mMissile.mAccuracyBuff = 0;
	mMissile.mMagicPointsRequired = 4;
	mMissile.mDamageRange.mLow = 1;
	mMissile.mDamageRange.mHigh = 4;

	mShield.mName = "Shield";
	mShield.mArmorBuff = 5;	
	mShield.mAccuracyBuff = 0;
	mShield.mMagicPointsRequired = 3;
	
	mMAccuracy.mName = "Accuracy";
	mMAccuracy.mArmorBuff = 0;	
	mMAccuracy.mAccuracyBuff = 7;
	mMAccuracy.mMagicPointsRequired = 3;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmorDeflect()
{
	return mArmor[0].mDeflect;
}

int Player::getArmorAbsorb()
{
	return mArmor[0].mAbsorb;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	unsigned presskey = '1';

	Weapon Longsword("Longsword", "A longsword made of steel.", "Steel", 5, 50, 1, 8, 0);
	Weapon Staff("Staff", "A stout staff made of oak.", "Oak", 5, 20, 1, 6, 0);
	Weapon Shortsword("Shortsword", "A shortsword made of steel.", "Steel", 5, 30, 1, 6, 0);
	Weapon Flail("Flail", "A flail made of steel.", "Steel", 5, 40, 1, 6, 0);

	Armor Platemail("Platemail", "Armor made of steel plates.", "Steel", 50, 300, 4, 3, 0);
	Armor Chainmail("Chainmail", "Armor made of chain links.", "Steel", 25, 100, 3, 2, 0);
	Armor Leather("Leather", "Armor made of leather.", "Leather", 15, 40, 2, 1, 0);
	Armor Cloth("Cloth", "Armor made of cloth.", "Cloth", 5, 10, 1, 0, 0);

	HealPotion Healing("Healing Potion", "A red potion of healing.", "magic liquid", 1, 50, 20, 0);	
	FirePotion Fire("Fireball Potion", "A yellow potion of fireballs.", "magic liquid", 1, 100, 6, 36);

	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	// Input character's name.
	cout << "Enter your character's name: ";
	getline(cin, mName);

	// Character selection.
	cout << "Please select a character class number..."<< endl;	
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
	presskey = getkbe();

	switch( presskey )
	{
	case '1':  // Fighter
		mClassName      = "Fighter";
		mGold = 10000;
		mAccuracy       = 10;
		mHitPoints      = 20;
		mMaxHitPoints   = 20;
		mSpellPoints    = 5;
		mMaxSpellPoints = 5;
		mExpPoints      = 0;
		mNextLevelExp   = 1000;
		mLevel          = 1;
		mWeapon.push_back(Longsword);
		mArmor.push_back(Platemail);
		break;
	case '2':  // Wizard
		mClassName    = "Wizard";
		mAccuracy     = 5;
		mHitPoints    = 10;
		mMaxHitPoints = 10;
		mSpellPoints    = 25;
		mMaxSpellPoints = 25;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mWeapon.push_back(Staff);
		mArmor.push_back(Cloth);
		break;
	case '3':  // Cleric
		mClassName    = "Cleric";
		mAccuracy     = 8;
		mHitPoints    = 15;
		mMaxHitPoints = 15;
		mSpellPoints    = 15;
		mMaxSpellPoints = 15;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mWeapon.push_back(Flail);
		mArmor.push_back(Chainmail);
		break;
	default: // Thief
		mClassName    = "Thief";
		mAccuracy     = 7;
		mHitPoints    = 12;
		mMaxHitPoints = 12;
		mSpellPoints    = 10;
		mMaxSpellPoints = 10;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mWeapon.push_back(Shortsword);
		mArmor.push_back(Leather);
		break;
	}

	mInventory.push_back(Healing);
	mInventory.push_back(Healing);
	mInventory.push_back(Healing);
	mInventory.push_back(Fire);
	mInventory.push_back(Fire);
	mInventory.push_back(Fire);

	//Input character's race.
	cout << "Please select a character race number:" << endl;
	cout << "1)Elf 2)Dwarf 3)Halfling 4)Human : ";

	int raceNum = 1;
	raceNum = getkbe();

	switch(raceNum)
	{
	case '1': //Elf
		mRace = "Elf";
		mAccuracy += 1;
		mHitPoints -= 1;
		mMaxHitPoints -= 1;		
		break;
	case '2': //Dwarf
		mRace = "Dwarf";
		mAccuracy -= 1;
		mHitPoints += 2;
		mMaxHitPoints += 2;		
		break;
	case '3': //Halfling
		mRace = "Halfling";
		mAccuracy += 2;
		mHitPoints += 1;
		mMaxHitPoints += 1;		
		break;
	default: //Human
		mRace = "Human";
		break;
	}
}

bool Player::attack(Monster& monster)
{	
	// Combat is turned based: display an options menu.  You can,
	// of course, extend this to let the player use an item,
	// cast a spell, and so on.

	int selSpell = 0;
	int selPotion = 0;
	int selection = 1;

	if (mShieldDur > 0)
	{
		mShieldDur--;
		if (mShieldDur == 0)
		{
			mArmor[0].mDeflect -= mShield.mArmorBuff;
		}
	}

	if (mAccuracyDur > 0)
	{
		mAccuracyDur--;
		if (mAccuracyDur == 0)
		{
			mAccuracy -= mMAccuracy.mAccuracyBuff ;
		}
	}
	cout << "[Shield: " << mShieldDur << "][Accuracy: " << mAccuracyDur << "]" << endl;
	cout << "1) Attack, 2) Cast Spell, 3) Potion, 4) Run: ";
	selection = getkbe();
	cout << endl;

	int roll = 0;
	int totalroll = 0;

	switch( selection )
	{
	case '1':
		roll = Random::random(0, 20);
		totalroll += roll - mWeapon[0].mEnchant;

		cout << "You attack an " << monster.getName() << " with a " << mWeapon[0].mName << endl;

		if( roll < mAccuracy )
		{
			int damage = Random::random(mWeapon[0].mDamageRange.mLow, mWeapon[0].mDamageRange.mHigh);

			int totalDamage = (damage + mWeapon[0].mEnchant) - monster.getArmor();

			if( totalDamage <= 0 )
			{
				cout << "Your attack failed to penetrate "
					<< "the armor. [Damage: " << totalDamage << " (" << damage << " + " <<mWeapon[0].mEnchant << " - " << monster.getArmor() << ") | Roll: " << totalroll << " (" << roll << " - " << mWeapon[0].mEnchant << ")]" << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage 
					<< " damage! [Damage: " << totalDamage << " (" << damage << " + " <<mWeapon[0].mEnchant << " - " << monster.getArmor() << ") | Roll: " << totalroll << " (" << roll << " - " << mWeapon[0].mEnchant << ")]" << endl;

				// Subtract from monster's hitpoints.
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss! [Roll: " << totalroll << " (" << roll << "-" << mWeapon[0].mEnchant << ")]" << endl;
		}
		cout << endl;
		break;
	case '2':
		while(selSpell < '1' || selSpell > '5')
		{
			cout << "1) Fireball, 2) Missile, 3)Shield, 4)Accuracy, 5)Cancel: ";
			selSpell = getkbe();
			cout << endl;
		}
		castSpell(selSpell, &monster);
		break;
	case '3':
		while (selPotion < '1' || selPotion > '3')
		{
			cout << "1) Healing, 2) Fireball, 3) Cancel: ";
			selPotion = getkbe();
			cout << endl;

			if (selPotion == '1')
			{
				for (int x = 0; x < (int)mInventory.size(); x++)
				{
					if (mInventory[x].mName == "Healing Potion")
					{
						mInventory.erase(mInventory.begin()+x);
						mHitPoints = mMaxHitPoints;
						mSpellPoints = mMaxSpellPoints;
						cout << "You drink a healing potion and are fully restored!" << endl;
						break;
					}
					else
					{
						cout << "You have no healing potions!" << endl;
						break;
					}
				}
			}

			if (selPotion == '2')
			{
				for (int x = 0; x < (int)mInventory.size(); x++)
				{
					if (mInventory[x].mName == "Fireball Potion")
					{
						mInventory.erase(mInventory.begin()+x);
						int rnd = Random::random(6,36);
						cout << "You throw the potion at " << monster.getName() << " and it explodes in a ball of fire! (" << rnd << ")" << endl;
						monster.takeDamage(rnd);
						break;
					}
					if (mInventory.size() == x+1)
					{
						cout << "You have no fireball potions!" << endl;
						break;
					}
				}
				break;
			}

			if (selPotion == '3')
			{
				break;
			}
		}	
		break;
	case '4':
		// 50 % chance of being able to run.
		roll = Random::random(1, 4);

		if( roll > 2 )
		{
			cout << "You run away!" << endl;
			return true;//<--Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}	
	}
	return false;
}

void Player::levelUp()
{
	if( mExpPoints >= mNextLevelExp )
	{
		cout << "You gained a level!" << endl;

		// Increment level.
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;

		if (mClassName == "Fighter")
		{
			// Increase stats randomly.
			mAccuracy       += Random::random(2, 5);
			mMaxHitPoints   += Random::random(2, 10);
			mMaxSpellPoints += Random::random(2, 4);
			//mArmor          += Random::random(2, 4);

			// Give player full hitpoints when they level up.
			mHitPoints = mMaxHitPoints;
			mSpellPoints = mMaxSpellPoints;
		}

		if (mClassName == "Cleric")
		{
			// Increase stats randomly.
			mAccuracy       += Random::random(2, 4);
			mMaxHitPoints   += Random::random(2, 8);
			mMaxSpellPoints += Random::random(2, 8);
			//mArmor          += Random::random(2, 4);

			// Give player full hitpoints when they level up.
			mHitPoints = mMaxHitPoints;
			mSpellPoints = mMaxSpellPoints;
		}

		if (mClassName == "Thief")
		{
			// Increase stats randomly.
			mAccuracy       += Random::random(3, 5);
			mMaxHitPoints   += Random::random(2, 6);
			mMaxSpellPoints += Random::random(2, 6);
			//mArmor          += Random::random(1, 3);

			// Give player full hitpoints when they level up.
			mHitPoints = mMaxHitPoints;
			mSpellPoints = mMaxSpellPoints;
		}

		if (mClassName == "Wizard")
		{
			// Increase stats randomly.
			mAccuracy       += Random::random(1, 3);
			mMaxHitPoints   += Random::random(2, 4);
			mMaxSpellPoints += Random::random(2, 10);
			//mArmor          += Random::random(1, 2);

			// Give player full hitpoints when they level up.
			mHitPoints = mMaxHitPoints;
			mSpellPoints = mMaxSpellPoints;
		}
	}
}

void Player::rest()
{
	cout << "Resting..." << endl;

	mHitPoints = mMaxHitPoints;
	mSpellPoints = mMaxSpellPoints;

	if (mShieldDur > 0)
	{
		mShieldDur = 0;
		mArmor[0].mDeflect -= mShield.mArmorBuff;
	}

	if (mAccuracyDur > 0)
	{
		mAccuracyDur = 0;
		mAccuracy -= mMAccuracy.mAccuracyBuff ;	
	}
}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;

	cout << "Name             = " << mName           << endl;
	cout << "Race             = " << mRace           << endl;
	cout << "Class            = " << mClassName      << endl;
	cout << "Accuracy         = " << mAccuracy       << endl;
	cout << "Hitpoints        = " << mHitPoints      << "/" << mMaxHitPoints << endl;	
	cout << "Spell Points     = " << mSpellPoints    << "/" << mMaxSpellPoints << endl;	
	cout << "XP               = " << mExpPoints      << "/" << mNextLevelExp << endl;
	cout << "Level            = " << mLevel          << endl;
	cout << "Armor            = " << mArmor[0].mName << " [" << mArmor[0].mAbsorb << "/" << mArmor[0].mDeflect << "]+" << mArmor[0].mEnchant << endl;
	cout << "Gold             = " << mGold           << endl;
	cout << "Shield buff      = " << mShieldDur      << endl;
	cout << "Accuracy buff    = " << mAccuracyDur    << endl;
	cout << "Weapon Name      = " << mWeapon[0].mName << " [" << mWeapon[0].mDamageRange.mLow << "-" << mWeapon[0].mDamageRange.mHigh << "]+" << mWeapon[0].mEnchant << endl;
	cout << "Items: " << endl;
	for (int x = 0;x < (int)mInventory.size(); x++)
	{
		cout << "[" << x << "]" << mInventory[x].mName;
		/*if (x != mInventory.size()-1)
		{
			cout << ", ";
		}
		else
		{*/
			cout << endl;
		//}
	}

	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp, int gold)
{
	cout << "You won the battle!" << endl;
	cout << "You win " << xp 
		<< " experience points!" << endl
		<< "You find " << gold << " gold pieces!" << endl;

	mExpPoints += xp;
	mGold += gold;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press any key to quit: ";
	getkb();
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}

void Player::castSpell(int selectSpell, Monster* monster)
{
	switch (selectSpell)
	{
	case '1':
		if (mSpellPoints < mFireball.mMagicPointsRequired)
		{
			cout << "Insufficent spell points!" << endl;
			break;
		}
		else
		{
			int dmg = 0;
			for (int x = 0; x < mLevel; x++)
			{
				dmg += Random::random(mFireball.mDamageRange.mLow, mFireball.mDamageRange.mHigh);
			}
			monster->takeDamage(dmg);
			mSpellPoints -= mFireball.mMagicPointsRequired;
			cout << "You launch a fireball at " << monster->getName() << "! (" << dmg << ")" << endl;
		}
		break;
	case '2':
		if (mSpellPoints < mMissile.mMagicPointsRequired)
		{
			cout << "Insufficent spell points!" << endl;
			break;
		}
		else
		{
			int dmg = 0;
			for (int x = 0; x < mLevel; x++)
			{
				dmg += Random::random(mMissile.mDamageRange.mLow, mMissile.mDamageRange.mHigh);
			}
			monster->takeDamage(dmg);
			mSpellPoints -= mMissile.mMagicPointsRequired;
			cout << "You launch a magic missile at " << monster->getName() << "! (" << dmg << ")" << endl;
		}
		break;
	case '3':
		if (mSpellPoints < mShield.mMagicPointsRequired)
		{
			cout << "Insufficent spell points!" << endl;
			break;
		}
		else
		{
			cout << "A magical shield surrounds you!" << endl;
			int prot = 0;
			for (int x = 0; x < mLevel; x++)
			{
				prot += mShield.mArmorBuff;
				mShieldDur += 10;
				mArmor[0].mDeflect += mShield.mArmorBuff;
			}
			mSpellPoints -= mShield.mMagicPointsRequired;
		}
		break;
	case '4':
		if (mSpellPoints < mMAccuracy.mMagicPointsRequired)
		{
			cout << "Insufficent spell points!" << endl;
			break;
		}
		else
		{
			cout << "Your move with supernatural agility!" << endl;
			int acc = 0;
			for (int x = 0; x < mLevel; x++)
			{
				acc += mMAccuracy.mAccuracyBuff;
				mAccuracyDur += 10;
				mAccuracy += mMAccuracy.mAccuracyBuff;
			}
			mSpellPoints -= mMAccuracy.mMagicPointsRequired;
		}
		break;
	case '5':
		cout << "You cancel your spellcasting preparations!" << endl;
		break;
	}
}

void Player::equipItems()
{

}