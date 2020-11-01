#include "Dog.h"
#include<iostream>

Dog::Dog(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f pos):
	animation(texture, imageCount, switchTime)
{
	row = 0;
	start = 0;
	body.setSize(sf::Vector2f(100.0f, 118.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(pos.x + 200.0f, pos.y + 16.0f);
	body.setTexture(texture);
}

Dog::~Dog()
{
}

void Dog::update(float deltaTime, Player player, sf::Vector2f pos)
{
	animation.updatedog(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	if (player.GetCollider().CheckCollision(this->GetCollider())) {
		row = 5;
		start++;
		body.setPosition(pos.x - 100.0f, pos.y - 12.0f);
	}

}

void Dog::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Dog::SetPosition(float x, float y) {
	body.setPosition(x, y);
}
