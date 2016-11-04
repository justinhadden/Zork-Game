#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Room
{
public:
	Room(const string& name = "", const string& desc = "");
	void setDirect(Room* north, Room* east, Room* south, Room* west);
	void look();
	void GetDesc();
	string GetName();
	void lockUnlock();
	bool locked = false;
	void popRoom(string item);
	void ground();
	bool pick(string theChoice);
	vector<Room*> direct;

private:

	vector<string> m_InRoom;
	string m_Name;
	string m_Desc;
};

Room::Room(const string& name, const string& desc)
{
	m_Name = name;
	m_Desc = desc;
}

void Room::setDirect(Room* north, Room* east, Room* south, Room* west)
{
	direct.push_back(north);
	direct.push_back(east);
	direct.push_back(south);
	direct.push_back(west);
}

void Room::GetDesc()
{
	cout << m_Desc << endl;
}

string Room::GetName()
{
	return m_Name;
}

void Room::lockUnlock()
{
	if (locked)
	{
		locked = false;
	}
	else
	{
		locked = true;
	}
}

void Room::popRoom(string item)
{
	m_InRoom.push_back(item);
}

void Room::ground()
{
	vector<string>::iterator iter;
	if (m_InRoom.begin() == m_InRoom.end())
	{
		cout << "Nothing here" << endl;
	}
	else
	{
		cout << "On the ground you see:" << endl;
		for (iter = m_InRoom.begin(); iter != m_InRoom.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
}

bool Room::pick(string theChoice)
{
	vector<string>::iterator iter;
	bool found = true;

	iter = find(m_InRoom.begin(), m_InRoom.end(), theChoice);

	if (iter == m_InRoom.end())
	{
		cout << "That item isn't in here." << endl;
		found = false;
	}
	else
	{
		m_InRoom.erase(iter);
	}

	return found;
}

void Room::look()
{
	if (direct[0] == 0)
	{
		cout << "Nothing north" << endl;
	}
	else
	{
		cout << "To the north you see " << direct[0]->m_Name << endl;
	}
	if (direct[1] == 0)
	{
		cout << "Nothing east" << endl;
	}
	else
	{
		cout << "To the east you see " << direct[1]->m_Name << endl;
	}
	if (direct[2] == 0)
	{
		cout << "Nothing south" << endl;
	}
	else
	{
		cout << "To the south you see " << direct[2]->m_Name << endl;
	}
	if (direct[3] == 0)
	{
		cout << "Nothing west" << endl;
	}
	else
	{
		cout << "To the west you see " << direct[3]->m_Name << endl;
	}
}

class Player
{
public:
	Player(string name = "");
	void pick(string theChoice);
	void lookInv();
	bool use(string useThis);
	void dropInv(string dropThis);

private:
	vector<string> m_Inventory;
	string m_Name;
};

Player::Player(string name) :
	m_Name(name)
{}

void Player::pick(string theChoice)
{
	m_Inventory.push_back(theChoice);
	cout << "Picked up " << theChoice << endl;
}

void Player::lookInv()
{
	vector<string>::iterator iter;
	if (m_Inventory.begin() == m_Inventory.end())
	{
		cout << "Nothing in your inventory" << endl;
	}
	else
	{
		cout << "Your inventory:" << endl;
		for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
}

bool Player::use(string useThis)
{
	vector<string>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), useThis);
	bool haveItem = true;
	if (iter == m_Inventory.end())
	{
		cout << "You don't have that item." << endl;
		haveItem = false;
	}

	return haveItem;
}

void Player::dropInv(string dropThis)
{
	vector<string>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), dropThis);

	if (iter == m_Inventory.end())
	{
		cout << "You don't have that Item." << endl;
	}
	else
	{
		m_Inventory.erase(iter);
		cout << dropThis << " removed from inventory." << endl;
	}
}

class Map
{
public:
	Map();
	~Map();

	void move(string theChoice, Map* theMap);
	void look();
	void ground();
	void pick();
	void playerInv();
	void use();

private:
	Player* m_pPlayer;
	Room* m_pPlayerLoc;
};

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


	Player* player = new Player("Moegy");

	m_pPlayerLoc = house;
	m_pPlayer = player;
}

Map::~Map()
{

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


class GameControl
{
public:
	void info();
	void loop(Map* theMap);

private:
	Player* m_pPlayer;
};

void GameControl::info()
{
	cout << "'Help(h)' - gives you your options" << endl;
	cout << "'Look(l)' - lets you look around" << endl;
	cout << "'North(n)/East(e)/South(s)/West(w)' - move around" << endl;
	cout << "'Ground(g)' - looks for items on the ground" << endl;
	cout << "'Pick(p)' - picks up an item from the ground" << endl;
	cout << "'Inventory(i)' - checks your inventory" << endl;
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
			theMap->move(theChoice, theMap);
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "L" || theChoice == "LOOK")
		{
			cout << "--------------------------------" << endl;
			theMap->look();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "G" || theChoice == "GROUND")
		{
			cout << "--------------------------------" << endl;
			theMap->ground();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "P" || theChoice == "PICK")
		{
			cout << "--------------------------------" << endl;
			theMap->pick();
			cout << "--------------------------------" << endl;
		}
		else if (theChoice == "I" || theChoice == "Inventory")
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
		else if (theChoice != "QUIT")
		{
			cout << "--------------------------------" << endl;
			cout << "I do not recognize that command" << endl;
			cout << "--------------------------------" << endl;
		}
	}

}

int main()
{
	Map map;

	cout << "Welcome to Zork." << endl;
	cout << "Type 'help' for a list of options" << endl;

	GameControl gameCont;
	gameCont.loop(&map);

	return 0;
}





