#include "../include/minion.hpp"
#include "../include/vec_utils.hpp"
#include <iostream>

void Minion::collide(Minion &minion) {
	sf::Vector2<float> direction = minion.pos - this->pos;
	float distance = length_squared(direction);

	if (distance < this->r*this->r*4) {
		distance = sqrt(distance);
		direction /= distance;

		this->pos += direction * (distance - this->r * 2) / 2.0f;
		minion.pos -= direction * (distance - this->r * 2) / 2.0f;

		this->vel	-= 0.5f * direction * length(this->vel); 
		minion.vel	+= 0.5f * direction * length(minion.vel); 
	}
}

void Minion::attract(Minion &minion) {
	bool negative = this->get_state(1) ^ minion.get_state(1);

	sf::Vector2<float> direction = minion.pos - this->pos;
	float distance_squared = length_squared(direction);
	
	if (distance_squared != 0 && (distance_squared > 500*500 || negative)) {
		if (distance_squared < this->r*this->r*16 || negative) distance_squared *= -1;

		normalize(direction);

		sf::Vector2f lacc = (1 - 2 * negative) * 10000.0f * direction / distance_squared;

		this->acc += lacc;
		minion.acc -= lacc;
	}
}

void Minion::interact(Minion &minion) {
	this->attract(minion);
	this->collide(minion);
}

void Minion::update(float dt) {
	this->vel += acc * dt;
	this->pos += vel * dt;
	this->acc *= 0.0f;
}
