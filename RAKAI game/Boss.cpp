#include "Boss.h"
#include<iostream>

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 3;
    body.setSize(sf::Vector2f(360.0f, 432.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Boss::~Boss()
{
}

void Boss::updateBoss(float deltaTime, Bullet bullet1)
{
    animation.updatestar(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        count++;
        //row = 1;
        //body.setPosition(-1000.0f, 350.0f);
    }

}

void Boss::updateMove(float deltaTime, Player player)
{
    if (abs(player.GetPosition().x - body.getPosition().x) <= 400.0f)
    {
        velocity.y = 0;
        velocity.x = 90;
        if (player.GetPosition().x < body.getPosition().x)
        {
            body.move(-velocity * deltaTime);
        }
        else if (player.GetCollider().CheckCollision(this->GetCollider()))
        {
            x1 += 10;
            //body.setPosition(-100.0f, 350.0f);
        }
        animation.updatestar(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }

}

void Boss::draw(sf::RenderWindow& window)
{
    window.draw(body);
}
void Boss::MOVE() 
{
    body.setPosition(-10.0f, 350.0f);
}