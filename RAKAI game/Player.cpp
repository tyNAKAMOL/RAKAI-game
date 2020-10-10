#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight):
	animation(texture, imageCount, switchTime)
    //bullet1(texture, imageCount, switchTime,speed)
{
	this->speed = speed;
    this->jumpHeight = jumpHeight;
	row = 0;
    canJump = true;
    slide = false;
    bullet = false;
	
    body.setSize(sf::Vector2f(120.0f, 150.0f));
    body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(200.0f, 520.0f);
	body.setTexture(texture);

    /*sf::Texture BULLET;
    BULLET.loadFromFile("a/bullet.png");
    Bullet bullet1(&BULLET,sf::Vector2u(3,1),0.15f, 400.0f,body.getPosition());*/
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{ 
    velocity.x = 0.0f;

    slide = false;
    bullet = false;

    if (slide == false)
    {
        body.setSize(sf::Vector2f(120.0f, 150.0f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        bullet = true;
        row = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        velocity.x += speed * 1.7; slide = false; bullet = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump == true) 
    {
        canJump = false;
        velocity.y = - sqrtf(2.0f * 1555.0f * jumpHeight); //กระโดด
    }
        velocity.y += 1555.0f * deltaTime; //กระโดด
 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        velocity.x += speed * 1.7f;
        slide = true;
        if (slide == true)
        {
            body.setSize(sf::Vector2f(120.0f, 130.0f));
        }
    }

    if (velocity.x == 0 && bullet == false)
    {
        row = 0;
    }
    else
    {
        if (velocity.x > 0.0f)
        {
            if (slide == true)
            {
                row = 3;
            }
            else
            {
                row = 1;
            }
        }
        if (velocity.x < 0.0f)
        {
            row = 1;
        }
    }
    animation.update(row, deltaTime, slide, bullet);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

    void Player::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        //right
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        //bottom
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        //top
        velocity.y = 0.0f;
    }

}
