#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"
#include "Bullet.h"

class Boss
{
public:
    Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Boss();
    void updateBoss(float deltaTime, Bullet bullet1);
    void updateMove(float deltaTime, Player player);
    void draw(sf::RenderWindow& window);
    void MOVE();
    Collision GetCollider() { return Collision(body); }

    int hit()
    {
        if (count == 1) {
            count--;
            return 1;
        }
    }

    int colBoss()
    {
        if (x1 == 10) {
            x1 -= 10;
            return 2;
        }
    }


private:
    int row;
    int count = 0;
    int x1 = 0;
    float speed;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};