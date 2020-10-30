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

    int colBloodstop()
    {
        if (Bstop == 20)
        {
            Bdown -= 20;
            return 3;
        }
    }

    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Bup = 0;
    int Bdown = 0;
    int Bstop = 0;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};