#pragma once
#include <SFML/Graphics.hpp>
class FrameRate
{
	sf::Text fpsStream;
	sf::Font font;
	sf::Clock clock;

public:
	FrameRate();
	void init();
	void draw(sf::RenderWindow& window);
	void load();
	void update(int fps);
	int getDeltaTime();
};

