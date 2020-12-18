#pragma once
#include<SFML/Graphics.hpp>
class Bullet1
{
public:
    sf::Sprite DrawBullet;
    sf::Clock timerDrawBullet;
    Bullet1(sf::Texture& BULLET, int bx, int by) {
        DrawBullet.setTexture(BULLET);
        DrawBullet.setScale(0.5,0.5);
        DrawBullet.setTextureRect(sf::IntRect(0, 0, 100, 100));
        DrawBullet.setPosition(bx, by);
    }
};

