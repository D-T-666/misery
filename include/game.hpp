#include "../include/minion.hpp"
#include "../include/vec_utils.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ERR(x)						\
	fprintf(stderr, x);				\
	exit(1);

class Game {
private:
	int total_minions = 80, minion_radius = 10;
	Minion minions[80];
	sf::Color group_colors[2];

	sf::RenderWindow window;
	sf::Event event;

	sf::Texture personTexture;
	sf::CircleShape minionSprite;

	sf::Clock clock, frameClock;

	sf::Mouse mouse;
	sf::Vector2i origin;
	sf::Vector2i centerOfScreen;

	float focusingOnMinion;
	int focusedMinionIndex;

public:
	Game() { this->setup(); }

	void draw_minion(sf::Vector2f pos, int group_index);
	void draw_mouse(sf::Vector2<int> pos, int r);
	void setup();
	int loop();
};