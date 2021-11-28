#include <SFML/System/Vector2.hpp>
#include <math.h>

float length_squared(sf::Vector2<float> vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

float length(sf::Vector2<float> vec) {
	return sqrt(length_squared(vec));
}

sf::Vector2<float> normalize(sf::Vector2<float> &vec) {
	vec /= length(vec);
	return vec;
}