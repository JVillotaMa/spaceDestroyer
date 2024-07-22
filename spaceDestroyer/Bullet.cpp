#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"

Bullet::Bullet() {
	m_shape = sf::RectangleShape(sf::Vector2f(10, 5));
}
Bullet::Bullet(sf::Vector2f dir) {
	m_shape = sf::RectangleShape(sf::Vector2f(10, 5));
	m_direction = dir;
	speed = 1.0f;
}
sf::Vector2f Bullet::getDirection() {
	return m_direction;
}
sf::RectangleShape* Bullet::getShape() {
	return &m_shape;
}
void Bullet::setDirection(sf::Vector2f newDir) {
	m_direction = newDir;
}
void Bullet::setShape(sf::RectangleShape newShape) {
	m_shape = newShape;
}
bool Bullet::outOfBound(int width, int height)
{
	if (m_shape.getPosition().x > width ||
		m_shape.getPosition().x < 0 ||
		m_shape.getPosition().y > height ||
		m_shape.getPosition().y < 0)
	{
		return true;
	}
	return false;
}
void Bullet::updatePos(float deltatime) {
	m_shape.setPosition((m_shape.getPosition() + getDirection() * deltatime * speed));

}
