#include "map.h"

Map::Map()
{
	Room* house = new Room("a House in a field", "You are in a field with a house in the middle of it.");
	Item* key = new Item("KEY", "KEY", "An old key(key)");

	Room* forest = new Room("a Forest", "You are in a dark forest and can barely see.");

	Room* oldcabin = new Room("an Old Cabin", "You are in the forest next to and old cabin.");
	Item* gateKey = new Item("GATEKEY", "KEY", "The Gate Key(gatekey)");

	Room* mountain = new Room("a Mountain", "You are at the foot of a giant mountain.");
	Item* rock = new Item("ROCK", "ROCK", "A small rock(rock)");
	Item* pickaxe = new Item("PICKAXE", "WEAPON", "A rusty pickaxe(pickaxe)", "pickaxe", 2);

	Room* swamp = new Room("a Swamp", "You are in a nasty swamp surrounded by flies.");
	Item* mudball = new Item("MUDBALL", "MUDBALL", "A nasty ball of mud(mudball)");
	Enemy* stump = new Enemy("Stump", "A regular tree stump", 200, 0);

	Room* castleGates = new Room("the Castle Gates", "You are at the gates of a massive castle.");

	Room* courtyard = new Room("a Courtyard", "You are in the courtyard of the castle", true, "GATEKEY");
	Item* sword = new Item("SWORD", "WEAPON", "A magical sword(sword)", "magic sword", 3);
	Item* gold = new Item("GOLD", "TREASURE", "A gold bar!(gold)");


	//Adding items to rooms
	house->addItem(key);
	oldcabin->addItem(gateKey);
	mountain->addItem(rock);
	mountain->addItem(pickaxe);
	swamp->addItem(mudball);
	courtyard->addItem(gold);
	courtyard->addItem(sword);

	//Adding enemies to rooms
	swamp->addEnemy(stump);

	//Setting adjacent rooms for each room
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
	return m_pPlayer->getName();
}

void Map::move(string theChoice)
{
	if (theChoice == "N" || theChoice == "NORTH")
	{
		if (m_pPlayerLoc->getAdjRooms(0) == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else if (m_pPlayerLoc->getAdjRooms(0)->isLocked())
		{
			cout << "The gates are locked" << endl;
		}
		else
		{
			cout << "You walk north." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(0);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
		}
	}
	else if (theChoice == "E" || theChoice == "EAST")
	{
		if (m_pPlayerLoc->getAdjRooms(1) == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk east." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(1);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
		}
	}
	else if (theChoice == "S" || theChoice == "SOUTH")
	{
		if (m_pPlayerLoc->getAdjRooms(2) == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk south." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(2);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
		}
	}
	else if (theChoice == "W" || theChoice == "WEST")
	{
		if (m_pPlayerLoc->getAdjRooms(3) == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else
		{
			cout << "You walk west." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(3);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
		}
	}

}

void Map::look()
{
	m_pPlayerLoc->look();
}

void Map::inspect()
{
	m_pPlayerLoc->inspect();
}

void Map::pick()
{
	string choice;
	cout << "Take which item?: ";
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

	bool found = m_pPlayer->hasItem(dropThis);
	if (found)
	{
		Item* item = m_pPlayer->dropItem(dropThis);
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

	bool haveItem = m_pPlayer->hasItem(useThis);

	if (haveItem)
	{
		Item* item = m_pPlayer->getItem(useThis);
		if (item->getType() == "KEY")
		{
			bool lockedDoors = false;
			for (int i = 0; i < 4; ++i)
			{
				if (m_pPlayerLoc->getAdjRooms(i) != 0)
				{
					if (m_pPlayerLoc->getAdjRooms(i)->isLocked())
					{
						lockedDoors = true;
					}
				}
			}
			if (lockedDoors)
			{
				string theChoice;
				cout << "Which door would you like to open?(n/e/s/w)" << endl;
				cin >> theChoice;

				for (int i = 0; i <= theChoice.length(); ++i)
				{
					theChoice[i] = toupper(theChoice[i]);
				}

				if (theChoice == "N" || theChoice == "NORTH")
				{
					if (item->getName() == m_pPlayerLoc->getAdjRooms(0)->getLockType())
					{
						m_pPlayerLoc->getAdjRooms(0)->lockUnlock();
						cout << "Door unlocked. Key was removed." << endl;
						item = m_pPlayer->dropItem(useThis);
						delete item;
					}
					else
					{
						cout << "Wrong key." << endl;
					}
				}
				else if (theChoice == "E" || theChoice == "EAST")
				{
					if (item->getName() == m_pPlayerLoc->getAdjRooms(1)->getLockType())
					{
						m_pPlayerLoc->getAdjRooms(1)->lockUnlock();
						cout << "Door unlocked." << endl;
					}
					else
					{
						cout << "Wrong key." << endl;
					}
				}
				else if (theChoice == "S" || theChoice == "SOUTH")
				{
					if (item->getName() == m_pPlayerLoc->getAdjRooms(2)->getLockType())
					{
						m_pPlayerLoc->getAdjRooms(2)->lockUnlock();
						cout << "Door unlocked." << endl;
					}
					else
					{
						cout << "Wrong key." << endl;
					}
				}
				else if (theChoice == "W" || theChoice == "WEST")
				{
					if (item->getName() == m_pPlayerLoc->getAdjRooms(3)->getLockType())
					{
						m_pPlayerLoc->getAdjRooms(3)->lockUnlock();
						cout << "Door unlocked." << endl;
					}
					else
					{
						cout << "Wrong key." << endl;
					}
				}
				else
				{
					cout << "--------------------------------" << endl;
					cout << "I do not recognize that command" << endl;
					cout << "--------------------------------" << endl;
				}
			}
			else
			{
				cout << "There are no locked doors here." << endl;
			}
		}
		else
		{
			cout << "Can't use that here." << endl;
		}
	}
}

Room* Map::getPlayerLoc()
{
	return m_pPlayerLoc;
}

Player* Map::getPlayer()
{
	return m_pPlayer;
}

void Map::attackEnemy()
{
	Enemy* enemy = m_pPlayerLoc->getEnemy();
	
	string answer;
	cout << "Are you sure you want to attack the " << enemy->getName() << "?(y/n)";
	cin >> answer;

	if (answer == "y" || answer == "Y")
	{
		int attack = m_pPlayer->getAttack();
		int attackMod = 1;
		while (answer != "n")
		{
			if (m_pPlayer->hasWeapon())
			{
				attackMod = m_pPlayer->getAttackMod();
			}
			enemy->damage(attack * attackMod);

			cout << "You attack the " << enemy->getName() << " for " << attack * attackMod << " damage." << endl;
			if (enemy->getAttack() == 0)
			{
				cout << "The " << enemy->getName() << " does not fight back." << endl;
			}
			else
			{
				m_pPlayer->damage(enemy->getAttack());
				cout << "The " << enemy->getName() << " hit you for " << enemy->getAttack() << " damage." << endl;
				cout << "You have " << m_pPlayer->getHealth() << " health left." << endl;
			}
			if (enemy->getHealth() > 0)
			{
				cout << "Attack again?(y/n): ";
				cin >> answer;
			}
			else
			{
				cout << "The " << enemy->getName() << " has been slain." << endl;
				answer = "n";
			}
		}
	}
	else if (answer == "n" || answer == "N")
	{
		cout << "Wussy" << endl;
	}
	else
	{
		cout << "--------------------------------" << endl;
		cout << "I do not recognize that command" << endl;
		cout << "--------------------------------" << endl;
	}
	if (enemy->getHealth() > 0)
	{
		m_pPlayerLoc->addEnemy(enemy);
	}
	else
	{
		delete enemy;
	}

}
