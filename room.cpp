#include "room.h"

Room::Room(const string& name, const string& desc)
{
	m_Name = name;
	m_Desc = desc;
}

void Room::setAdjRooms(Room* north, Room* east, Room* south, Room* west)
{
	m_AdjRooms[0] = north;
	m_AdjRooms[1] = east;
	m_AdjRooms[2] = south;
	m_AdjRooms[3] = west;
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

void Room::addItem(Item* item)
{
	items.push_back(item);
}

void Room::ground()
{
	vector<Item*>::iterator iter;
	if (items.begin() == items.end())
	{
		cout << "Nothing here" << endl;
	}
	else
	{
		cout << "On the ground you see:" << endl;
		for (iter = items.begin(); iter != items.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
}

bool Room::hasItem(string theChoice)
{
	vector<Item*>::iterator iter;
	bool found = true;

	iter = find(items.begin(), items.end(), theChoice);

	if (iter == items.end())
	{
		cout << "That item isn't in here." << endl;
		found = false;
	}
	else
	{
		items.erase(iter);
	}

	return found;
}

void Room::look()
{
	if (m_AdjRooms[0] == 0)
	{
		cout << "Nothing north" << endl;
	}
	else
	{
		cout << "To the north you see " << m_AdjRooms[0]->m_Name << endl;
	}
	if (m_AdjRooms[1] == 0)
	{
		cout << "Nothing east" << endl;
	}
	else
	{
		cout << "To the east you see " << m_AdjRooms[1]->m_Name << endl;
	}
	if (m_AdjRooms[2] == 0)
	{
		cout << "Nothing south" << endl;
	}
	else
	{
		cout << "To the south you see " << m_AdjRooms[2]->m_Name << endl;
	}
	if (m_AdjRooms[3] == 0)
	{
		cout << "Nothing west" << endl;
	}
	else
	{
		cout << "To the west you see " << m_AdjRooms[3]->m_Name << endl;
	}
}