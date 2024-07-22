#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"



void Player::addFireRate(int deltaTime)
{
	m_fireRate += deltaTime;
}

Player::Player() {
	m_health = 0.0f;
	m_attackDmg = 0.0f;
	m_attackSpeed = 2;
	m_fireRate = m_attackSpeed;
	m_speed = 0;
	m_sprite;
}
void Player::innit()
{
	m_health = 100.0f;
	m_attackDmg = 100.0f;
	m_attackSpeed = 0.9f; // Attacks every x attack speed
	m_speed = 0.5f;
	m_sprite.setPosition(sf::Vector2f(200.0f, 600.0f));
}
void Player::load()
{
	if (m_texture.loadFromFile("assets/player/spritesheet.png")) {
		m_sprite.setTexture(m_texture);
	}
	else {
		std::cout << "fail texture";
	}
	m_sprite.setTextureRect(sf::IntRect(0, 0, 92, 92));
}
void Player::update(float deltatime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_sprite.setTextureRect(sf::IntRect(0,92, 92, 92));
		m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(0, -m_speed) * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_sprite.setTextureRect(sf::IntRect(92, 0, 92, 92));
		m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(-m_speed, 0) * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_sprite.setTextureRect(sf::IntRect(92, 92, 92, 92));
		m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(0, m_speed) * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_sprite.setTextureRect(sf::IntRect(0,0, 92, 92));
		m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(m_speed, 0) * deltatime);
	}
	addFireRate(deltatime);
}
void Player::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}
sf::Sprite Player::getSprite() {
	return m_sprite;
}
float Player::getHealth() {
	return m_health;
}
float Player::getAttackDmg() {
	return m_attackDmg;
}
int Player::getAttackSpeed() {
	return m_attackSpeed;

}
float Player::getSpeed() {
	return m_speed;
}
bool Player::canAttack()
{
	if (m_fireRate >= m_attackSpeed * 1000) {
		m_fireRate = 0;
		return true;
	}
	return false;
}
void Player::reduceHealth(float reduce)
{
	m_health -= reduce;
}
void Player::print() {
	std::cout << "Health: " << getHealth() << "Dmg: " << getAttackDmg() << "Speed: " << getSpeed() << "Attack Speed" << getAttackSpeed();
}