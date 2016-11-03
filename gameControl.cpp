#include "gameControl.h"

void GameControl::info()
{
	cout << "'Help(h)' - gives you your options" << endl;
	cout << "'Look(l)' - lets you look around" << endl;
	cout << "'North(n)/East(e)/South(s)/West(w)' - move around" << endl;
	cout << "'Inspect(i)' - looks for items on the ground" << endl;
	cout << "'Pick(p)' - picks up an item from the ground" << endl;
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

		for (int i = 0; i <= theChoice.length(); ++i)
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
		else if (theChoice == "P" || theChoice == "PICK")
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
		else if (theChoice != "QUIT")
		{
			cout << "--------------------------------" << endl;
			cout << "I do not recognize that command" << endl;
			cout << "--------------------------------" << endl;
		}
	}

}