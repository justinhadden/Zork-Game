#include "room.h"

Room::Room(const string& name, const string& desc, bool isLocked, string lockType)
	: m_Name(name)
	, m_Desc(desc)
	, locked(isLocked)
	, m_lockType(lockType)
{}

void Room::setAdjRooms(Room* north, Room* east, Room* south, Room* west)
{
	m_AdjRooms[0] = north;
	m_AdjRooms[1] = east;
	m_AdjRooms[2] = south;
	m_AdjRooms[3] = west;
}

void Room::getDesc()
{
	cout << m_Desc << endl;
}

string Room::getName()
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

bool Room::isLocked()
{
	return locked;
}

string Room::getLockType()
{
	return m_lockType;
}

void Room::addItem(Item* item)
{
	items.push_back(item);
}

Room* Room::getAdjRooms(int index)
{
	return m_AdjRooms[index];
}

void Room::inspect()
{
	vector<Item*>::iterator iter;
	if (items.empty())
	{
		cout << "Nothing here" << endl;
	}
	else
	{
		cout << "On the ground you see:" << endl;
		for (iter = items.begin(); iter != items.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

bool Room::hasItem(string theChoice)
{
	vector<Item*>::iterator iter;
	bool found = false;

	for (iter = items.begin(); iter != items.end(); ++iter)
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

void Room::look()
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

Item* Room::getItem(string name)
{
	vector<Item*>::iterator iter;
	Item* item;

	for (iter = items.begin(); iter != items.end(); ++iter)
	{
		if ((*iter)->getName() == name)
		{
			item = *iter;
			items.erase(iter);
			break;
		}
	}


	return item;
}