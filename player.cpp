#include "player.h"

Player::Player(string name) :
	m_Name(name)
{}

void Player::pick(Item* theChoice)
{
	m_Inventory.push_back(theChoice);
	cout << "Picked up " << theChoice->getDesc() << endl;
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

bool Player::hasItem(string theChoice)
{
	vector<Item*>::iterator iter;
	bool found = false;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == theChoice)
		{
			found = true;
		}
	}

	if (!found)
	{
		cout << "You do not have that item." << endl;
	}

	return found;
}

bool Player::use(string useThis)
{
	vector<Item*>::iterator iter;
	bool found = true;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == useThis)
		{
			found = true;
		}
	}

	if (!found)
	{
		cout << "You don't have that item." << endl;
	}

	return found;
}

Item* Player::dropItem(string dropThis)
{
	vector<Item*>::iterator iter;
	Item* item;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == dropThis)
		{
			item = *iter;
			m_Inventory.erase(iter);
			cout << item->getDesc() << " removed from inventory." << endl;
			break;
		}
	}
	return item;
}

Item* Player::getItem(string getThis)
{
	vector<Item*>::iterator iter;
	Item* item;
	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getName() == getThis)
		{
			item = *iter;
		}
	}

	return item;
}

string Player::getName()
{
	return m_Name;
}

bool Player::hasWeapon()
{
	bool hasWeapon = false;

	vector<Item*>::iterator iter;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getType() == "WEAPON")
		{
			hasWeapon = true;
		}
	}
	return hasWeapon;
}

void Player::stashThis(Item* item)
{
	m_Inventory.push_back(item);
}

void Player::equipWeapon()
{
	if (hasWeapon())
	{
		string theChoice;
		cout << "Which weapon would you like to equip?: ";
		cin >> theChoice;

		for (int i = 0; i <= theChoice.length(); ++i)
		{
			theChoice[i] = toupper(theChoice[i]);
		}

		vector<Item*>::iterator iter;

		for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
		{
			if ((*iter)->getName() == theChoice)
			{
				equipedWeapon = *iter;
				cout << equipedWeapon->getDesc() << " has been equiped" << endl;
			}
		}

	}
	else
	{
		cout << "You don't have a weapon" << endl;
	}
}
