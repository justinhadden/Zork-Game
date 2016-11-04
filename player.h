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
	string getName();
	bool hasWeapon();
	void stashThis(Item* item);
	void equipWeapon();
	void unequipWeapon();
	void showAttack();
	void attack();

private:
	vector<Item*> m_Inventory;
	string m_Name;
	Item* m_EquipedWeapon;
	int m_attack = 25;
	int m_health = 300;
};
