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
	void addEnemy(Enemy* enemy);
	bool hasItem(string name);
	Item* getItem(string name);	
	void look();
	void getDesc();
	string getName();

	bool isLocked();
	void lockUnlock();
	string getLockType();

	void inspect();
	void listEnemies();
	bool hasEnemies();
	Enemy* getEnemy();

private:
	vector<Enemy*> m_Enemies;
	Room* m_AdjRooms[4];
	vector<Item*> m_Items;
	string m_Name;
	string m_Desc;
	bool m_Locked;
	string m_LockType;
};
