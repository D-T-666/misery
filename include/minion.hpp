#pragma once

#include <SFML/Graphics.hpp>

class Minion
{
private:
	float x, y; // position
	float w, h; // size~
    int state = false;
	sf::Sprite sprite;

public:
	Minion(const sf::Vector2f pos, const sf::Vector2f size) { this->set_pos(pos); this->set_size(size); };
	Minion() { };

	inline void get_pos(sf::Vector2f & pos) const { pos = sf::Vector2f(this->x, this->y); };
	inline void set_pos(const sf::Vector2f pos) { this->x = pos.x; this->y = pos.y; };

	inline void get_size(sf::Vector2f & size) const { size = sf::Vector2f(this->w, this->h); };
	inline void set_size(const sf::Vector2f size) { this->w = size.x; this->h = size.y; };

    inline void toggle_state(const int state) { this->state |= state; };
    inline bool get_state(const int state) const { return static_cast<bool>(this->state & state); };
	
	inline sf::Sprite & get_sprite(void) { return this->sprite; }; 

	~Minion() {};
};



