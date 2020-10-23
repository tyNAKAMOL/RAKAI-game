#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"
#include "Bullet.h"


class Enemy
{
public:
    Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Enemy();
    void update1(float deltaTime, Bullet bullet1);
    void draw(sf::RenderWindow& window);
    Collision GetCollider() { return Collision(body); }
    
    int hit()
    {
        if (count == 1) {
            count--;
            return 1;
        }
    }


private:
    int row;
    int count = 0;
    sf::RectangleShape body;
    Animation animation;
};