#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"
#include "star.h"

#pragma once
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void update(float deltaTime, std::vector<star*>& stars);
	void updateScore(std::vector<star*>& stars);
	//void increaseScore(int score);
	
	int colStar()
	{
		if (score == 10) {
			score -= 10;
			return 2;
		}
	}

	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	void HPbar(float deltaTime, Player player,sf::Vector2f pos);
	void SetPosition(float x, float y);

	sf::Vector2f GetPosition() { return body.getPosition(); }//view
	Collision GetCollider() { return Collision(body); }

private:
	
	int score;
	float speed;
	bool slide;
	bool bullet;
	float damage;
	unsigned int row;

	sf::RectangleShape body;
	Animation animation;
	

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

