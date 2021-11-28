#include <SFML/System/Vector2.hpp>
#include <math.h>

float length_squared(sf::Vector2f vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

float length(sf::Vector2f vec) {
	return sqrt(length_squared(vec));
}

sf::Vector2f normalize(sf::Vector2f &vec) {
	vec /= length(vec);
	return vec;
}

sf::Vector2f normalized(sf::Vector2f vec) {
	return normalize(vec);
}

float dot_product(sf::Vector2f a, sf::Vector2f b) {
	return a.x * b.x + a.y * b.y;
}