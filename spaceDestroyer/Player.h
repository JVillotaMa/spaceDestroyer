#ifndef PLAYER_H
#define PLAYER_H

class Player {
	float m_health;
	float m_attackDmg;
	int m_attackSpeed;
	int m_fireRate;
	float m_speed;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
private:
	void addFireRate(int deltaTime);
public:
	Player();
	void innit();
	void load();
	void update(float deltatime);
	void draw(sf::RenderWindow& window);
	sf::Sprite getSprite();
	float getHealth();
	float getAttackDmg();
	int getAttackSpeed();
	float getSpeed();
	bool canAttack();
	void reduceHealth(float reduce);
	void print();
};

#endif // !PLAYER_H
