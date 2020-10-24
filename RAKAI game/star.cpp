#include "star.h"
#include<iostream>
star::star(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float x,float y) :
	animation(texture, imageCount, switchTime)
{
	Cstar = 0;
	row = 0;
	body.setSize(sf::Vector2f(35.0f, 44.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x,y);
	body.setTexture(texture);
	
}

star::~star()
{
}

void star::update(float deltaTime, Player player)
{
	animation.updatestar(row, deltaTime);
	body.setTextureRect(animation.uvRect);

	if (player.GetCollider().CheckCollision(this->GetCollider())) {
		Cstar++;
		std::cout << "isCollide star";
		body.setPosition(-1000.0f, 350.0f);
	}
}

void star::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
