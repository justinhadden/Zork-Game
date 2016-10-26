#include "room.h"

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

bool Room::isLocked()
{
	return locked;
}

void Room::popRoom(Item* item)
{
	m_InRoom.push_back(item);
}

void Room::ground()
{
	vector<Item*>::iterator iter;
	if (m_InRoom.begin() == m_InRoom.end())
	{
		cout << "Nothing here" << endl;
	}
	else
	{
		cout << "On the ground you see:" << endl;
		for (iter = m_InRoom.begin(); iter != m_InRoom.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

bool Room::checkItem(string theChoice)
{
	vector<Item*>::iterator iter;
	bool found = false;

	for (iter = m_InRoom.begin(); iter != m_InRoom.end(); ++iter)
	{
		if ((*iter)->getName() == theChoice)
		{	
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "That item isn't in here." << endl;
		found = false;
	}

	return found;
}

Item * Room::takeItem(string theChoice)
{
	vector<Item*>::iterator iter;
	Item* returnThis;
	for (iter = m_InRoom.begin(); iter != m_InRoom.end(); ++iter)
	{
		if ((*iter)->getName() == theChoice)
		{
			returnThis = *iter;
			m_InRoom.erase(iter);
			break;
		}
	}

	return returnThis;
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