#include "player.h"

Player::Player(string name)
	: m_Name(name)
	, m_EquipedWeapon(0)
	, m_InvCount(0)
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
		cout << m_Name << "'s inventory:" << endl;
		for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
		{
			cout << (*iter)->getDesc() << endl;
		}
	}
	cout << "--------------------------------" << endl;
	if (m_EquipedWeapon == 0)
	{
		cout << "No weapon equiped." << endl;
		cout << "Attack: " << m_Attack << endl;
	}
	else
	{
		cout << "Equiped weapon: " << m_EquipedWeapon->getDesc() << endl;
		cout << "Attack: " << (getAttack() * m_EquipedWeapon->getAttackMod()) << endl;
	}
	cout << "Health: " << getHealth() << endl;
	cout << "Inventory Slots: " << m_MaxInv << endl;
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
	if (hasWeapon())
	{
		if (m_EquipedWeapon->getName() == theChoice)
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
	if (dropThis == m_EquipedWeapon->getName())
	{
		unequipWeapon();
	}
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

Item * Player::getWeapon()
{
	return m_EquipedWeapon;
}

string Player::getName()
{
	return m_Name;
}

int Player::getMaxInv()
{
	return m_MaxInv;
}

int Player::getInvCount()
{
	return m_InvCount;
}

void Player::setInvCount(int set)
{
	m_InvCount += set;
}

void Player::setMaxInv(int set)
{
	m_MaxInv += set;
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

bool Player::hasWeaponEquiped()
{
	if (m_EquipedWeapon == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
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
		bool found = hasWeapon();
		if (found)
		{
			if (hasWeaponEquiped())
			{
				unequipWeapon();
			}
			for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
			{
				if ((*iter)->getName() == theChoice)
				{
					m_EquipedWeapon = *iter;
					m_Inventory.erase(iter);
					cout << m_EquipedWeapon->getDesc() << " has been equiped." << endl;
					m_InvCount -= 1;
					break;
				}
			}
		}
		else
		{
			cout << "You do not have that weapon." << endl;
		}

	}
	else
	{
		cout << "You don't have a weapon" << endl;
	}
}

void Player::unequipWeapon()
{
	if (m_InvCount >= m_MaxInv)
	{
		cout << "You don't have room in your inventory to sheath your weapon." << endl;
	}
	else
	{
		cout << "You have sheathed your " << m_EquipedWeapon->getShortDesc() << endl;
		m_Inventory.push_back(m_EquipedWeapon);
		m_InvCount += 1;
		m_EquipedWeapon = 0;
	}
	
}

void Player::showAttack()
{
	if (m_EquipedWeapon != 0)
	{
		cout << m_Attack * m_EquipedWeapon->getAttackMod() << endl;
	}
	else
	{
		cout << m_Attack << endl;
	}
}

void Player::showHealth()
{
	cout << m_health << endl;

}

void Player::damage(int damage)
{
	m_health -= damage;
	if (m_health > 100)
	{
		m_health = 100;
	}
}

int Player::getAttack()
{
	return m_Attack;
}

int Player::getHealth()
{
	return m_health;
}

int Player::getAttackMod()
{
	return m_EquipedWeapon->getAttackMod();
}

void Player::attack()
{
	string attackWep;
	if (m_EquipedWeapon == 0)
	{
		attackWep = "fists";
	}
	else
	{
		attackWep = m_EquipedWeapon->getShortDesc();
	}

	cout << "You swing your " << attackWep << " at nothing in particular..." << endl;
}
