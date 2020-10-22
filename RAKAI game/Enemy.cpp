#include "Enemy.h"
#include<iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
	animation(texture, imageCount, switchTime)
{
	row = 5;
	body.setSize(sf::Vector2f(100.0f, 118.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime, Bullet bullet)
{
	animation.updatealien(row, deltaTime);
	body.setTextureRect(animation.uvRect);

	if (bullet.GetCollider().CheckCollision(this->GetCollider())) 
	{
		std::cout << "......................................";
		count++;
		row = 1;
		body.setPosition(-1000.0f, 350.0f);
		//bullet1.setPosition(NULL, NULL);
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(body);
}