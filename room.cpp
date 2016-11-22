#include "room.h"

Room::Room(const string& name, const string& desc, const string& area, const string& itemLoc, bool isLocked, string lockType)//constructor for room class
	: m_Name(name)
	, m_Desc(desc)
	, m_AreaDesc(area)
	, m_ItemLoc(itemLoc)
	, m_Locked(isLocked)
	, m_LockType(lockType)
{}

void Room::setAdjRooms(Room* north, Room* east, Room* south, Room* west)//Stores adjacent rooms
{
	m_AdjRooms[0] = north;
	m_AdjRooms[1] = east;
	m_AdjRooms[2] = south;
	m_AdjRooms[3] = west;
}

void Room::getDesc()//couts the desc
{
	cout << m_Desc << endl;
}

string Room::getAreaDesc(string addThis)//Returns areadesc and has option to change areadesc
{
	m_AreaDesc = addThis;
	return m_AreaDesc;
}

string Room::getName(string addThis)//Returns room name with option to add to it
{
	m_Name = m_Name + addThis;
	return m_Name;
}

bool Room::beenHere()//Returns whether or not the player has been here before
{
	return m_BeenHere;
}

void Room::flipBeenHere()//Flips beenhere
{
	m_BeenHere = true;
}

void Room::lockUnlock()//Lock or unlock a door. Currently we only unlock doors
{
	if (m_Locked)
	{
		m_Locked = false;
	}
	else
	{
		m_Locked = true;
	}
}

bool Room::isLocked()//Returns if a room is locked
{
	return m_Locked;
}

string Room::getLockType()//Returns the lock type
{
	return m_LockType;
}

void Room::addItem(Item* item)//Add an item to a room
{
	m_Items.push_back(item);
}

void Room::addEnemy(Enemy* enemy)//Add an enemy to the room
{
	m_Enemies.push_back(enemy);
}

bool Room::roomHasItems()//Checks if the room has items
{
	bool found = true;

	if (m_Items.empty())
	{
		found = false;
	}

	return found;
}

Room* Room::getAdjRooms(int index)//Return the room selected by index
{
	return m_AdjRooms[index];
}

void Room::inspect()//prints the areadesc and a list of items in the room
{
	vector<Item*>::iterator iter;
	cout << m_AreaDesc << endl;
	if (m_Items.empty())
	{
		cout << "There are no items here" << endl;
	}
	else
	{
		cout << m_ItemLoc << endl;
		for (iter = m_Items.begin(); iter != m_Items.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

void Room::listEnemies()//lists the enemies in the room
{
	vector<Enemy*>::iterator iter;

	if (!m_Enemies.empty())
	{
		cout << "Things to fight: " << endl;
		for (iter = m_Enemies.begin(); iter != m_Enemies.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

bool Room::hasEnemies()//Returns whethor or not there are enemies in the room
{
	if (m_Enemies.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Room::hasItem(string theChoice)//Checks the room for a specific item
{
	vector<Item*>::iterator iter;
	bool found = false;

	for (iter = m_Items.begin(); iter != m_Items.end(); ++iter)
	{
		if ((*iter)->getName() == theChoice)
		{
			found = true;
		}
	}

	if (!found)
	{
		cout << "That item isn't in here." << endl;
	}

	return found;
}

void Room::look()//Look in each of the directions
{
	if (m_AdjRooms[0] != 0)
	{
		cout << "To the north you see " << m_AdjRooms[0]->m_Name << endl;
	}
	if (m_AdjRooms[1] != 0)
	{
		cout << "To the east you see " << m_AdjRooms[1]->m_Name << endl;
	}
	if (m_AdjRooms[2] != 0)
	{
		cout << "To the south you see " << m_AdjRooms[2]->m_Name << endl;
	}
	if (m_AdjRooms[3] != 0)
	{
		cout << "To the west you see " << m_AdjRooms[3]->m_Name << endl;
	}
}

Item* Room::getItem(string name)//remove an item from the room
{
	vector<Item*>::iterator iter;
	Item* item;

	for (iter = m_Items.begin(); iter != m_Items.end(); ++iter)
	{
		if ((*iter)->getName() == name)
		{
			item = *iter;
			m_Items.erase(iter);
			break;
		}
	}


	return item;
}

Enemy* Room::getEnemy(string thisOne)//remove an enemy from the room
{
	vector<Enemy*>::iterator iter;
	Enemy* enemy = 0;
	bool found = false;
	for (iter = m_Enemies.begin(); iter != m_Enemies.end(); ++iter)
	{
		if ((*iter)->getName() == thisOne)
		{
			enemy = *iter;
			m_Enemies.erase(iter);
			found = true;
			break;
		}
	}

	return enemy;
}