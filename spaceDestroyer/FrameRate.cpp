#include "FrameRate.h"
#include <SFML/Graphics.hpp>
#include <iostream>

FrameRate::FrameRate()
{
}

void FrameRate::init()
{
}

void FrameRate::draw(sf::RenderWindow& window)
{
	window.draw(fpsStream);
}

void FrameRate::load()
{
}

void FrameRate::update(int fps)
{
	fpsStream.setString(std::to_string(1000 / fps));
}

int FrameRate::getDeltaTime()
{
	sf::Time deltaTime = clock.restart();
	int fps = deltaTime.asMilliseconds();;
	return fps;
}

