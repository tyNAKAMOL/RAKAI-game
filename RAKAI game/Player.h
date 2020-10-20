#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"
#pragma once
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }//view
	Collision GetCollider() { return Collision(body); }

private:
	sf::RectangleShape body;
	Animation animation;
	//Bullet bullet1;
	unsigned int row;
	float speed;
	bool slide;
	bool bullet;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

