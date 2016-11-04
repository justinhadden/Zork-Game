#include<iostream>
#include<string>

using namespace std;

class Enemy
{
public:
	Enemy(const string& name, const string& desc, int health, int attack);
	string getName();
	string getDesc();
	int getAttack();
	int getHealth();
	void damage(int damage);


private:
	string m_Name;
	string m_Desc;
	int m_Attack;
	int m_Health;
	
};