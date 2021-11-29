#include "../include/game.hpp"
#include <SFML/System/Vector2.hpp>
#include <iostream>

void Game::draw_minion(sf::Vector2f pos, int group_index) {
	sf::Vector2i p = sf::Vector2i{pos} - sf::Vector2i{minion_radius, minion_radius} - sf::Vector2i{origin};
	minionSprite.setPosition(p.x, p.y);
	minionSprite.setRadius(minion_radius);
	minionSprite.setFillColor(group_colors[group_index]);

	window.draw(minionSprite);
}

void Game::draw_mouse(sf::Vector2<int> pos, int r) {
	minionSprite.setPosition(pos.x-1, pos.y-1);
	minionSprite.setRadius(r);
	minionSprite.setFillColor({255, 255, 255, 255});

	window.draw(minionSprite);
}

void Game::setup() {
	window.create(sf::VideoMode::getDesktopMode(), "misery", sf::Style::Fullscreen);

	if (!personTexture.loadFromFile("assets/person.png")) {
		ERR("Could not load texture from file!");
	}

	group_colors[0] = sf::Color{224, 37, 4};
	group_colors[1] = sf::Color{35, 117, 204};

	for (int i = 0; i < total_minions; i++) {
		minions[i].set_pos(sf::Vector2f(rand() % 500, rand() % 500));
		minions[i].set_size(minion_radius);

		if (i % 2) minions[i].toggle_state(1);
	}

	// sf::Window::ShowMouseCursor(false);
	window.setMouseCursorVisible(false);

	centerOfScreen.x = int(window.getSize().x) / 2;
	centerOfScreen.y = int(window.getSize().y) / 2;
}

int Game::loop() {
	float dt = frameClock.getElapsedTime().asSeconds();

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}


	window.clear(sf::Color::Black);

	sf::Vector2<float> pos;

	for (int i = 0; i < total_minions; i++) {
		minions[i].update(frameClock.getElapsedTime().asSeconds());

		for (int j = i+1; j < total_minions; j++) {
			minions[i].interact(minions[j]);
		}

		minions[i].get_pos(pos);

		if (length_squared(pos - sf::Vector2f{origin + mouse.getPosition()}) < minion_radius * minion_radius) {
			draw_mouse(sf::Vector2i{pos} - origin - sf::Vector2i{minion_radius + 1, minion_radius + 1}, minion_radius + 2);

			if (mouse.isButtonPressed(sf::Mouse::Left)) {
				focusedMinionIndex = i;
			}
		}

		if (focusedMinionIndex == i) {
			origin += sf::Vector2i{pos} - origin - lerp_vector(sf::Vector2i{pos} - origin, centerOfScreen, 0.03f);
		}

		draw_minion(pos, minions[i].get_state(1));
	}

	draw_mouse(mouse.getPosition(), 1);
	frameClock.restart();
	window.display();

	return window.isOpen() ? (0) : 1;
}