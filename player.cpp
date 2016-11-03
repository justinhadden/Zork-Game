Player::Player(string name) :
	m_Name(name)
{}

void Player::pick(string theChoice)
{
	m_Inventory.push_back(theChoice);
	cout << "Picked up " << theChoice << endl;
}

void Player::lookInv()
{
	vector<string>::iterator iter;
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

bool Player::use(string useThis)
{
	vector<string>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), useThis);
	bool haveItem = true;
	if (iter == m_Inventory.end())
	{
		cout << "You don't have that item." << endl;
		haveItem = false;
	}

	return haveItem;
}

bool Player::dropInv(string dropThis)
{
	vector<string>::iterator iter = find(m_Inventory.begin(), m_Inventory.end(), dropThis);
	bool found = true;
	if (iter == m_Inventory.end())
	{
		cout << "You don't have that Item." << endl;
		found = false;
	}
	else
	{
		m_Inventory.erase(iter);
		cout << dropThis << " removed from inventory." << endl;
	}

	return found;
}

string Player::GetName()
{
	return m_Name;
}