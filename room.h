#include<vector>
#include "item.h"

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
	void popRoom(Item* item);
	void ground();
	bool checkItem(string theChoice);
	Item* takeItem(string theChoice);
	vector<Room*> direct;

private:
	vector<Item*> m_InRoom;
	string m_Name;
	string m_Desc;
};
