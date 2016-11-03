#include "player.h"

Player::Player(string name) :
	m_Name(name)
{}

void Player::pick(Item* theChoice)
{
	m_Inventory.push_back(theChoice);
	cout << "Picked up " << theChoice << endl;
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
			cout << *iter << endl;
		}
	}
}

bool Player::hasItem(string theChoice)
{
	vector<Item*>::iterator iter;
	bool found = true;

	iter = find(m_Inventory.begin(), m_Inventory.end(), theChoice);

	if (iter == m_Inventory.end())
	{
		cout << "That item isn't in here." << endl;
		found = false;
	}
	else
	{
		m_Inventory.erase(iter);
	}

	return found;
}

bool Player::use(string useThis)
{
	vector<Item*>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), useThis);
	bool haveItem = true;
	if (iter == m_Inventory.end())
	{
		cout << "You don't have that item." << endl;
		haveItem = false;
	}

	return haveItem;
}

Item* Player::dropInv(string dropThis)
{
	vector<Item*>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), dropThis);

	Item* item = *iter;

	m_Inventory.erase(iter);
	cout << dropThis << " removed from inventory." << endl;

	return item;
}

Item* Player::getItem(string getThis)
{
	vector<Item*>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), getThis);

	Item* item = *iter;

	return item;
}

string Player::GetName()
{
	return m_Name;
}