#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Utilities.h"

Enemy::Enemy() :
	m_healt(0)
{
}
Enemy::~Enemy() {

}
void Enemy::innit() {

	m_healt = 100;
	m_dmg = 10;
	m_speed = 0.3f;
	m_sprite.setPosition(sf::Vector2f(1000.0f, 500.0f));
}
void Enemy::load() {
	;
	if (m_texture.loadFromFile("assets/enemy/spritesheet.png")) {
		m_sprite.setTexture(m_texture);
	}
	else {
		std::cout << "Fail loading the goblin";
	}
	m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_sprite.setPosition(sf::Vector2f(500,500));
}

void Enemy::update(sf::Vector2f target, int deltatime)
{
	if (isDead()) {
		m_sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
	}else{
		m_sprite.setPosition(m_sprite.getPosition() + target);
	}
}

int  Enemy::getHealth() {
	return m_healt;
}
int Enemy::getDamage() {
	return m_dmg;
}
float Enemy::getSpeed() {
	return m_speed;
}
sf::Sprite Enemy::getSprite() {
	return m_sprite;
}
void Enemy::print() {
	std::cout << getHealth() << " " << getDamage() << " " << getSpeed() << " ";
}
void Enemy::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void Enemy::reduceHealth(int reduce)
{
	m_healt -= reduce;
}

bool Enemy::isDead()
{
	if (m_healt <= 0) {
		return true;
	}
	return false;
}
