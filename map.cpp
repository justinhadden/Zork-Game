#include "map.h"

Map::Map()
{
	Room* field = new Room("a field", "You are standing in an open field.");
	m_AllRooms.push_back(field);
	Item* key = new Item("KEY", "KEY", "An old key(key)");
	m_AllItems.push_back(key);

	Room* forest = new Room("a Forest", "You are in a dark forest and can barely see.");
	m_AllRooms.push_back(forest);

	Room* oldcabin = new Room("an Old Cabin", "You are in the forest next to an old cabin.");
	m_AllRooms.push_back(oldcabin);
	Enemy* goblin = new Enemy("GOBLIN", "A disgusting looking goblin with a crude axe(goblin)", "goblin", 200, 25);
	m_AllEnemies.push_back(goblin);
	Item* gateKey = new Item("GATEKEY", "KEY", "The Gate Key(gatekey)");
	m_AllItems.push_back(gateKey);

	Room* mountain = new Room("a Mountain", "You are at the foot of a giant mountain.");
	m_AllRooms.push_back(mountain);
	Item* rock = new Item("ROCK", "ROCK", "A small rock(rock)");
	m_AllItems.push_back(rock);
	Item* pickaxe = new Item("PICKAXE", "WEAPON", "A rusty pickaxe(pickaxe)", "pickaxe", 2);
	m_AllItems.push_back(pickaxe);

	Room* swamp = new Room("a Swamp", "You are in a nasty swamp surrounded by flies.");
	m_AllRooms.push_back(swamp);
	Item* mudball = new Item("MUDBALL", "MUDBALL", "A nasty ball of mud(mudball)");
	m_AllItems.push_back(mudball);
	Enemy* stump = new Enemy("STUMP", "A regular tree stump(stump)", "stump", 200, 0);
	m_AllEnemies.push_back(stump);
	Item* battleaxe = new Item("BATTLEAXE", "WEAPON", "A huge battleaxe(battleaxe)", "battleaxe", 3.25);
	m_AllItems.push_back(battleaxe);

	Room* castleGates = new Room("the Castle Gates", "You are at the gates of a massive castle.");
	m_AllRooms.push_back(castleGates);

	Room* courtyard = new Room("a Courtyard behind castle gates", "You are in the courtyard of the castle", true, "GATEKEY");
	m_AllRooms.push_back(courtyard);
	Item* sword = new Item("SWORD", "WEAPON", "A magical sword(sword)", "magic sword", 3);
	m_AllItems.push_back(sword);
	Item* gold = new Item("GOLD", "TREASURE", "A gold bar!(gold)");
	m_AllItems.push_back(gold);

	Room* castleHall = new Room("a Throne Room", "You are standing in an abandoned throne room.");
	m_AllRooms.push_back(castleHall);
	Enemy* skeleton = new Enemy("SKELETON", "An armored skeleton warrior(skeleton)", "skeleton", 300, 20);
	m_AllEnemies.push_back(skeleton);
	Enemy* skeletonDog = new Enemy("DOG", "The skeletons vicous skeleton dog(dog)", "dog", 100, 30);
	m_AllEnemies.push_back(skeletonDog);
	Item* bag = new Item("BAG", "BAG", "A bag of holding(bag)", "bag", 3);
	m_AllItems.push_back(bag);

	Room* hedgeMaze1 = new Room("a hedge Maze", "You are at the begining of a hedge maze.");
	m_AllRooms.push_back(hedgeMaze1);
	Room* hedgeMaze2 = new Room("more hedge Maze", "You are standing in a hedge maze.");
	m_AllRooms.push_back(hedgeMaze2);
	Room* hedgeMaze3 = new Room("more hedge Maze", "You are standing in a hedge maze.");
	m_AllRooms.push_back(hedgeMaze3);
	Room* hedgeMaze4 = new Room("more hedge Maze", "You are standing in a hedge maze.");
	m_AllRooms.push_back(hedgeMaze4);
	Room* hedgeMaze5 = new Room("more hedge Maze", "You are standing at what appears to be the end of the hedgemaze.");
	m_AllRooms.push_back(hedgeMaze5);
	Item* magicScroll = new Item("SCROLL", "KEY", "A scroll that is glowing with magic(scroll)");
	m_AllItems.push_back(magicScroll);

	Room* magicRoom = new Room("a Magical Barrier", "You are standing in a old magicians study. There is a portal westward.", true, "SCROLL");
	m_AllRooms.push_back(magicRoom);
	Item* fireStaff = new Item("FIRESTAFF", "WEAPON", "A staff of firebolts(firestaff)", "firestaff", 4);
	m_AllItems.push_back(fireStaff);

	Room* space = new Room("A portal leading to the unknown", "You are in space. This is bad. Also the end.");
	m_AllRooms.push_back(space);

	Item* healthPotion1 = new Item("REDPOTION", "HEALTH", "A red potion(redpotion)");
	m_AllItems.push_back(healthPotion1);
	Item* healthPotion2 = new Item("REDPOTION", "HEALTH", "A red potion(redpotion)");
	m_AllItems.push_back(healthPotion2);
	Item* healthPotion3 = new Item("REDPOTION", "HEALTH", "A red potion(redpotion)");
	m_AllItems.push_back(healthPotion3);


	//Adding items to rooms
	field->addItem(key);
	mountain->addItem(rock);
	mountain->addItem(pickaxe);
	swamp->addItem(mudball);
	courtyard->addItem(gold);
	courtyard->addItem(sword);
	hedgeMaze5->addItem(magicScroll);
	hedgeMaze5->addItem(healthPotion1);
	magicRoom->addItem(fireStaff);
	magicRoom->addItem(healthPotion2);

	//Adding rewards for enemies
	stump->setReward(battleaxe);
	goblin->setReward(gateKey);
	skeleton->setReward(bag);
	skeletonDog->setReward(healthPotion3);

	//Adding enemies to rooms
	swamp->addEnemy(stump);
	oldcabin->addEnemy(goblin);
	castleHall->addEnemy(skeleton);
	castleHall->addEnemy(skeletonDog);

	//Setting adjacent rooms for each room
	field->setAdjRooms(mountain, forest, 0, 0);
	forest->setAdjRooms(oldcabin, swamp, 0, field);
	oldcabin->setAdjRooms(0, castleGates, forest, mountain);
	mountain->setAdjRooms(0, oldcabin, field, 0);
	swamp->setAdjRooms(castleGates, 0, 0, forest);
	castleGates->setAdjRooms(courtyard, 0, swamp, oldcabin);
	courtyard->setAdjRooms(castleHall, hedgeMaze1, castleGates, 0);
	castleHall->setAdjRooms(0, 0, courtyard, magicRoom);
	magicRoom->setAdjRooms(0, castleHall, 0, space);
	space->setAdjRooms(0, 0, 0, 0);

	//illogical case to make the hedgemaze confusing
	hedgeMaze1->setAdjRooms(hedgeMaze2, hedgeMaze2, hedgeMaze2, courtyard);
	hedgeMaze2->setAdjRooms(hedgeMaze3, hedgeMaze2, hedgeMaze2, hedgeMaze1);
	hedgeMaze3->setAdjRooms(hedgeMaze3, hedgeMaze4, hedgeMaze3, hedgeMaze1);
	hedgeMaze4->setAdjRooms(hedgeMaze3, hedgeMaze3, hedgeMaze4, hedgeMaze5);
	hedgeMaze5->setAdjRooms(hedgeMaze1, hedgeMaze1, hedgeMaze1, hedgeMaze1);

	string name;
	cout << "What is your name?: ";
	cin >> name;

	Player* player = new Player(name);

	m_pPlayerLoc = field;
	m_pPlayer = player;
}

Map::~Map()
{
	vector<Room*>::iterator iterRoom;
	vector<Item*>::iterator iterItem;
	vector<Enemy*>::iterator iterEnemy;

	for (iterRoom = m_AllRooms.begin(); iterRoom != m_AllRooms.end(); ++iterRoom)
	{
		delete *iterRoom;
	}
	for (iterItem = m_AllItems.begin(); iterItem != m_AllItems.end(); ++iterItem)
	{
		delete *iterItem;
	}
	for (iterEnemy = m_AllEnemies.begin(); iterEnemy != m_AllEnemies.end(); ++iterEnemy)
	{
		delete *iterEnemy;
	}
	delete m_pPlayer;
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
			cout << "The way is locked" << endl;
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
		else if (m_pPlayerLoc->getAdjRooms(1)->isLocked())
		{
			cout << "The way is locked" << endl;
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
		else if (m_pPlayerLoc->getAdjRooms(2)->isLocked())
		{
			cout << "The way is locked" << endl;
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
		else if (m_pPlayerLoc->getAdjRooms(3)->isLocked())
		{
			cout << "The way is locked" << endl;
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
	if (m_pPlayerLoc->getName() == "more hedge Maze")
	{
		cout << "You just see hedge maze in every direction. Sucks to suck." << endl;
	}
	else
	{
		m_pPlayerLoc->look();
	}
}

void Map::inspect()
{
	m_pPlayerLoc->inspect();
}

void Map::pick()
{
	if (m_pPlayer->getInvCount() >= m_pPlayer->getMaxInv())
	{
		cout << "Your inventory is full" << endl;
	}
	else
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
			m_pPlayer->setInvCount(1);
			if (takeThis->getType() == "BAG")
			{
				m_pPlayer->setMaxInv(3);
			}
		}
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
		m_pPlayer->setInvCount(-1);
		if (item->getType() == "BAG")
		{
			m_pPlayer->setMaxInv(-3);
		}
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
			if (m_pPlayerLoc->hasEnemies())
			{
				cout << "Can't unlock doors with enemies nearby." << endl;
			}
			else
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
							m_pPlayerLoc->getAdjRooms(0)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							delete item;
							m_pPlayer->setInvCount(-1);
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
							m_pPlayerLoc->getAdjRooms(1)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							delete item;
							m_pPlayer->setInvCount(-1);
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
							m_pPlayerLoc->getAdjRooms(2)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							delete item;
							m_pPlayer->setInvCount(-1);
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
							m_pPlayerLoc->getAdjRooms(3)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							delete item;
							m_pPlayer->setInvCount(-1);
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
		}
		else if (item->getType() == "HEALTH")
		{
			cout << "You feel rejuvenated!" << endl;
			m_pPlayer->damage(-100);
			item = m_pPlayer->dropItem(useThis);
			delete item;
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
	string thisOne;
	cout << "Who would you like to attack?: ";
	cin >> thisOne;
	for (int i = 0; i < thisOne.length(); ++i)
	{
		thisOne[i] = toupper(thisOne[i]);
	}
	Enemy* enemy = m_pPlayerLoc->getEnemy(thisOne);
	
	if (enemy != 0)
	{
		string answer;
		cout << "Are you sure you want to attack the " << enemy->getShortDesc() << "?(y/n): ";
		cin >> answer;
		answer = toupper(answer[0]);

		if (answer[0] == 'y' || answer[0] == 'Y')
		{
			int attack = m_pPlayer->getAttack();
			int attackMod = 1;
			while (answer[0] != 'N')
			{
				if (m_pPlayer->hasWeaponEquiped())
				{
					attackMod = m_pPlayer->getAttackMod();
				}
				enemy->damage(attack * attackMod);

				cout << "You attack the " << enemy->getShortDesc() << " for " << attack * attackMod << " damage." << endl;
				if (!m_pPlayer->hasWeaponEquiped())
				{
					cout << "You hurt your fists" << endl;
					m_pPlayer->damage(5);
					cout << "You have " << m_pPlayer->getHealth() << " health left." << endl;
				}
				if (enemy->getAttack() == 0)
				{
					cout << "The " << enemy->getShortDesc() << " does not fight back." << endl;
				}
				else if (enemy->getHealth() > 0)
				{
					m_pPlayer->damage(enemy->getAttack());
					cout << "The " << enemy->getShortDesc() << " hit you for " << enemy->getAttack() << " damage." << endl;
					cout << "You have " << m_pPlayer->getHealth() << " health left." << endl;
				}
				if (m_pPlayer->getHealth() <= 0)
				{
					cout << "You have been slain." << endl;
					break;
				}
				else if (enemy->getHealth() > 0)
				{
					cout << "Attack again?(y/n): ";
					cin >> answer;
					answer = toupper(answer[0]);
				}
				else
				{
					cout << "The " << enemy->getName() << " has been slain and has dropped " << enemy->getReward()->getDesc() << " as loot!" << endl;
					answer = "N";
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
			m_pPlayerLoc->addItem(enemy->getReward());
			delete enemy;
		}
	}
	else
	{
		cout << "That enemy isn't in here" << endl;
	}
}
