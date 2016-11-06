#include "item.h"

class Enemy
{
public:
	Enemy(const string& name, const string& desc, const string& shortDesc, int health, int attack);
	string getName();
	string getDesc();
	string getShortDesc();
	int getAttack();
	int getHealth();
	void damage(int damage);
	void setReward(Item* reward);
	Item* getReward();

private:
	Item* m_Reward;
	string m_Name;
	string m_Desc;
	string m_ShortDesc;
	int m_Attack;
	int m_Health;
	
};