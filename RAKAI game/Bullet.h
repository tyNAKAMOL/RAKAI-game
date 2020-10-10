#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"

class Bullet
{
public:
	Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos);
	~Bullet();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
private:
	Animation animation;
	float speed;
	sf::RectangleShape body;
	unsigned int row;
	sf::Vector2f velocity;
};

