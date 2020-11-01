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
    
    int colBloodup()
    {
        if (Bup == 1) 
        {
            Bup--;
            return 1;
        }
    }
    int colBlooddown()
    {
        if (Bdown == 10)
        {
            Bdown -= 10;
            return 2;
        }
    }

    int colX2()
    {
        if (X2 == 20)
        {
            X2 -= 20;
            return 3;
        }
    }

    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Bup;
    int Bdown;
    int X2;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};