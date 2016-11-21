#include "gameControl.h"

void GameControl::info()
{
	cout << "'Help' - gives you your options" << endl;
	cout << "'Look' - lets you look around" << endl;
	cout << "'Info' - gets a short discription of where you are" << endl;
	cout << "'North/East/South/West' - move around" << endl;
	cout << "'Inspect(i)' - get information about where you are and items there" << endl;
	cout << "'Take' - picks up an item from the ground" << endl;
	cout << "'Equip' - equip weapon/armor" << endl;
	cout << "'Character(c)' - get information about your character and inventory" << endl;
	cout << "'Attack' - attack an enemy in the room" << endl;
	cout << "'Use' - uses an item/reads a note" << endl;
	cout << "'Quit' - quits the game/allows a restart" << endl;
}

string GameControl::loop(Map* theMap)
{
	gameOver = false;
	m_TheMap = theMap;
	string theChoice;
	
	cout << "--------------------------------" << endl;
	theMap->getPlayerLoc()->getDesc();
	theMap->getPlayerLoc()->listEnemies();
	theMap->getPlayerLoc()->inspect();
	theMap->getPlayerLoc()->flipBeenHere();
	cout << "--------------------------------" << endl;

	while (!gameOver && m_TheMap->getPlayer()->getHealth() > 0)
	{	
		cin >> theChoice;

		//I toupper the whole user input. I use this a lot
		for (unsigned int i = 0; i < theChoice.length(); ++i)//Apparently .length() returns a size_t which is unsigned. 
		{													 //Was told to set i to size_t but don't really understand what that is so just unsigned the int
			theChoice[i] = toupper(theChoice[i]);			 //to make sure I can explain this.
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
			theMap->getPlayer()->equip();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "UNEQUIP")
		{
			cout << "--------------------------------" << endl;
			cout << "Remove armor or sheath weapon?(armor/weapon): ";
			cin >> theChoice;

			for (unsigned int i = 0; i < theChoice.length(); ++i)
			{
				theChoice[i] = toupper(theChoice[i]);
			}

			if (theChoice == "ARMOR")
			{
				theMap->getPlayer()->unequip(0);
			}
			else if (theChoice == "WEAPON")
			{
				theMap->getPlayer()->unequip(0);
			}
			else
			{
				cout << "--------------------------------" << endl;
				cout << "I do not recognize that command" << endl;
			}
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
			if (theMap->getPlayer()->getHealth() <= 0)
			{
				gameOver = true;
			}
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "QUIT")
		{
			gameOver = true;
		}
		else
		{
			cout << "--------------------------------" << endl;
			cout << "I do not recognize that command" << endl;
			cout << "--------------------------------" << endl;
		}
	}

	 string answer = playerDead();
	 return answer;
}

string GameControl::playerDead()
{
	string answer;
	cout << "Would you like to play again?(y/n): ";
	cin >> answer;
	
	answer = toupper(answer[0]);

	return answer;
}
