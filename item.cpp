#include "item.h"

Item::Item(const string& name, const string& type, const string& desc) :
	m_Name(name),
	m_Type(type),
	m_Desc(desc)
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