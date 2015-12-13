#include "Store.h"
#include "Getkb.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

Store::Store()
{
	
}

void Store::Enter(Player& player)
{
	Weapon Longsword("Longsword", "A longsword made of steel.", "Steel", 5, 50, 1, 8, 0);
	Weapon Staff("Staff", "A stout staff made of oak.", "Oak", 5, 20, 1, 6, 0);
	Weapon Shortsword("Shortsword", "A shortsword made of steel.", "Steel", 5, 30, 1, 6, 0);
	Weapon Flail("Flail", "A flail made of steel.", "Steel", 5, 40, 1, 6, 0);
	Weapon THSword("2H Sword", "A large sword requiring two hands and made of steel.", "Steel", 10, 250, 2, 12, 1);

	Armor Platemail("Platemail", "Armor made of steel plates.", "Steel", 50, 300, 4, 3, 0);
	Armor Chainmail("Chainmail", "Armor made of chain links.", "Steel", 25, 100, 3, 2, 0);
	Armor Leather("Leather", "Armor made of leather.", "Leather", 15, 40, 2, 1, 0);
	Armor Cloth("Cloth", "Armor made of cloth.", "Cloth", 5, 10, 1, 0, 0);
	Armor Exotic("Exotic", "Exotic armor made from an unknown material.", "Exotic", 1, 1000, 8, 7, 1);

	HealPotion Healing("Healing Potion", "A red potion of healing.", "magic liquid", 1, 50, 20, 0);	
	FirePotion Fire("Fireball Potion", "A yellow potion of fireballs.", "magic liquid", 1, 100, 6, 36);

	int key;
	int choice = 0;
	int itemToSell = -1;
	bool done = false;

	while (!done)
	{
		cout << "You enter Garth's Equipment Emporium!" << endl;
		cout << "1) Buy 2) Sell 3) Exit" << endl;

		key = getkb();

		switch (key)
		{
		case '1':
			cout << "1) Longsword: 100 " << endl;
			cout << "2) Staff: 10" << endl;
			cout << "3) Flail: 75" << endl;
			cout << "4) Shortsword: 50" << endl;
			cout << "5) 2H Sword: 250" << endl;
			cout << "6) Platemail: 500" << endl;
			cout << "7) Chainmail: 350" << endl;
			cout << "8) Leather: 200" << endl;
			cout << "9) Cloth: 50" << endl;
			cout << "10) Exotic Armor: 1000" << endl;
			cout << "11) Healing potion: 100" << endl;
			cout << "12) Fireball potion: 100" << endl;
			cout << "13) Cancel" << endl;
			cout << "======================" << endl;
			cout << "What do you wish to buy: ";

			cin >> choice;
			cout << endl;

			if (choice == 1)
			{
				if (this->checkMoney(player, 100))
				{
					player.mGold -= 100;
					player.mInventory.push_back(Longsword);
					cout << "You purchase a Longsword." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 2)
			{
				if (this->checkMoney(player, 10))
				{
					player.mGold -= 10;
					player.mInventory.push_back(Staff);
					cout << "You purchase a Staff." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 3)
			{
				if (this->checkMoney(player, 75))
				{
					player.mGold -= 75;
					player.mInventory.push_back(Flail);
					cout << "You purchase a Flail." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 4)
			{
				if (this->checkMoney(player, 50))
				{
					player.mGold -= 50;
					player.mInventory.push_back(Shortsword);
					cout << "You purchase a Shortsword." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 5)
			{
				if (this->checkMoney(player, 250))
				{
					player.mGold -= 250;
					player.mInventory.push_back(THSword);
					cout << "You purchase a 2H Sword." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 6)
			{
				if (this->checkMoney(player, 500))
				{
					player.mGold -= 500;
					player.mInventory.push_back(Platemail);
					cout << "You purchase a Platemail." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 7)
			{
				if (this->checkMoney(player, 350))
				{
					player.mGold -= 350;
					player.mInventory.push_back(Chainmail);
					cout << "You purchase a Chainmail armor." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 8)
			{
				if (this->checkMoney(player, 200))
				{
					player.mGold -= 200;
					player.mInventory.push_back(Leather);
					cout << "You purchase a Leather armor." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 9)
			{
				if (this->checkMoney(player, 50))
				{
					player.mGold -= 50;
					player.mInventory.push_back(Cloth);
					cout << "You purchase a Cloth armor." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 10)
			{
				if (this->checkMoney(player, 1000))
				{
					player.mGold -= 1000;
					player.mInventory.push_back(Exotic);
					cout << "You purchase an Exotic armor." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 11)
			{
				if (this->checkMoney(player, 100))
				{
					player.mGold -= 100;
					player.mInventory.push_back(Healing);
					cout << "You purchase a Healing potion." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 12)
			{
				if (this->checkMoney(player, 100))
				{
					player.mGold -= 100;
					player.mInventory.push_back(Fire);
					cout << "You purchase a Fireball potion." << endl;
				}
				else
				{
					cout << "Insufficient gold."  << endl;
				}
			}

			if (choice == 13)
			{
				done = true;				
			}

			break;
		case '2':
			for (int x = 0;x < (int)player.mInventory.size(); x++)
			{
				cout << "[" << x << "]" << player.mInventory[x].mName << endl;
			}
			cout << "Sell which item (-1 to cancel)?";
			cin >> itemToSell;

			if (itemToSell > 0 && itemToSell <= player.mInventory.size())
			{
				cout << "You sell " << player.mInventory[itemToSell].mName << " for " << player.mInventory[itemToSell].mValue << "." << endl;
				player.mGold += player.mInventory[itemToSell].mValue;
				player.mInventory.erase(player.mInventory.begin()+itemToSell);
			}
			break;
		default:
			done = true;
			break;
		}
	}
	cout << "You leave the store." << endl << endl;
	return;
}

bool Store::checkMoney(Player& player, int cost)
{
	if (cost > player.mGold)
	{
		return false;
	}
	else
	{
		return true;
	}
}