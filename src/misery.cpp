#include "../include/game.hpp"
#include <time.h>



int main() {
	srand(time(NULL));

	Game misery;

	int status = 0;
	while (!status)
		status = misery.loop();

	return status;
}