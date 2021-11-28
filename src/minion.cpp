#include "../include/minion.hpp"
#include <cstdlib>

void Minion::update() {
	this->x += rand()%3-1;
	this->y += rand()%3-1;
}
