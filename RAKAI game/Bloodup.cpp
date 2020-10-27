#include "Bloodup.h"
#include<iostream>

Bloodup::Bloodup(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y):
    animation(texture, imageCount, switchTime)
{
    row = 0;
    body.setSize(sf::Vector2f(90.0f, 108.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Bloodup::~Bloodup()
{
}

void Bloodup::update(float deltaTime, Player player)
{
    animation.updatealien(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        std::cout << "Blood UP!!!";
        Bup++;
        //body.setPosition(-1000.0f, 350.0f);
    }

}

void Bloodup::draw(sf::RenderWindow& window)
{
    window.draw(body);
}