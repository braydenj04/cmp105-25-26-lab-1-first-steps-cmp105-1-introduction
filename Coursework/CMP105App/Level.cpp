#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_snake.setRadius(10);
	m_snake.setFillColor(sf::Color::Red);
	m_snake.setPosition({ 100, 100 });

	m_food.setRadius(7);
	m_food.setFillColor(sf::Color::Yellow);
	spawnFood();
}

void Level::spawnFood()
{
	sf::Vector2u window_size = m_window.getSize();
	float x = rand() % window_size.x;
	float y = rand() % window_size.y;
	m_food.setPosition({ x, y });
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
	

	if (m_isGameOver) return;
	m_timeElapsed += dt;


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
		m_isGameOver = true;
		std::cout << "GAME OVER\n" << "SCORE: " << m_score;
		std::cout << "\nTIME: " << m_timeElapsed << " seconds\n";
	if (pos.y > window_size.y - radius * 2 || pos.y < 0)
		m_isGameOver = true;
		std::cout << "GAME OVER\n" << "SCORE: " << m_score;
		std::cout << "\nTIME: " << m_timeElapsed << " seconds\n";

	//collide with food
	float x_dist = (pos.x + radius) - (m_food.getPosition().x + m_food.getRadius());
	float y_dist = (pos.y + radius) - (m_food.getPosition().y + m_food.getRadius());

	float squared_dist = (x_dist * x_dist) + (y_dist * y_dist);
	float radii_sum = radius + m_food.getRadius();
	if (squared_dist < radii_sum * radii_sum)
	{
		// they are colliding
		spawnFood();
		m_speed *= 1.1f;
		m_score++;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_snake);
	m_window.draw(m_food);
	endDraw();
}

