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
	int getAttack();
	int getHealth();
	bool hasWeapon();
	bool hasWeaponEquiped();
	void stashThis(Item* item);
	void equipWeapon();
	void unequipWeapon();
	void showAttack();
	void showHealth();
	void damage(int damage);
	void attack();
	int getAttackMod();
	int getInvCount();
	int getMaxInv();
	void setInvCount(int set);

private:
	int m_InvCount;
	int m_MaxInv = 5;
	vector<Item*> m_Inventory;
	string m_Name;
	Item* m_EquipedWeapon;
	int m_Attack = 25;
	int m_health = 100;
};
