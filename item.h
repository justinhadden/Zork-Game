#include<iostream>
#include<string>

using namespace std;

class Item
{
public:
	Item(const string& name = "", const string& type = "", const string& desc = "", const string& shortDesc = "", int mod = 0, const string& scribe = "");
	string getName();
	string getType();
	string getDesc();
	string getShortDesc();
	string getScribe();
	int getMod();

private:
	string m_Name;
	string m_Type;
	string m_Desc;
	string m_ShortDesc;
	string m_Scribe;
	int m_Mod;

};
