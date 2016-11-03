#include<vector>
#include "item.h"

using namespace std;

class Room
{
public:
	Room(const string& name = "", const string& desc = "");

	// Set the rooms adjacent to this room
	void setAdjRooms(Room *north, Room *east, Room *south, Room *west);
	// Get the rooms adjacent to this room
	auto getAdjRooms() const
	{
		return m_AdjRooms;
	}

	// Add an item to the room
	void addItem(Item *item);
	// Check if the room has an item
	bool hasItem(string name);
	// Get an item from the room
	Item *getItem(string name);

	// Check if the room is locked
	bool isLocked() const
	{
		return locked;
	}

	void look();
	void GetDesc();
	string GetName();
	void lockUnlock();

	void ground();

private:
	Room* m_AdjRooms[4];

	vector<Item*> items;

	string m_Name;
	string m_Desc;

	bool locked;
};
