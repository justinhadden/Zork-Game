#include "gameControl.h"

void GameControl::info()
{
	cout << "'Help(h)' - gives you your options" << endl;
	cout << "'Look(l)' - lets you look around" << endl;
	cout << "'WhereAmI(wai)' - gets a discription of where you are" << endl;
	cout << "'North(n)/East(e)/South(s)/West(w)' - move around" << endl;
	cout << "'Inspect(i)' - looks for items on the ground" << endl;
	cout << "'Take(t)' - picks up an item from the ground" << endl;
	cout << "'Equip(eqp)' - equip weapon" << endl;
	cout << "'Character Inventory(c)' - checks your inventory" << endl;
	cout << "'Use(u)' - uses an item" << endl;
	cout << "'Quit' - quits the game" << endl;
}

void GameControl::loop(Map* theMap)
{
	string theChoice;

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
		else if (theChoice == "WAI" || theChoice == "WHEREAMI")
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