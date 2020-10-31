#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"

class Dog
{
public:
	Dog(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f pos);
	~Dog();
	void update(float deltaTime, Player player,sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	void SetPosition(float x, float y);

	Collision GetCollider() { return Collision(body); }

private:
	int row;
	sf::RectangleShape body;
	Animation animation;
};

