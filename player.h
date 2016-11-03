#include "room.h"

class Player
{
public:
	Player(string name = "");
	void pick(Item* takeThis);
	void lookInv();
	bool use(string useThis);
	bool dropInv(string dropThis);
	string GetName();

private:
	vector<Item*> m_Inventory;
	string m_Name;
};
