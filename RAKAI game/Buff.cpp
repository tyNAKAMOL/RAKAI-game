#include "Buff.h"
#include<iostream>
Buff::Buff(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
	animation(texture, imageCount, switchTime)
{
	row = 0;
	body.setSize(sf::Vector2f(70.0f, 88.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

Buff::~Buff()
{
}

void Buff::update(float deltaTime)
{
	animation.updatestar(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void Buff::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Buff::setPosition(float x, float y) {
	body.setPosition(x, y);
}
