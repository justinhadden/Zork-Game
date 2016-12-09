#include "player.h"

Player::Player(string name)
	: m_Name(name)
	, m_EquipedWeapon(0)
	, m_EquipedArmor(0)
	, m_InvCount(0)
{}

void Player::pick(Item* theChoice)//Pick up item then tell user
{
	m_Inventory.push_back(theChoice);
	cout << "Picked up " << theChoice->getDesc() << endl;
}

void Player::lookInv()//show inventory and character information
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
		cout << "Attack: " << (getAttack() * m_EquipedWeapon->getMod()) << endl;
	}
	if (m_EquipedArmor == 0)
	{
		cout << "No armor equiped." << endl;
	}
	else
	{
		cout << "Equiped armor: " << m_EquipedArmor->getDesc() << endl;
		cout << "Armor: " << m_EquipedArmor->getMod() << endl;
	}
	cout << "Health: " << getHealth() << endl;
	cout << "Inventory Slots: " << m_MaxInv << endl;
}

bool Player::hasItem(string theChoice)//Check if player has item chosen
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
	if (hasWeaponEquiped() && !found)
	{
		if (m_EquipedWeapon->getName() == theChoice)
		{
			found = true;
		}
	}
	if (hasArmorEquiped() && !found)
	{
		if (m_EquipedArmor->getName() == theChoice)
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

Item* Player::dropItem(string dropThis)//drop item from inventory or equiped item
{
	vector<Item*>::iterator iter;
	Item* item;
	if (hasWeaponEquiped() && dropThis == m_EquipedWeapon->getName())
	{
		unequip(1);
	}
	else if (hasArmorEquiped() && dropThis == m_EquipedArmor->getName())
	{
		unequip(0);
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

Item* Player::getItem(string getThis)//Copy Item from inventory
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

bool Player::hasWeapon()//Checks for weapon in inventory
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

bool Player::hasArmor()//Checks for armor in inventory
{
	bool hasArmor = false;

	vector<Item*>::iterator iter;

	for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
	{
		if ((*iter)->getType() == "ARMOR")
		{
			hasArmor = true;
		}
	}
	return hasArmor;
}

bool Player::hasWeaponEquiped()//Checks if weapon is equiped
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

bool Player::hasArmorEquiped()//Checks if armor equiped
{
	if (m_EquipedArmor == 0)
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

void Player::equip()//Equip armor or weapon
{
	if (hasWeapon() || hasArmor())//Make sure player has it
	{
		string theChoice;
		cout << "What would you like to equip?: ";
		cin >> theChoice;
		int maxInv = m_MaxInv;

		for (unsigned int i = 0; i <= theChoice.length(); ++i)
		{
			theChoice[i] = toupper(theChoice[i]);
		}

		bool foundItem = hasItem(theChoice);//Make sure player has chosen item

		//check if it's already equiped
		if (foundItem && hasWeaponEquiped() && theChoice == m_EquipedWeapon->getName() || foundItem && hasArmorEquiped() && theChoice == m_EquipedArmor->getName())
		{
			cout << "That is already equiped." << endl;
		}
		else if (foundItem)//equip item
		{
			vector<Item*>::iterator iter;
			if (getItem(theChoice)->getType() == "WEAPON")//if it's a weapon
			{		
				if (hasWeaponEquiped())
				{
					m_MaxInv += 1;
					unequip(1);
				}
				for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
				{
					if ((*iter)->getName() == theChoice)
					{
						m_EquipedWeapon = *iter;
						m_Inventory.erase(iter);
						cout << m_EquipedWeapon->getDesc() << " has been equiped." << endl;
						m_InvCount -= 1;
						m_MaxInv = maxInv;
						break;
					}
				}
			}
			else if (getItem(theChoice)->getType() == "ARMOR")//If it's armor
			{
				if (hasArmorEquiped())
				{
					m_MaxInv += 1;
					unequip(0);
				}
				for (iter = m_Inventory.begin(); iter != m_Inventory.end(); ++iter)
				{
					if ((*iter)->getName() == theChoice)
					{
						m_EquipedArmor = *iter;
						m_Inventory.erase(iter);
						cout << m_EquipedArmor->getDesc() << " has been equiped." << endl;
						m_InvCount -= 1;
						m_MaxInv = maxInv;
						break;
					}
				}
			}
		}
		else
		{
			cout << "You don't have that item." << endl;
		}

	}
	else
	{
		cout << "You don't have anything to equip" << endl;
	}
}

void Player::unequip(int choice)//unequip weapon or armor
{
	if (choice == 1)
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
	else
	{
		if (m_InvCount >= m_MaxInv)
		{
			cout << "You don't have room in your inventory to remove your armor." << endl;
		}
		else
		{
			cout << "You have removed your " << m_EquipedArmor->getShortDesc() << endl;
			m_Inventory.push_back(m_EquipedArmor);
			m_InvCount += 1;
			m_EquipedArmor = 0;
		}
	}
}

void Player::damage(int damage)//damage/heal player
{
	if (damage > 0)
	{
		if (hasArmorEquiped())
		{
			damage -= m_EquipedArmor->getMod();
		}
		m_health -= damage;
	}
	else
	{
		m_health -= damage;
	}	
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
	return m_EquipedWeapon->getMod();
}

int Player::getArmorMod()
{
	return m_EquipedArmor->getMod();
}

void Player::attack()//attack for when there is nothing to attack
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
