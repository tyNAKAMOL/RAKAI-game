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
	void HPbar(float deltaTime, Player player,sf::Vector2f pos);
	void SetPosition(float x, float y);

	sf::Vector2f GetPosition() { return body.getPosition(); }//view
	Collision GetCollider() { return Collision(body); }

private:
	sf::RectangleShape body;
	Animation animation;
	float damage;
	unsigned int row;
	float speed;
	bool slide;
	bool bullet;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

