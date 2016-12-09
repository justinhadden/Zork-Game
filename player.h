#include "room.h"

class Player
{
public:
	Player(string name = "");
	void pick(Item* takeThis);	
	bool hasItem(string haveThis);
	Item* dropItem(string dropThis);
	Item* getItem(string getThis);
	Item* getWeapon();
	string getName();

	int getHealth();	

	//weapons
	bool hasWeapon();
	bool hasWeaponEquiped();

	//armor/weapon
	void equip();
	void unequip(int choice);

	//armor
	bool hasArmor();
	bool hasArmorEquiped();

	//attack stuff
	int getAttack();	
	void damage(int damage);
	void attack();
	int getAttackMod();
	int getArmorMod();

	//inventory
	void lookInv();
	int getInvCount();
	int getMaxInv();
	void setInvCount(int set);
	void setMaxInv(int set);

	//for testing
	void stashThis(Item* item);

private:
	int m_InvCount;
	int m_MaxInv = 5;
	vector<Item*> m_Inventory;
	string m_Name;
	Item* m_EquipedWeapon;
	Item* m_EquipedArmor;
	int m_Attack = 10;
	int m_health = 100;
};
