#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Minion
{
private:
	sf::Vector2<float> pos, vel;
	float r; // size~
	int state = false;

public:
	Minion(const sf::Vector2f pos, const float size) { this->set_pos(pos); this->set_size(size); };
	Minion() { };

	inline void get_pos(sf::Vector2f & pos) const { pos = this->pos; };
	inline void set_pos(const sf::Vector2f pos) { this->pos = pos; };

	inline void get_size(float & size) const { size = this->r; };
	inline void set_size(const float size) { this->r = size; };

	inline void toggle_state(const int state) { this->state |= state; };
	inline bool get_state(const int state) const { return static_cast<bool>(this->state & state); };

	void update(Minion minions[], int &n, float dt);

	~Minion() {};
};



