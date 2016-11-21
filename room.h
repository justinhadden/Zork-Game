#include<vector>
#include "enemy.h"

using namespace std;

class Room
{
public:
	Room(const string& name = "", const string& desc = "", const string& area = "", const string& itemLoc = "On the ground you see: ", bool isLocked = false, string lockType = "");
	void setAdjRooms(Room *north, Room *east, Room *south, Room *west);
	Room* getAdjRooms(int index);
	void addItem(Item* item);
	void addEnemy(Enemy* enemy);
	bool roomHasItems();
	bool hasItem(string name);
	Item* getItem(string name);	
	void look();
	void getDesc();
	string getAreaDesc(string addThis = "");
	string getName(string addThis = "");
	void flipBeenHere();
	bool beenHere();

	bool isLocked();
	void lockUnlock();
	string getLockType();

	void inspect();
	void listEnemies();
	bool hasEnemies();
	Enemy* getEnemy(string thisOne);

private:
	vector<Enemy*> m_Enemies;
	Room* m_AdjRooms[4];
	vector<Item*> m_Items;
	string m_Name;
	string m_Desc;
	string m_AreaDesc;
	string m_ItemLoc;
	bool m_Locked;
	string m_LockType;
	bool m_BeenHere = false;
};
