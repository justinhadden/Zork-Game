#include "item.h"

Item::Item(const string& name, const string& type, const string& desc, const string& shortDesc, int mod, const string& scribe)
	: m_Name(name)
	, m_Type(type)
	, m_Desc(desc)
	, m_ShortDesc(shortDesc)
	, m_Mod(mod)
	, m_Scribe(scribe)
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

string Item::getScribe()
{
	return m_Scribe;
}

int Item::getMod()
{
	return m_Mod;
}
