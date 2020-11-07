#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"
#include "star.h"
#include "Buff.h"

#pragma once
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void update(float deltaTime, std::vector<star*>& stars, std::vector<Buff>& X2Vector);
	void updateNumstar(float deltaTime, std::vector<star*>& stars, std::vector<Buff>& X2Vector);
	int getNumStar() { return this->numStar; }
	bool getBuffStatus() { return this->buffX10; }
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	void HPbar(float deltaTime, Player player,sf::Vector2f pos);
	void SetPosition(float x, float y);

	sf::Vector2f GetPosition() { return body.getPosition(); }//view
	Collision GetCollider() { return Collision(body); }

private:
	
	int numStar;
	float speed;
	bool slide;
	bool bullet;
	bool buffX10;
	float damage;
	unsigned int row;

	sf::RectangleShape body;
	Animation animation;
	
	float buffTimer = 0;
	sf::Clock clock;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

