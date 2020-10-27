#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"

class Bloodup
{
public:
    Bloodup(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Bloodup();
    void update(float deltaTime, Player player);
    void draw(sf::RenderWindow& window);
    int hit()
    {
        if (Bup == 1) {
            Bup--;
            return 1;
        }
    }
    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Bup = 0;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};