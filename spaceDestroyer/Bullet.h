#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
	sf::Vector2f m_direction;
	sf::RectangleShape m_shape;
	float speed;
public:
	Bullet();
	Bullet(sf::Vector2f dir);
	void updatePos(float deltatime);
	sf::Vector2f getDirection();
	sf::RectangleShape* getShape();
	void setDirection(sf::Vector2f newDir);
	void setShape(sf::RectangleShape newShape);
	bool outOfBound(int width, int height);
};


#endif BULLET_H