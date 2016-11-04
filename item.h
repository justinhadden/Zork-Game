#include<string>
#include<iostream>

using namespace std;

class Item
{
public:
	Item(const string& name = "", const string& type = "", const string& desc = "");
	string getName();
	string getType();
	string getDesc();

private:
	string m_Name;
	string m_Type;
	string m_Desc;

};
