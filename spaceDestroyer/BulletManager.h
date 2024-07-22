#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H
#include <vector>
#include "Bullet.h"

class BulletManager {
	std::vector<Bullet> m_bullets;
public:
	BulletManager();
	BulletManager(int limit);
	void uptdate(float deltatime);
	void addBullet(sf::Vector2f target, sf::Vector2f origin);
	void draw(sf::RenderWindow& window);
	void erase(int index);
	int getSize();
	Bullet get(int index);
	void outOfBoundBullet(int width, int height);
};

#endif BULLET_MANAGER_H