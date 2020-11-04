#include "Bloodup.h"
#include<iostream>

Bloodup::Bloodup(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y):
    animation(texture, imageCount, switchTime)
{
    row = 0;
    Bup = 0;
    Bdown = 0;
    X2 = 0;
    body.setSize(sf::Vector2f(45.0f, 58.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Bloodup::~Bloodup()
{
}

void Bloodup::update(float deltaTime, Player player)
{
    animation.updateItemBloodup(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        Bup++;
        Bdown += 10;
        X2 += 20;
        body.setPosition(-3000.0f, 350.0f);
    }
}

void Bloodup::draw(sf::RenderWindow& window)
{
    window.draw(body);
}