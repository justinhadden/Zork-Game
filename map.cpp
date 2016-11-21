#include "map.h"

Map::Map()//The Map constructor builds the rooms/items/enemies as well as places them all
{
	//Starting room
	Room* field = new Room("a field", "You are standing in an open field.", "You see a grassy field full of grasshoppers and birds\nchirping as they are flying by.");
	m_AllRooms.push_back(field);
	Item* key = new Item("KEY", "KEY", "An old key(key)");
	m_AllItems.push_back(key);

	//First forest
	Room* forest = new Room("a Forest", "You are in a dark forest and can barely see.", "It's hard to see but you can make out a\nbloody mess on the ground.");
	m_AllRooms.push_back(forest);
	Item* note = new Item("NOTE", "NOTE", "A note covered in blood(note)", "note", 0, "Today we encountered the horrible goblin that stole the gate key to the castle.\nHe has taken refuge in an old cabin to the north.\nOne by one my collegues fell to his crude axe.\nI'm going to journey south and see if I can find the famed\nbattle axe of killinating to defeat him.\nIf I don't return, please tell my king of\nthe courage and loyalty I had in pursing his will.");
	m_AllItems.push_back(note);

	//second and third forest
	Room* moreForest = new Room("a blood trail", "You travel deeper into the forest.", "You see a bloody trail heading south");
	m_AllRooms.push_back(moreForest);
	Room* southForest = new Room("a bloodtrail", "You and at the southern end of the forest.", "The forest seems to open up to the west and south.\nThe bloody trail heads west.");
	m_AllRooms.push_back(southForest);

	//Canyon and canyon floor with armor
	Room* canyon = new Room("a canyon", "You are standing at the edge of a steep canyon.", "It's a long way down the canyon but the rope should help.");
	m_AllRooms.push_back(canyon);	
	Room* canyonFloor = new Room("the canyon floor", "You made it to the bottom of the canyon.", "Looks like a knight might have fallen down this canyon.", "Amongst the rubble you see: ", true, "ROPE");
	m_AllRooms.push_back(canyonFloor);
	Item* armor = new Item("PLATE", "ARMOR", "A set of platemail(plate)", "platemail", 5);
	m_AllItems.push_back(armor);

	//Cave section with riddle room and treasure room
	Room* caveEntrance = new Room("the entrance to a cave", "You are at the entrance to a cave.", "There is an old man with a long beard standing at the intrance.\nHe says the answer to the riddle will get you\nwhat you seek then throws a small note at you.");
	m_AllRooms.push_back(caveEntrance);
	Item* riddleNote = new Item("RIDDLE", "NOTE", "A note with a riddle(riddle)", "note", 0, "I have lots to say but never speak, I open but you cannot\nwalk through me, I have a spine but no bones.");
	m_AllItems.push_back(riddleNote);
	Room* cave = new Room("a cave", "You are standing in the cave.", "There are a few items on the ground.\nThe riddle probably will tell you which item to pick up.\nThe knight looks like she chose the wrong item.\nBy that I mean she is very dead.", "Sitting on small collumns you see: ");
	m_AllRooms.push_back(cave);
	Item* book = new Item("BOOK", "CORRECT", "A book with weird symbols on the cover(book)");
	m_AllItems.push_back(book);
	Item* hourGlass = new Item("HOURGLASS", "DIE", "An hourglass dripping sand(hourglass)");
	m_AllItems.push_back(hourGlass);
	Item* skull = new Item("SKULL", "DIE", "A white skull with it's mouth agape(skull)");
	m_AllItems.push_back(skull);
	Item* painting = new Item("PAINTING", "DIE", "A painting of an old women(painting)");
	m_AllItems.push_back(painting);
	Room* treasureRoom = new Room("a treasure room", "You are in the treasure room of the cave.", "There is a weapon stand holding an impressive looking battleaxe.", "In the cave you see: ", true, "BOOK");
	m_AllRooms.push_back(treasureRoom);
	Item* battleaxe = new Item("BATTLEAXE", "WEAPON", "The Battleaxe of Killinating(battleaxe)", "battleaxe", 5);
	m_AllItems.push_back(battleaxe);

	//Old cabin with goblin carrying gatekey
	Room* oldcabin = new Room("an Old Cabin", "You are in the forest next to an old cabin.", "In this thick forest you see an old cabin\nthat is being occupied by the goblin.");
	m_AllRooms.push_back(oldcabin);
	Enemy* goblin = new Enemy("GOBLIN", "A disgusting looking goblin with a crude axe(goblin)", "goblin", 200, 25);
	m_AllEnemies.push_back(goblin);
	Item* gateKey = new Item("GATEKEY", "KEY", "The Gate Key(gatekey)");
	m_AllItems.push_back(gateKey);

	//mountain with pickaxe
	Room* mountain = new Room("a Mountain", "You are at the foot of a giant mountain.", "At the foot of the mountain it appears miners\nhave been picking away at the stone.");
	m_AllRooms.push_back(mountain);
	Item* rock = new Item("ROCK", "ROCK", "A small rock(rock)");
	m_AllItems.push_back(rock);
	Item* pickaxe = new Item("PICKAXE", "WEAPON", "A rusty pickaxe(pickaxe)", "pickaxe", 2);
	m_AllItems.push_back(pickaxe);

	//Swamp with stump containing rope for canyon
	Room* swamp = new Room("a Swamp", "You are in a nasty swamp surrounded by flies.", "This nasty swamp is so smelly but this stump\nlooks like someone has stashed somthing in it.");
	m_AllRooms.push_back(swamp);
	Item* mudball = new Item("MUDBALL", "MUDBALL", "A nasty ball of mud(mudball)");
	m_AllItems.push_back(mudball);
	Enemy* stump = new Enemy("STUMP", "A regular tree stump(stump)", "stump", 200, 0);
	m_AllEnemies.push_back(stump);
	Item* rope = new Item("ROPE", "KEY", "A rope coil(rope)");
	m_AllItems.push_back(rope);

	//Castle section requiring gatekey 
	Room* castleGates = new Room("the Castle Gates", "You are at the gates of a massive castle towards the north.", "The castle gates look old but the old\nlock still looks strong.");
	m_AllRooms.push_back(castleGates);
	Room* courtyard = new Room("a Courtyard behind castle gates", "You are in the courtyard of the castle.", "This courtyard looks like is used to be a busy place.", "On some of the merchant stands you see: ", true, "GATEKEY");
	m_AllRooms.push_back(courtyard);
	Item* sword = new Item("SWORD", "WEAPON", "A magical sword(sword)", "magic sword", 6);
	m_AllItems.push_back(sword);
	Item* gold = new Item("GOLD", "TREASURE", "A gold bar!(gold)");
	m_AllItems.push_back(gold);

	//Castle interior with two enemies 
	Room* castleHall = new Room("a Throne Room", "You are standing in an abandoned throne room.", "This throne room doesn't look like it's in as\nbad of shape as the rest of the castle.");
	m_AllRooms.push_back(castleHall);
	Enemy* skeleton = new Enemy("SKELETON", "An armored skeleton warrior(skeleton)", "skeleton", 300, 20);
	m_AllEnemies.push_back(skeleton);
	Enemy* skeletonDog = new Enemy("DOG", "The skeletons vicous skeleton dog(dog)", "dog", 100, 30);
	m_AllEnemies.push_back(skeletonDog);
	Item* bag = new Item("BAG", "BAG", "A bag of holding(bag)", "bag", 3);
	m_AllItems.push_back(bag);

	//Hedge maze with scroll to open magic door in castle
	Room* hedgeMaze1 = new Room("a hedge Maze", "You are at the begining of a hedge maze.", "This hedgemaze is pretty overgrown.");
	m_AllRooms.push_back(hedgeMaze1);
	Room* hedgeMaze2 = new Room("more hedge Maze", "You are standing in a hedge maze.", "You can't tell any difference in the hedgemaze");
	m_AllRooms.push_back(hedgeMaze2);
	Room* hedgeMaze3 = new Room("more hedge Maze", "You are standing in a hedge maze.", "You can't tell any difference in the hedgemaze");
	m_AllRooms.push_back(hedgeMaze3);
	Room* hedgeMaze4 = new Room("more hedge Maze", "You are standing in a hedge maze.", "You can't tell any difference in the hedgemaze");
	m_AllRooms.push_back(hedgeMaze4);
	Room* hedgeMaze5 = new Room("more hedge Maze", "You are standing at what appears to be the end of the hedgemaze.", "There is a pedestal standing with a\nbust of what could be the king.", "Next to the pedestal you see: ");
	m_AllRooms.push_back(hedgeMaze5);
	Item* magicScroll = new Item("SCROLL", "KEY", "A scroll that is glowing with magic(scroll)");
	m_AllItems.push_back(magicScroll);

	//Magic room with ult weapon firestaff
	Room* magicRoom = new Room("a Magical Barrier", "You are standing in a old magicians study. There is a portal westward.", "Looks like this place is definitely lived in.\nThe torches are still warm.", "On the wooden tables you see: ", true, "SCROLL");
	m_AllRooms.push_back(magicRoom);
	Item* fireStaff = new Item("FIRESTAFF", "WEAPON", "A staff of firebolts(firestaff)", "firestaff", 7);
	m_AllItems.push_back(fireStaff);

	//The end
	Room* space = new Room("A portal leading to the unknown", "You are in space. This is bad. Also the end.", "Seriously...    this is the end.\n\nGood job.\n");
	m_AllRooms.push_back(space);

	//Health potions to scatter around
	Item* healthPotion1 = new Item("REDPOTION", "HEALTH", "A red potion(redpotion)");
	m_AllItems.push_back(healthPotion1);
	Item* healthPotion2 = new Item("REDPOTION", "HEALTH", "A red potion(redpotion)");
	m_AllItems.push_back(healthPotion2);
	Item* healthPotion3 = new Item("REDPOTION", "HEALTH", "A red potion(redpotion)");
	m_AllItems.push_back(healthPotion3);
	

	//Adding items to rooms
	field->addItem(key);
	forest->addItem(note);
	mountain->addItem(rock);
	mountain->addItem(pickaxe);
	swamp->addItem(mudball);
	courtyard->addItem(gold);
	courtyard->addItem(sword);
	hedgeMaze5->addItem(magicScroll);
	hedgeMaze5->addItem(healthPotion1);
	magicRoom->addItem(fireStaff);
	magicRoom->addItem(healthPotion2);
	caveEntrance->addItem(riddleNote);
	cave->addItem(book);
	cave->addItem(hourGlass);
	cave->addItem(skull);
	cave->addItem(painting);
	treasureRoom->addItem(battleaxe);
	canyonFloor->addItem(armor);

	//Adding rewards for enemies
	stump->setReward(rope);
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
	forest->setAdjRooms(oldcabin, swamp, moreForest, field);
	moreForest->setAdjRooms(forest, 0, southForest, 0);
	southForest->setAdjRooms(moreForest, 0, canyon, caveEntrance);
	caveEntrance->setAdjRooms(0, southForest, 0, cave);
	cave->setAdjRooms(0, caveEntrance, 0, treasureRoom); 
	treasureRoom->setAdjRooms(0, cave, 0, 0);
	canyon->setAdjRooms(southForest, 0, canyonFloor, 0);
	canyonFloor->setAdjRooms(canyon, 0, 0, 0);
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

	cout << "--------------------------------" << endl;
	string name;
	cout << "What is your name?: ";
	cin >> name;

	Player* player = new Player(name);

	m_pPlayerLoc = field;
	m_pPlayer = player;
}

Map::~Map()
{
	//Delee items/rooms/enemies from rooms and inventory
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

string Map::getName()//Returns player name
{
	return m_pPlayer->getName();
}

void Map::move(string theChoice)//moves player to room chosen
{
	if (theChoice == "N" || theChoice == "NORTH")
	{
		if (m_pPlayerLoc->getAdjRooms(0) == 0)//If the direction chosen is 0 then the room doesn't exist
		{
			cout << "You can't go that way" << endl;
		}
		else if (m_pPlayerLoc->getAdjRooms(0)->isLocked())//If the direction chosen is locked
		{
			cout << "The way is locked" << endl;
		}
		else if (!m_pPlayerLoc->getAdjRooms(0)->beenHere())//If the pler hasn't been there
		{
			cout << "You walk north." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(0);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
			m_pPlayerLoc->inspect();
			m_pPlayerLoc->flipBeenHere();//beenthere() flips a flag that lets the game know the player has been here
		}
		else//Gives less information the second time you enter a room
		{
			cout << "You walk north." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(0);
			m_pPlayerLoc->getDesc();
		}
	}
	else if (theChoice == "E" || theChoice == "EAST")//Same as north
	{
		if (m_pPlayerLoc->getAdjRooms(1) == 0)
		{
			cout << "You can't go that way" << endl;
		}
		else if (m_pPlayerLoc->getAdjRooms(1)->isLocked())
		{
			cout << "The way is locked" << endl;
		}
		else if (!m_pPlayerLoc->getAdjRooms(1)->beenHere())
		{
			cout << "You walk east." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(1);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
			m_pPlayerLoc->inspect();
			m_pPlayerLoc->flipBeenHere();
		}
		else
		{
			cout << "You walk east." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(1);
			m_pPlayerLoc->getDesc();
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
		else if (!m_pPlayerLoc->getAdjRooms(2)->beenHere())
		{
			cout << "You walk south." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(2);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
			m_pPlayerLoc->inspect();
			m_pPlayerLoc->flipBeenHere();
		}
		else
		{
			cout << "You walk south." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(2);
			m_pPlayerLoc->getDesc();
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
		else if (!m_pPlayerLoc->getAdjRooms(3)->beenHere())
		{
			cout << "You walk west." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(3);
			m_pPlayerLoc->getDesc();
			m_pPlayerLoc->listEnemies();
			m_pPlayerLoc->inspect();
			m_pPlayerLoc->flipBeenHere();
		}
		else
		{
			cout << "You walk west." << endl;
			m_pPlayerLoc = m_pPlayerLoc->getAdjRooms(3);
			m_pPlayerLoc->getDesc();
		}
		if (m_pPlayerLoc->getName() == "the entrance to a cave")
		{
			m_pPlayerLoc->getAreaDesc("The old man just stares at you...");
		}
	}

}

void Map::look()//Look to see what directions you can go
{
	//Made a few special situations
	if (m_pPlayerLoc->getName() == "more hedge Maze")
	{
		cout << "You just see hedge maze in every direction. Sucks to suck." << endl;
	}
	else if (m_pPlayerLoc->getName() == "A portal leading to the unknown")
	{
		cout << "You are in space. Enjoy no gravity...      and a cold icy death.\n\nThe end\n" << endl;
	}
	else
	{
		m_pPlayerLoc->look();
	}
}

void Map::inspect()//Inspect gives information about room 
{

	//Special situation for the canyon to allow player to try to jump down the canyon
	if (m_pPlayerLoc->getName() == "a canyon")
	{
		if (m_pPlayerLoc->getAdjRooms(2)->isLocked())
		{
			string answer;
			cout << "You look down the canyon and can make out\nsomething shiny at the bottom.\nBut it's probably at least 200ft down." << endl;
			cout << "Do you wanna jump down an try to get it?(y/n): ";
			cin >> answer;
			answer = toupper(answer[0]);
			if (answer[0] == 'Y')
			{
				cout << "You try to jump down the 200ft canyon \nlike an idiot and die because gravity." << endl;
				m_pPlayer->damage(100);
			}
			else
			{
				cout << "Wussy." << endl;
			}
		}
		else
		{
			m_pPlayerLoc->inspect();
		}
	}
	else
	{
		m_pPlayerLoc->inspect();
	}
}

void Map::pick()//used to take item from a room
{
	if (m_pPlayer->getInvCount() >= m_pPlayer->getMaxInv())//checks for space in your inventory
	{
		cout << "Your inventory is full" << endl;
	}
	else if (m_pPlayerLoc->roomHasItems())
	{
		string choice;
		cout << "Take which item?: ";
		cin >> choice;

		for (unsigned int i = 0; i <= choice.length(); ++i)
		{
			choice[i] = toupper(choice[i]);
		}

		bool found;
		found = m_pPlayerLoc->hasItem(choice);//Makes sure that item exist in the room

		if (found)
		{
			Item* takeThis = m_pPlayerLoc->getItem(choice);
			m_pPlayer->pick(takeThis);
			m_pPlayer->setInvCount(1);

			//A few special situation picks
			if (takeThis->getType() == "BAG")//Picking up the bag gives a few extra spaces in your inventory
			{
				m_pPlayer->setMaxInv(3);
			}
			if (takeThis->getType() == "DIE")//Choosing the wrong item in the cave kills you 
			{
				cout << "You feel funny. The world goes dark.\nYou are dead." << endl;
				getPlayer()->damage(105);
			}
			if (takeThis->getType() == "CORRECT")//the right one opens the hidden door
			{
				cout << "A hidden door to the west clicks open" << endl;
				m_pPlayerLoc->getAdjRooms(3)->lockUnlock();
				m_pPlayerLoc->getAdjRooms(1)->getAreaDesc("The old man has vanished!");
			}
		}
	}
	else
	{
		cout << "Nothing here." << endl;
	}
}

void Map::drop()//Drop an item from your inventory
{
	string dropThis;
	cout << "Drop which item?: ";
	cin >> dropThis;

	for (unsigned int i = 0; i <= dropThis.length(); ++i)
	{
		dropThis[i] = toupper(dropThis[i]);
	}

	bool found = m_pPlayer->hasItem(dropThis);//Makes sure the player has item to drop
	if (found)
	{
		Item* item = m_pPlayer->dropItem(dropThis);
		m_pPlayerLoc->addItem(item);
		m_pPlayer->setInvCount(-1);
		if (item->getType() == "BAG")//If player drops bag remove extra inventory spaces
		{
			m_pPlayer->setMaxInv(-3);
		}
	}
}

void Map::playerInv()//Used to show character info items/health/attack/armor
{
	m_pPlayer->lookInv();
}

void Map::use()//Use an item in the players inventory
{
	cout << "Use which item?: ";
	string useThis;
	cin >> useThis;

	for (unsigned int i = 0; i <= useThis.length(); ++i)
	{
		useThis[i] = toupper(useThis[i]);
	}

	bool haveItem = m_pPlayer->hasItem(useThis);//Makes sure the player has item

	if (haveItem)
	{
		Item* item = m_pPlayer->getItem(useThis);//Gets item from inventory
		if (item->getType() == "KEY")//Decision structure for if the item is of type 'key'
		{
			if (m_pPlayerLoc->hasEnemies())//Don't allow unlocking doors with in the room
			{
				cout << "Can't unlock doors with enemies nearby." << endl;
			}
			else if (item->getName() == "ROPE")//structure for is the item is a rope
			{
				if (m_pPlayerLoc->getName() == "a canyon")
				{
					m_pPlayerLoc->getAdjRooms(2)->lockUnlock();
					m_pPlayerLoc->getAdjRooms(2)->getName("(Roped)");
					cout << "You tie the rope off and toss it down to the canyon floor." << endl;
					m_pPlayer->dropItem(useThis);
					m_pPlayer->setInvCount(-1);
				}
				else
				{
					cout << "The rope just sits there and does nothing special so you pick it back up." << endl;
				}
			}
			else//Structure for the plain keys. Checks each direction for locks and lock types.
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

					for (unsigned int i = 0; i <= theChoice.length(); ++i)
					{
						theChoice[i] = toupper(theChoice[i]);
					}

					if (theChoice == "N" || theChoice == "NORTH")
					{
						if (m_pPlayerLoc->getAdjRooms(0) == 0)//If the direction choosen isn't a room
						{
							cout << "That's not locked" << endl;							
						}
						else if (item->getName() == m_pPlayerLoc->getAdjRooms(0)->getLockType())//If the key matches the rooms locktype
						{
							m_pPlayerLoc->getAdjRooms(0)->lockUnlock();//Unlock room
							m_pPlayerLoc->getAdjRooms(0)->getName("(Opened)");//Add a (Opened) to room name
							cout << "Door unlocked." << endl;//Let the player know it worked
							item = m_pPlayer->dropItem(useThis);//Remove item... don't know if this is the right thing to do yet. 
							m_pPlayer->setInvCount(-1);
						}
						else
						{
							cout << "The key doesn't seem to help you here." << endl;
						}
					}
					else if (theChoice == "E" || theChoice == "EAST")//Each direction is the same as north
					{
						if (m_pPlayerLoc->getAdjRooms(1) == 0)
						{
							cout << "That's not locked" << endl;
						}
						else if (item->getName() == m_pPlayerLoc->getAdjRooms(1)->getLockType())
						{
							m_pPlayerLoc->getAdjRooms(1)->lockUnlock();
							m_pPlayerLoc->getAdjRooms(1)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							m_pPlayer->setInvCount(-1);
						}
						else
						{
							cout << "The key doesn't seem to help you here." << endl;
						}
					}
					else if (theChoice == "S" || theChoice == "SOUTH")
					{
						if (m_pPlayerLoc->getAdjRooms(2) == 0)
						{
							cout << "That's not locked" << endl;
						}
						else if (item->getName() == m_pPlayerLoc->getAdjRooms(2)->getLockType())
						{
							m_pPlayerLoc->getAdjRooms(2)->lockUnlock();
							m_pPlayerLoc->getAdjRooms(2)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							m_pPlayer->setInvCount(-1);
						}
						else
						{
							cout << "The key doesn't seem to help you here." << endl;
						}
					}
					else if (theChoice == "W" || theChoice == "WEST")
					{
						if (m_pPlayerLoc->getAdjRooms(3) == 0)
						{
							cout << "That's not locked" << endl;
						}
						else if (item->getName() == m_pPlayerLoc->getAdjRooms(3)->getLockType())
						{
							m_pPlayerLoc->getAdjRooms(3)->lockUnlock();
							m_pPlayerLoc->getAdjRooms(3)->getName("(Opened)");
							cout << "Door unlocked." << endl;
							item = m_pPlayer->dropItem(useThis);
							m_pPlayer->setInvCount(-1);
						}
						else
						{
							cout << "The key doesn't seem to help you here." << endl;
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
		else if (item->getType() == "HEALTH")//If item being used is a health item
		{
			cout << "You feel rejuvenated!" << endl;
			m_pPlayer->damage(-100);
			item = m_pPlayer->dropItem(useThis);
		}
		else if (item->getType() == "NOTE")//If item is of type note
		{
			cout << "The " << item->getShortDesc() << " reads: " << endl;
			cout << item->getScribe() << endl;
		}
		else
		{
			cout << "Can't use that here." << endl;
		}
	}
}

Room* Map::getPlayerLoc()//Returns the players location
{
	return m_pPlayerLoc;
}

Player* Map::getPlayer()//Returns the player
{
	return m_pPlayer;
}

void Map::attackEnemy()//Attack got pretty complicated. Need to look at this again!!!!
{
	//gamecontrol has already made sure there is an enemy in the room
	string thisOne;
	cout << "Who would you like to attack?: ";
	cin >> thisOne;
	for (unsigned int i = 0; i < thisOne.length(); ++i)
	{
		thisOne[i] = toupper(thisOne[i]);
	}
	Enemy* enemy = m_pPlayerLoc->getEnemy(thisOne);//Get enemy returns 0 if the enemy choosen doesn't exist or actually removes enemy from room is it does.
	
	if (enemy != 0)//If the enemy you chose to attack exists
	{
		string answer;
		cout << "Are you sure you want to attack the " << enemy->getShortDesc() << "?(y/n): ";//answer to loop combat
		cin >> answer;
		answer = toupper(answer[0]);//Only toupper the first letter to check for just the 'y'

		if (answer[0] == 'y' || answer[0] == 'Y')
		{
			int attack = m_pPlayer->getAttack();
			int attackMod = 1;//Attack mod defaults to nothing
			while (answer[0] != 'N')
			{
				if (m_pPlayer->hasWeaponEquiped())//If player has a weapon equipped the set attack mod
				{
					attackMod = m_pPlayer->getAttackMod();
				}
				enemy->damage(attack * attackMod);//Actual damage being done

				cout << "You attack the " << enemy->getShortDesc() << " for " << attack * attackMod << " damage." << endl;//Tell player what happened
				if (!m_pPlayer->hasWeaponEquiped() && !m_pPlayer->hasArmorEquiped())//If player didn't have weapon punish player
				{
					cout << "You hurt your fists" << endl;
					m_pPlayer->damage(5);
					cout << "You have " << m_pPlayer->getHealth() << " health left." << endl;
				}
				if (enemy->getAttack() == 0)//As of 11/21/2016 only the stump uses this
				{
					cout << "The " << enemy->getShortDesc() << " does not fight back." << endl;
				}
				else if (enemy->getHealth() > 0 && m_pPlayer->hasArmorEquiped())//Attack for if enemy still alive and player has armor
				{
					m_pPlayer->damage(enemy->getAttack());
					cout << "The " << enemy->getShortDesc() << " hit you for " << enemy->getAttack() - m_pPlayer->getArmorMod() << " damage." << endl;
					cout << "You have " << m_pPlayer->getHealth() << " health left." << endl;
				}
				else if (enemy->getHealth() > 0)//Attack for if enemy still alive and player has NO armor
				{
					m_pPlayer->damage(enemy->getAttack());
					cout << "The " << enemy->getShortDesc() << " hit you for " << enemy->getAttack() << " damage." << endl;
					cout << "You have " << m_pPlayer->getHealth() << " health left." << endl;
				}
				if (m_pPlayer->getHealth() <= 0)//After all attacks are done check if player is dead.
				{
					cout << "You have been slain." << endl;
					break;
				}
				else if (enemy->getHealth() > 0)//If enemy is still alive check for continued attack
				{
					cout << "Attack again?(y/n): ";
					cin >> answer;
					answer = toupper(answer[0]);
				}
				else//If the enemy was killed then let player know and show reward
				{
					cout << "The " << enemy->getName() << " has been slain and has dropped " << enemy->getReward()->getDesc() << " as loot!" << endl;
					answer = "N";
				}
			}
		}
		else if (answer == "X" || answer == "x")//Cheats!!!
		{
			cout << "You fucked that guy. He's dead now." << endl;
			enemy->damage(10000);
		}
		else if (answer == "n" || answer == "N")//Insult for not fighting
		{
			cout << "Wussy" << endl;
		}
		else
		{
			cout << "--------------------------------" << endl;
			cout << "I do not recognize that command" << endl;
			cout << "--------------------------------" << endl;
		}
		if (enemy->getHealth() > 0)//If player leaves combat and enemy is still alive place enemy back in the room
		{
			m_pPlayerLoc->addEnemy(enemy);
		}
		else//If enemy was killed drop item in room
		{
			m_pPlayerLoc->addItem(enemy->getReward());
		}
	}
	else//if getenemy() returned 0 then enemy doesn't exist
	{
		cout << "That enemy isn't in here" << endl;
	}
}
