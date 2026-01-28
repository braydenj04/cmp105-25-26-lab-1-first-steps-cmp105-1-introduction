#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_snake.setRadius(10);
	m_snake.setFillColor(sf::Color::Red);
	m_snake.setPosition({ 100, 100 });
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D)) 
	{
		m_direction = Direction::RIGHT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A))
	{
		m_direction = Direction::LEFT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W))
	{
		m_direction = Direction::UP;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S))
	{
		m_direction = Direction::DOWN;
	}
}

// Update game objects
void Level::update(float dt)
{
	switch (m_direction)
	{
	case Direction::UP:
		m_snake.move({ 0.f,  -m_speed * dt });
		break;
	case Direction::DOWN:
		m_snake.move({ 0.f,  m_speed * dt });
		break;
	case Direction::LEFT:
		m_snake.move({ -m_speed * dt, 0.f });
		break;
	case Direction::RIGHT:
		m_snake.move({ m_speed * dt, 0.f });
		break;
	}

	sf::Vector2f pos = m_snake.getPosition();
	float radius = m_snake.getRadius();
	sf::Vector2u window_size = m_window.getSize();
	if (pos.x > window_size.x - radius * 2 || pos.x < 0)
		// if the x co-ord is incorrect
		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
	if (pos.y > window_size.y - radius * 2 || pos.y < 0)
		// if the y co-ord is incorrect
		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_snake);
	endDraw();
}

