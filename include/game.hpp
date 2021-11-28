#include "../include/minion.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ERR(x)						\
	fprintf(stderr, x);				\
	exit(1);

class Game {
private:
	int total_minions = 10;
	int total_groups = 2;
	Minion minions[2][10];
	sf::Color group_colors[2];

	sf::RenderWindow window;
	sf::Event event;

	sf::Texture personTexture;
	sf::Sprite minionSprite;

	sf::Clock clock, frameClock;

public:
	Game() { this->setup(); }

	void draw_minion(sf::Vector2<float> pos, int group_index);
	void setup();
	int loop();
};