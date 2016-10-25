#include "player.h"

Player::Player(const string& name):
	m_Name(name)
{}

void Player::pick(Item* takeThis)
{
	m_Inventory.push_back(takeThis);
	cout << "Picked up " << takeThis->getDesc() << endl;
}

void Player::lookInv()
{
	vector<Item*>::iterator iter;
	if (m_Inventory.begin() == m_Inventory.end())
	{
		cout << "Nothing in your inventory" << endl;
	}
	else
	{
		cout << "Your inventory:" << endl;
		for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
}

bool Player::checkItem(string useThis)
{
	vector<Item*>::iterator iter;
	bool haveItem = false;
	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == useThis)
		{
			haveItem = true;
			break;
		}
	}
	if (!haveItem)
	{
		cout << "You don't have that item" << endl;
		haveItem = false;
	}

	return haveItem;
}

Item * Player::getItem(string getThis)
{
	vector<Item*>::iterator iter;
	Item* item;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == getThis)
		{
			item = *iter;
			break;
		}
	}

	return item;
}

Item* Player::dropInv(string dropThis)
{
	vector<Item*>::iterator iter;
	Item* item;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == dropThis)
		{
			item = *iter;
			cout << (*iter)->getName() << " removed from inventory." << endl;
			m_Inventory.erase(iter);
			
			break;
		}
	}

	return item;
}

string Player::GetName()
{
	return m_Name;
}
