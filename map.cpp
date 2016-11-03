#include "map.h"

Map::Map()
{
	Room* house = new Room("a House in a field", "You are in a field with a house in the middle of it.");
	Item* key = new Item("KEY", "KEY", "An old key(key)");

	Room* forest = new Room("a Forest", "You are in a dark forest and can barely see.");

	Room* oldcabin = new Room("an Old Cabin", "You are in the forest next to and old cabin.");
	Item* gatekey = new Item("GATEKEY", "KEY", "The Gate Key(gatekey)");

	Room* mountain = new Room("a Mountain", "You are at the foot of a giant mountain.");
	Item* rock = new Item("ROCK", "ROCK", "A small rock(rock)");
	Item* pickaxe = new Item("PICKAXE", "WEAPON", "A rusty pickaxe(pickaxe)");

	Room* swamp = new Room("a Swamp", "You are in a nasty swamp surrounded by flies.");
	Item* mudball = new Item("MUDBALL", "MUDBALL", "A nasty ball of mud(mudball)");

	Room* castleGates = new Room("the Castle Gates", "You are at the gates of a massive castle.");

	Room* courtyard = new Room("a Courtyard", "You are in the courtyard of the castle");
	Item* gold = new Item("GOLD", "TREASURE", "A gold bar!(gold)");
	courtyard->lockUnlock();

	house->addItem(key);
	oldcabin->addItem(gatekey);
	mountain->addItem(rock);
	mountain->addItem(pickaxe);
	swamp->addItem(mudball);
	courtyard->addItem(gold);

	house->setAdjRooms(mountain, forest, 0, 0);
	forest->setAdjRooms(oldcabin, swamp, 0, house);
	oldcabin->setAdjRooms(0, castleGates, forest, mountain);
	mountain->setAdjRooms(0, oldcabin, house, 0);
	swamp->setAdjRooms(castleGates, 0, 0, forest);
	castleGates->setAdjRooms(courtyard, 0, swamp, oldcabin);
	courtyard->setAdjRooms(0, 0, castleGates, 0);

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

void Map::move(string theChoice)
{
	if (theChoice == "N" || theChoice == "NORTH")
	{
		if (m_pPlayerLoc->getAdjRooms()[0] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else if (m_pPlayerLoc->getAdjRooms()[0]->isLocked())
		{
			cout << "The gates are locked" << endl;
		}
		else
		{
			cout << "You walk north." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms()[0];
			m_pPlayerLoc->GetDesc();
		}
	}
	else if (theChoice == "E" || theChoice == "EAST")
	{
		if (m_pPlayerLoc->getAdjRooms()[1] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk east." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms()[1];
			m_pPlayerLoc->GetDesc();
		}
	}
	else if (theChoice == "S" || theChoice == "SOUTH")
	{
		if (m_pPlayerLoc->getAdjRooms()[2] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk south." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms()[2];
			m_pPlayerLoc->GetDesc();
		}
	}
	else if (theChoice == "W" || theChoice == "WEST")
	{
		if (m_pPlayerLoc->getAdjRooms()[3] == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk west." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms()[3];
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
	cout << "Pick up which item?: ";
	cin >> choice;

	for (int i = 0; i <= choice.length(); ++i)
	{
		choice[i] = toupper(choice[i]);
	}

	bool found;
	found = m_pPlayerLoc->hasItem(choice);

	if (found)
	{
		Item* takeThis = m_pPlayerLoc->getItem(choice);
		m_pPlayer->pick(takeThis);
	}
}

void Map::drop()
{
	string dropThis;
	cout << "Drop which item?: ";
	cin >> dropThis;

	for (int i = 0; i <= dropThis.length(); ++i)
	{
		dropThis[i] = toupper(dropThis[i]);
	}

	bool found = m_pPlayer->checkItem(dropThis);
	if (found)
	{
		Item* item = m_pPlayer->dropInv(dropThis);
		m_pPlayerLoc->addItem(item);
	}
}

void Map::playerInv()
{
	m_pPlayer->lookInv();
}

void Map::use()
{
	cout << "Use which item?: ";
	string useThis;
	cin >> useThis;

	for (int i = 0; i <= useThis.length(); ++i)
	{
		useThis[i] = toupper(useThis[i]);
	}

	bool haveItem = m_pPlayer->checkItem(useThis);

	if (haveItem)
	{
		Item* item = m_pPlayer->getItem(useThis);
		if (item->getType() == "KEY")
		{
			if (m_pPlayerLoc->GetName() == "the Castle Gates" && m_pPlayerLoc->getAdjRooms()[0]->GetName() == "a Courtyard")
			{
				if (item->getName() == "GATEKEY")
				{
					m_pPlayerLoc->getAdjRooms()[0]->lockUnlock();
					cout << "You unlocked the gates with the key and may enter." << endl;
					m_pPlayer->dropInv(useThis);
				}
				else
				{
					cout << "Wrong key." << endl;
				}
			}
			else
			{
				cout << "Can't use that here." << endl;
			}
		}
		else
		{
			cout << "Can't use that here." << endl;
		}
	}
}