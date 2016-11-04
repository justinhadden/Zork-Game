#include "enemy.h"

Enemy::Enemy(const string& name, const string& desc, int health, int attack)
	: m_Name(name)
	, m_Desc(desc)
	, m_Health(health)
	, m_Attack(attack)
{}

string Enemy::getName()
{
	return m_Name;
}

string Enemy::getDesc()
{
	return m_Desc;
}

int Enemy::getAttack()
{
	return m_Attack;
}

int Enemy::getHealth()
{
	return m_Health;
}

void Enemy::damage(int damage)
{
	m_Health -= damage;
}

void Enemy::setReward(Item * reward)
{
	m_Reward = reward;
}

Item * Enemy::getReward()
{
	return m_Reward;
}
