#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Player.h"
#include"Platform.h"
#include"Bullet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Rakai");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
	
	sf::RectangleShape background(sf::Vector2f(5000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("a/5.png");
	background.setTexture(&space);

	sf::Texture playertexture;
	playertexture.loadFromFile("a/as2.png");
	Player player(&playertexture, sf::Vector2u(6, 5), 0.15f, 250.0f ,200.0f);
	
	sf::Texture BULLET;
	BULLET.loadFromFile("a/bullet.png");
	Bullet bullet1(&BULLET, sf::Vector2u(3, 1), 0.15f, 200.0f, player.GetPosition());

	std::vector<Platform> platforms;
	// 2776.992 -2656.992
	platforms.push_back(Platform(nullptr, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(2500.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(4050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(1700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(80.0f, 687.072f), sf::Vector2f(900.0f, 830.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(5060.0f, 600.928f)));

	bool slide;
	int k = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		k = 2;
	}
	float deltaTime = 0.0f;
	sf::Clock clock;



	while (window.isOpen())
	{
		slide = false;

		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';
		
		player.update(deltaTime);
		bullet1.update(deltaTime);
		sf::Vector2f direction;

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		view.setCenter(player.GetPosition().x , 360.0f);
		if(view.getCenter().x - 540.0f <= 0.0f)
		{
			view.setCenter(540.0f, 360.0f);
		}
		if (view.getCenter().x + 540.0f >= 5000.0f)
		{
			view.setCenter(4460.0f, 360.0f);
		}
		window.clear();
		window.setView(view);
		//window.draw(background);		
		for (Platform& platform : platforms)
		{
			platform.Draw(window);
		}
		window.draw(background);
		player.Draw(window);
		if (k==2)
		{
			bullet1.draw(window);
		}
		window.display();
	}
	return 0;
}