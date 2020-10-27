#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"

class star
{
public:
	
	star(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float x,float y);
	~star();
	void update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	
	int iscollide()
	{
		if (Cstar == 1) {
			Cstar--;
			return 1;
		}
	}

	int iscollide2()
	{
		if (collide == 1) {
			collide--;
			return 2;
		}
	}
	Collision GetCollider() { return Collision(body); }

private:
	int row;
	int Cstar;
	int collide;
	sf::RectangleShape body;
	Animation animation;
};
