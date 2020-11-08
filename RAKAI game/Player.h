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

	int jumping(){
		if (checkjump == 1) {
			checkjump--;
		}
		return 1;
	}

	sf::Vector2f GetPosition() { return body.getPosition(); }//view
	Collision GetCollider() { return Collision(body); }

private:
	
	int numStar;
	int checkjump;
	float speed;
	float damage;
	bool slide;
	bool bullet;
	bool buffX10;
	unsigned int row;

	sf::RectangleShape body;
	Animation animation;
	
	float buffTimer = 0;
	sf::Clock clock;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

