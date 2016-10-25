#include<iostream>
#include<string>
#include<vector>

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
	void popRoom(string item);
	void ground();
	bool pick(string theChoice);
	vector<Room*> direct;

private:

	vector<string> m_InRoom;
	string m_Name;
	string m_Desc;
};
