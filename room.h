#include<vector>
#include "item.h"

using namespace std;

class Room
{
public:
	Room(const string& name = "", const string& desc = "");
	static Room zero();
	void setDirect(const Room& north, const Room& east, const Room& south, const Room& west);
	void look();
	void GetDesc();
	string GetName();
	void lockUnlock();
	void popRoom(Item* item);
	void ground();
	bool checkItem(string theChoice);
	Item* takeItem(string theChoice);
	vector<Room*> direct;

private:
	bool locked = false;
	vector<Item*> m_InRoom;
	string m_Name;
	string m_Desc;
};
