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

bool Room::getItem(string theChoice)
{
	vector<items>::iterator iter;
	bool found = true;

	iter = find(items.begin(), items.end(), theChoice);

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