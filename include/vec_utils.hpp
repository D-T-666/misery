#pragma once

#include <SFML/System/Vector2.hpp>
#include <math.h>

inline float length_squared(sf::Vector2f vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

inline float length(sf::Vector2f vec) {
	return sqrt(length_squared(vec));
}

inline sf::Vector2f normalize(sf::Vector2f &vec) {
	vec /= length(vec);
	return vec;
}

inline sf::Vector2f normalized(sf::Vector2f vec) {
	return normalize(vec);
}

inline float dot_product(sf::Vector2f a, sf::Vector2f b) {
	return a.x * b.x + a.y * b.y;
}

template <typename Type>
inline Type lerp_vector(Type a, Type b, float t) {
	Type res;
	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;

	return res;
}