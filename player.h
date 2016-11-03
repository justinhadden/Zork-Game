#include "room.h"

class Player
{
public:
	Player(string name = "");
	void pick(Item* takeThis);
	void lookInv();
	bool use(string useThis);
	bool hasItem(string haveThis);
	Item* dropItem(string dropThis);
	Item* getItem(string getThis);
	string GetName();

	void stashThis(Item* item);

private:
	vector<Item*> m_Inventory;
	string m_Name;
};
