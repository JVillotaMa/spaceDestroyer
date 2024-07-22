#ifndef ENEMY_H
#define ENEMY_H



class Enemy {
	int m_healt;
	int m_dmg;
	float m_speed;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:
	Enemy();
	~Enemy();
	void innit();
	void load();
	void update(sf::Vector2f target, int deltatime);
	int getHealth();
	int getDamage();
	float getSpeed();
	sf::Sprite getSprite();
	void print();
	void draw(sf::RenderWindow& window);
	void reduceHealth(int reduce);
	bool isDead();
};


#endif // !ENEMY_H

