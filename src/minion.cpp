#include "../include/minion.hpp"
#include "../include/vec_utils.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>

void Minion::update(Minion minions[], int &n, float dt) {
	sf::Vector2<float> acc{0.f, 0.f};
	
	for (int i = 0; i < n; i++) {
		sf::Vector2<float> direction = minions[i].pos - this->pos;

		float distance_squared = length_squared(direction);
		
		if (distance_squared != 0) {
			if (distance_squared < this->r*this->r) distance_squared *= -1;
			
			normalize(direction);

			acc += 10000.0f * direction / distance_squared;
		}
	}

	this->vel += acc * dt;
	this->pos += vel * dt;
}
