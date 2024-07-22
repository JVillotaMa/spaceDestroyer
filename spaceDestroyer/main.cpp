#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "FrameRate.h"
#include "Utilities.h"


void checkColisionEnemiesBullets(Enemy& enemy, BulletManager& bullM) {
	for (size_t i = 0; i < bullM.getSize(); i++)
	{
		if (checkCollision(bullM.get(i).getShape()->getGlobalBounds(), enemy.getSprite().getGlobalBounds())) {
			bullM.erase(i);
			enemy.reduceHealth(10);
		}
	}
}

int main(int argc, char* argv[]) {

	int deltatime;
	float bulletSpeed = 0.5f;
	FrameRate fr;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Survive!");
	window.setFramerateLimit(60);

	Player p1;
	Enemy e1;
	BulletManager bullM;

	p1.innit();
	e1.innit();

	p1.load();
	e1.load();


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		deltatime = fr.getDeltaTime();
		fr.update(deltatime);
		p1.update(deltatime);
		e1.update(normalizeVector(p1.getSprite().getPosition()-e1.getSprite().getPosition()),deltatime);

		bullM.uptdate(deltatime);
		bullM.outOfBoundBullet(window.getSize().x, window.getSize().y);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && p1.canAttack()) {
			bullM.addBullet(sf::Vector2f(sf::Mouse::getPosition(window)), p1.getSprite().getPosition());
		}

		if (checkCollision(p1.getSprite().getGlobalBounds(), e1.getSprite().getGlobalBounds()) && !e1.isDead()) { //Collision
			p1.reduceHealth(10.0f);
		}

		checkColisionEnemiesBullets(e1, bullM);

		window.clear();

		e1.draw(window);
		p1.draw(window);
		bullM.draw(window);

		window.display();
	}
	return 0;
}