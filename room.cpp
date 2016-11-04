#include "room.h"

Room::Room(const string& name, const string& desc, bool isLocked, string lockType)
	: m_Name(name)
	, m_Desc(desc)
	, m_Locked(isLocked)
	, m_LockType(lockType)
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

string Room::getName(string addThis)
{
	m_Name = m_Name + addThis;
	return m_Name;
}

void Room::lockUnlock()
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

bool Room::isLocked()
{
	return m_Locked;
}

string Room::getLockType()
{
	return m_LockType;
}

void Room::addItem(Item* item)
{
	m_Items.push_back(item);
}

void Room::addEnemy(Enemy* enemy)
{
	m_Enemies.push_back(enemy);
}

Room* Room::getAdjRooms(int index)
{
	return m_AdjRooms[index];
}

void Room::inspect()
{
	vector<Item*>::iterator iter;
	if (m_Items.empty())
	{
		cout << "Nothing here" << endl;
	}
	else
	{
		cout << "On the ground you see:" << endl;
		for (iter = m_Items.begin(); iter != m_Items.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

void Room::listEnemies()
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

bool Room::hasEnemies()
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

bool Room::hasItem(string theChoice)
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

Enemy* Room::getEnemy()
{
	Enemy* enemy = m_Enemies[0];

	m_Enemies.erase(m_Enemies.begin());

	return enemy;
}