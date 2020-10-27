#include "Enemy.h"
#include<iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    row = 5;
    body.setSize(sf::Vector2f(90.0f, 108.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::update1(float deltaTime, Bullet bullet1)
{
    animation.updatealien(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        std::cout << "......................................";
        count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }

}

void Enemy::update2(float deltaTime, Player player)
{
    velocity.x = 0.0f;
    animation.updatealien(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (player.GetPosition().x - body.getPosition().x >= -200.0f)
    {
        std::cout << " !!!!!! collide !!!!! ";
        /*count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);*/
    }

}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(body);
}