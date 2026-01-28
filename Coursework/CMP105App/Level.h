#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();


private:
	// Default functions for rendering to the screen.
	sf::CircleShape m_food;
	sf::CircleShape m_snake;
	float m_speed = 200;
	// Default variables for level class.
	enum class Direction { UP, DOWN, LEFT, RIGHT };
	Direction m_direction;
	void spawnFood();
	bool m_isGameOver = false;
	float m_score = 0;
	float m_timeElapsed = 0;
};
