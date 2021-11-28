#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Minion
{
private:
	sf::Vector2<float> pos, vel, acc;
	float r; // Radius
	int state = 0;

public:
	Minion(const sf::Vector2f pos, const float size) { this->set_pos(pos); this->set_size(size); };
	Minion() { };

	inline void get_pos(sf::Vector2f & pos) const { pos = this->pos; };
	inline void set_pos(const sf::Vector2f pos) { this->pos = pos; };

	inline void get_size(float & size) const { size = this->r; };
	inline void set_size(const float size) { this->r = size; };

	inline void toggle_state(const int state) { this->state |= state; };
	inline bool get_state(const int state) const { return static_cast<bool>(this->state & state); };

	void attract(Minion &minion);
	void collide(Minion &minion);
	void interact(Minion &minion);
	void update(float dt);

	~Minion() {};
};



