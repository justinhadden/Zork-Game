#include "room.h"
#include <algorithm>

Room::Room(const string& name, const string& desc)
    : name_(name)
    , desc_(desc)
    , locked_(false)
{
}

void Room::setAdjRooms(Room *north, Room *east, Room *south, Room *west)
{
	adjRooms_[0] = north;
	adjRooms_[1] = east;
	adjRooms_[2] = south;
	adjRooms_[3] = west;
}

void Room::addItem(Item *item)
{
    items_.push_back(item);
}

bool Room::hasItem(string name)
{
    bool ret = false;
    auto iter = items_.begin();
    while (iter != items_.end())
    {
        if ((*iter)->getName() == name)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

Item * Room::getItem(string name)
{
    Item *ret = nullptr;
    auto iter = items_.begin();
    while (iter != items_.end())
    {
        if ((*iter)->getName() == name)
        {
            ret = *iter;
            items_.erase(iter);
            break;
        }
    }
    return ret;
}

string Room::GetDesc()
{
    return desc_;
}

string Room::GetName()
{
	return name_;
}

void Room::lockUnlock()
{
    locked_ ? false : true;
}

void Room::ground()
{
	vector<Item*>::iterator iter;
	if (items_.begin() == items_.end())
	{
		cout << "Nothing here" << endl;
	}
	else
	{
		cout << "On the ground you see:" << endl;
		for (iter = items_.begin(); iter != items_.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

void Room::look()
{
	if (!adjRooms_[0])
	{
		cout << "Nothing north" << endl;
	}
	else
	{
		cout << "To the north you see " << adjRooms_[0]->GetName() << endl;
	}
	if (!adjRooms_[1])
	{
		cout << "Nothing east" << endl;
	}
	else
	{
		cout << "To the east you see " << adjRooms_[1]->GetName() << endl;
	}
	if (!adjRooms_[2])
	{
		cout << "Nothing south" << endl;
	}
	else
	{
		cout << "To the south you see " << adjRooms_[2]->GetName() << endl;
	}
	if (!adjRooms_[3])
	{
		cout << "Nothing west" << endl;
	}
	else
	{
		cout << "To the west you see " << adjRooms_[3]->GetName() << endl;
	}
}