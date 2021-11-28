#include "../include/game.hpp"


void Game::draw_minion(sf::Vector2<float> pos, int group_index) {
	minionSprite.setPosition(pos);
	minionSprite.setColor(group_colors[group_index]);

	window.draw(minionSprite);
}

void Game::setup() {
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

int Game::loop() {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	window.clear(sf::Color::Black);

	sf::Vector2<float> pos;

	for (int g = 0; g < total_groups; g++) {
		for (int i = 0; i < total_minions; i++) {
			minions[g][i].update(minions[g], total_minions, frameClock.getElapsedTime().asSeconds());

			minions[g][i].get_pos(pos);
			draw_minion(pos, g);
		}
	}

	frameClock.restart();
	window.display();

	return window.isOpen() ? 0 : 1;
}