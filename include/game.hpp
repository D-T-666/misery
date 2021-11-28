#include "../include/minion.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ERR(x)				\
	fprintf(stderr, x);		\
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

	sf::Clock clock;

public:
	Game() { this->setup(); }

	void draw_minion(sf::Vector2<float> pos, int group_index) {
		minionSprite.setPosition(pos);
		minionSprite.setColor(group_colors[group_index]);
		
		window.draw(minionSprite);
	}

	void setup() {
		window.create(sf::VideoMode::getDesktopMode(), "misery");

		window.setFramerateLimit(60);

		if (!personTexture.loadFromFile("assets/person.png")) {
			ERR("Could not load texture from file!");
		}

		group_colors[0] = sf::Color{224, 37, 4};
		group_colors[1] = sf::Color{35, 117, 204};

		for (int g = 0; g < total_groups; g++) {
			for (int i = 0; i < total_minions; i++) {
				minions[g][i].set_pos(sf::Vector2f(rand() % 500, rand() % 500));
			}
		}

		minionSprite.setTexture(personTexture);
	}

	int loop() {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		sf::Vector2<float> pos;

		for (int g = 0; g < total_groups; g++) {
			for (int i = 0; i < total_minions; i++) {
				minions[g][i].update();

				minions[g][i].get_pos(pos);
				draw_minion(pos, g);
			}
		}

		window.display();

		return window.isOpen() ? 0 : 1;
	}
};