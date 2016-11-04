#include "gameControl.h"

void GameControl::info()
{
	cout << "'Help' - gives you your options" << endl;
	cout << "'Look' - lets you look around" << endl;
	cout << "'Info' - gets a discription of where you are" << endl;
	cout << "'North/East/South/West' - move around" << endl;
	cout << "'Inspect' - looks for items on the ground" << endl;
	cout << "'Take' - picks up an item from the ground" << endl;
	cout << "'Equip' - equip weapon" << endl;
	cout << "'Character Inventory' - get information about your character" << endl;
	cout << "'Attack' - attacks the enemy in the room" << endl;
	cout << "'Use' - uses an item" << endl;
	cout << "'Quit' - quits the game" << endl;
}

void GameControl::loop(Map* theMap)
{
	string theChoice;

	cout << "--------------------------------" << endl;
	theMap->getPlayerLoc()->getDesc();
	cout << "--------------------------------" << endl;

	while (theChoice != "QUIT")
	{	
		cin >> theChoice;

		for (int i = 0; i < theChoice.length(); ++i)
		{
			theChoice[i] = toupper(theChoice[i]);
		}

		if (theChoice == "HELP")
		{
			cout << "--------------------------------" << endl;
			info();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "N" || theChoice == "NORTH" || theChoice == "E" || theChoice == "EAST" ||
			theChoice == "S" || theChoice == "SOUTH" || theChoice == "W" || theChoice == "WEST")
		{
			cout << "--------------------------------" << endl;
			theMap->move(theChoice);
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "L" || theChoice == "LOOK")
		{
			cout << "--------------------------------" << endl;
			theMap->look();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "I" || theChoice == "INSPECT")
		{
			cout << "--------------------------------" << endl;
			theMap->inspect();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "T" || theChoice == "TAKE")
		{
			cout << "--------------------------------" << endl;
			theMap->pick();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "C" || theChoice == "INVENTORY" || theChoice == "CHARACTER")
		{
			cout << "--------------------------------" << endl;
			theMap->playerInv();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "U" || theChoice == "USE")
		{
			cout << "--------------------------------" << endl;
			theMap->use();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "D" || theChoice == "DROP")
		{
			cout << "--------------------------------" << endl;
			theMap->drop();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "WAI" || theChoice == "INFO")
		{
			cout << "--------------------------------" << endl;
			theMap->getPlayerLoc()->getDesc();
			theMap->getPlayerLoc()->listEnemies();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "EQP" || theChoice == "EQUIP")
		{
			cout << "--------------------------------" << endl;
			theMap->getPlayer()->equipWeapon();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "SHOWATTACK")
		{
			cout << "--------------------------------" << endl;
			theMap->getPlayer()->showAttack();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "UNEQUIP")
		{
			cout << "--------------------------------" << endl;
			theMap->getPlayer()->unequipWeapon();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "A" || theChoice == "ATTACK")
		{
			cout << "--------------------------------" << endl;
			if (theMap->getPlayerLoc()->hasEnemies())
			{
				theMap->attackEnemy();
			}
			else
			{
				theMap->getPlayer()->attack();
			}
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "SHOWHEALTH")
		{
			cout << "--------------------------------" << endl;
			theMap->getPlayer()->showHealth();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice != "QUIT")
		{
			cout << "--------------------------------" << endl;
			cout << "I do not recognize that command" << endl;
			cout << "--------------------------------" << endl;
		}
	}

}