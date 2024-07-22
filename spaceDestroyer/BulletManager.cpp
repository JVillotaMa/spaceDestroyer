#include "BulletManager.h"
#include "Bullet.h"
#include "Utilities.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

BulletManager::BulletManager()
{
}

BulletManager::BulletManager(int limit)
{
	m_bullets.reserve(limit);
}

void BulletManager::uptdate(float deltatime)
{

	for (size_t i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i].updatePos(deltatime);
	}

}

void BulletManager::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_bullets.size(); i++)
	{
		window.draw(*m_bullets[i].getShape());
	}
}

void BulletManager::erase(int index)
{
	m_bullets.erase(m_bullets.begin() + index);
}

int BulletManager::getSize()
{
	return m_bullets.size();
}

Bullet BulletManager::get(int index)
{
	return m_bullets[index];
}

void BulletManager::outOfBoundBullet(int width, int height)
{
	for (size_t i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i].outOfBound(width, height)) {
			m_bullets.erase(m_bullets.begin() + i);
		}
	}
}

void BulletManager::addBullet(sf::Vector2f target, sf::Vector2f origin)
{
	Bullet bullet(normalizeVector(target - origin));
	bullet.getShape()->setPosition(origin);
	m_bullets.push_back(bullet);

}

