#include <SFML/Graphics.hpp>
#include "Utilities.h"

sf::Vector2f normalizeVector(sf::Vector2f vector) {
	float magnitud = std::sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	vector.x /= magnitud;
	vector.y /= magnitud;
	return vector;
}

bool checkCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (rect1.intersects(rect2)) {
		return true;
	}
	return false;
}

