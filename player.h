#include "room.h"

using namespace std;

class Player
{
public:
	Player(const string& name = "");
	void pick(Item* takeThis);
	void lookInv();
	bool checkItem(string useThis);
	Item* getItem(string getThis);
	Item* dropInv(string dropThis);
	string GetName();

private:
	vector<Item*> m_Inventory;
	string m_Name;
};
