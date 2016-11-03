#include<vector>
#include "item.h"

using namespace std;

class Room
{
public:
	Room(const string& name = "", const string& desc = "", bool isLocked = false, string lockType = "");
	void setAdjRooms(Room *north, Room *east, Room *south, Room *west);
	Room* getAdjRooms(int index);
	void addItem(Item* item);
	bool hasItem(string name);
	Item* getItem(string name);	
	void look();
	void GetDesc();
	string GetName();

	bool isLocked();
	void lockUnlock();
	string getLockType();

	void inspect();

private:
	Room* m_AdjRooms[4];
	vector<Item*> items;
	string m_Name;
	string m_Desc;
	bool locked;
	string m_lockType;
};
