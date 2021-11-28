#include "../include/game.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void Game::draw_minion(sf::Vector2<float> pos, int group_index) {
	minionSprite.setPosition(pos);
	minionSprite.setRadius(10);
	minionSprite.setFillColor(group_colors[group_index]);

	window.draw(minionSprite);
}

void Game::setup() {
	window.create(sf::VideoMode::getDesktopMode(), "misery");

	if (!personTexture.loadFromFile("assets/person.png")) {
		ERR("Could not load texture from file!");
	}

	group_colors[0] = sf::Color{224, 37, 4};
	group_colors[1] = sf::Color{35, 117, 204};

	for (int i = 0; i < total_minions; i++) {
		minions[i].set_pos(sf::Vector2f(rand() % 500, rand() % 500));
		minions[i].set_size(10);

		if (i % 2) minions[i].toggle_state(1);
	}
}

int Game::loop() {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	window.clear(sf::Color::Black);

	sf::Vector2<float> pos;

	for (int i = 0; i < total_minions; i++) {
		minions[i].update(frameClock.getElapsedTime().asSeconds());

		for (int j = i+1; j < total_minions; j++)
			minions[i].interact(minions[j]);

		minions[i].get_pos(pos);

		draw_minion(pos, minions[i].get_state(1));
	}

	frameClock.restart();
	window.display();

	return window.isOpen() ? (0) : 1;
}