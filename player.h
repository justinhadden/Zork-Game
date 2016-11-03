#include "room.h"

class Player
{
public:
	Player(string name = "");
	void pick(string theChoice);
	void lookInv();
	bool use(string useThis);
	bool dropInv(string dropThis);
	string GetName();

private:
	vector<string> m_Inventory;
	string m_Name;
};
