#include<iostream>
#include<string>

using namespace std;

class Item
{
public:
	Item(const string& name = "", const string& type = "", const string& desc = "", const string& shortDesc = "", int attackMod = 0);
	string getName();
	string getType();
	string getDesc();
	string getShortDesc();
	int getAttackMod();

private:
	string m_Name;
	string m_Type;
	string m_Desc;
	string m_ShortDesc;
	int m_AttackMod;

};
