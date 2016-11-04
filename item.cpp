#include "item.h"

Item::Item(const string& name, const string& type, const string& desc, const string& shortDesc, int attackMod)
	: m_Name(name)
	, m_Type(type)
	, m_Desc(desc)
	, m_ShortDesc(shortDesc)
	, m_AttackMod(attackMod)
{}

string Item::getName()
{
	return m_Name;
}

string Item::getType()
{
	return m_Type;
}

string Item::getDesc()
{
	return m_Desc;
}

string Item::getShortDesc()
{
	return m_ShortDesc;
}

int Item::getAttackMod()
{
	return m_AttackMod;
}
