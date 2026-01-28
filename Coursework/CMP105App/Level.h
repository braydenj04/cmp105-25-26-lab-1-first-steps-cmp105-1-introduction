#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();


private:
	// Default functions for rendering to the screen.
	sf::CircleShape m_snake;
	float m_speed = 200;
	// Default variables for level class.
	enum class Direction { UP, DOWN, LEFT, RIGHT };
	Direction m_direction;
};