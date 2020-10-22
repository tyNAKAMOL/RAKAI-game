#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"
#include "Bullet.h"


class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
	~Enemy();
	void update(float deltaTime, Bullet bullet);
	void draw(sf::RenderWindow& window);
	Collision GetCollider() { return Collision(body); }

private:
	int row;
	int count = 0;
	sf::RectangleShape body;
	Animation animation;
};

