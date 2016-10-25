#include "map.h"

Map::Map()
{
	Room* house = new Room("a House in a field", "You are in a field with a house in the middle of it.");
	Room* forest = new Room("a Forest", "You are in a dark forest and can barely see.");
	Room* oldcabin = new Room("an Old Cabin", "You are in the forest next to and old cabin.");
	oldcabin->popRoom("Key");
	Room* mountain = new Room("a Mountain", "You are at the foot of a giant mountain.");
	mountain->popRoom("Rock");
	mountain->popRoom("Pickaxe");
	Room* swamp = new Room("a Swamp", "You are in a nasty swamp surrounded by flies.");
	swamp->popRoom("Mudball");
	Room* castleGates = new Room("the Castle Gates", "You are at the gates of a massive castle.");
	Room* courtyard = new Room("a Courtyard", "You are in the courtyard of the castle");
	courtyard->popRoom("Gold");
	courtyard->lockUnlock();
	house->setDirect(mountain, forest, 0, 0);
	forest->setDirect(oldcabin, swamp, 0, house);
	oldcabin->setDirect(0, castleGates, forest, mountain);
	mountain->setDirect(0, oldcabin, house, 0);
	swamp->setDirect(castleGates, 0, 0, forest);
	castleGates->setDirect(courtyard, 0, swamp, oldcabin);
	courtyard->setDirect(0, 0, castleGates, 0);

	string name;
	cout << "First off, What is your name?: ";
	cin >> name;

	Player* player = new Player(name);

	m_pPlayerLoc = house;
	m_pPlayer = player;
}

Map::~Map()
{

}

string Map::getName()
{
	return m_pPlayer->GetName();
}

void Map::move(string theChoice, Map* theMap)
{
	if (theChoice == "N" || theChoice == "NORTH")
	{
		if (m_pPlayerLoc->direct[0] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else if (m_pPlayerLoc->direct[0]->locked)
		{
			cout << "The gates are locked" << endl;
		}
		else
		{
			cout << "You walk north." << endl;
			m_pPlayerLoc = m_pPlayerLoc->direct[0];
			m_pPlayerLoc->GetDesc();
		}
	}
	else if (theChoice == "E" || theChoice == "EAST")
	{
		if (m_pPlayerLoc->direct[1] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk east." << endl;
			m_pPlayerLoc = m_pPlayerLoc->direct[1];
			m_pPlayerLoc->GetDesc();
		}
	}
	else if (theChoice == "S" || theChoice == "SOUTH")
	{
		if (m_pPlayerLoc->direct[2] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk south." << endl;
			m_pPlayerLoc = m_pPlayerLoc->direct[2];
			m_pPlayerLoc->GetDesc();
		}
	}
	else if (theChoice == "W" || theChoice == "WEST")
	{
		if (m_pPlayerLoc->direct[3] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk west." << endl;
			m_pPlayerLoc = m_pPlayerLoc->direct[3];
			m_pPlayerLoc->GetDesc();
		}
	}

}

void Map::look()
{
	m_pPlayerLoc->GetDesc();
	m_pPlayerLoc->look();
}

void Map::ground()
{
	m_pPlayerLoc->ground();
}

void Map::pick()
{
	string choice;
	cout << "Pick up which item?" << endl;
	cin >> choice;

	bool found;
	found = m_pPlayerLoc->pick(choice);

	if (found)
	{
		m_pPlayer->pick(choice);
	}
}

void Map::drop()
{
	string dropThis;
	cout << "Drop which item?: ";
	cin >> dropThis;

	bool found = m_pPlayer->dropInv(dropThis);
	if (found)
	{
		m_pPlayerLoc->popRoom(dropThis);
	}
}

void Map::playerInv()
{
	m_pPlayer->lookInv();
}

void Map::use()
{
	cout << "Use which item?" << endl;
	string useThis;
	cin >> useThis;

	bool haveItem = m_pPlayer->use(useThis);

	if (useThis == "Key")
	{
		if (m_pPlayerLoc->GetName() == "the Castle Gates" && m_pPlayerLoc->direct[0]->GetName() == "a Courtyard")
		{
			m_pPlayerLoc->direct[0]->lockUnlock();
			cout << "You unlocked the gates with the key and may enter" << endl;
			m_pPlayer->dropInv(useThis);
		}
	}
}