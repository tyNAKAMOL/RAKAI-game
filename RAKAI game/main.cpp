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
#include"Dog.h"
#include"star.h"
#include"Menu.h"
#include"Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Rakai");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));//view

	Menu menu(window.getSize().x, window.getSize().y);

	sf::RectangleShape background(sf::Vector2f(10000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("a/123.png");
	background.setTexture(&space);

	sf::Texture playertexture;
	playertexture.loadFromFile("a/as2.png");
	Player player(&playertexture, sf::Vector2u(6, 5), 0.15f, 250.0f, 200.0f);

	/*sf::Texture iconstar;
	iconstar.loadFromFile("a/star1.png");
	Player star(&iconstar, sf::Vector2u(9, 3), 0.15f, 400.0f, 600.0f);*/
	
	/*sf::Texture starTexture;//รูป
	starTexture.loadFromFile("a/star1.png");
	sf::Sprite shapeStar;
	shapeStar.setTexture(starTexture);
	int spriteSizeX = starTexture.getSize().x / 8;
	int spriteSizeY = starTexture.getSize().y / 3;
	shapeStar.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	sf::Vector2f spawnPoint = { 450.f, 460.f };
	shapeStar.setPosition(spawnPoint);*/
	
	//Star
	sf::Texture STAR;
	STAR.loadFromFile("a/star4.png");
	std::vector <star> starVector;
	for (int posi = 0; posi < 1550; posi += 60) 
	{
		starVector.push_back(star(&STAR, sf::Vector2u(9, 1), 0.08f, 800.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 500; posi += 60)
	{
		starVector.push_back(star(&STAR, sf::Vector2u(9, 1), 0.08f, 2630.0f + posi, 370.0f));
	}
	/*star star1(&STAR, sf::Vector2u(8, 3), 0.15f,500.0f,350.0f);*/
	
	//Alien
	sf::Texture alien;
	alien.loadFromFile("a/alien.png");
	std::vector <Enemy> alienVector;
	starVector.push_back(star(&alien, sf::Vector2u(12, 8), 0.08f, 1700.0f , 550.0f));
	starVector.push_back(star(&alien, sf::Vector2u(12, 8), 0.08f, 600.0f , 370.0f));
	
	//Bullet
	sf::Texture BULLET;
	BULLET.loadFromFile("a/bullet1.png");
	Bullet bullet1(&BULLET, sf::Vector2u(3, 1), 0.15f, 600.0f, player.GetPosition());
	
	sf::Texture DOGRAKAI;
	DOGRAKAI.loadFromFile("a/dd.png");
	Dog rakai(&DOGRAKAI, sf::Vector2u(4, 9), 0.15f, player.GetPosition());

	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(1700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(2900.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(7500.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 50.0f), sf::Vector2f(5700.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 50.0f), sf::Vector2f(6100.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(6700.0f, 380.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(4050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(1250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(3650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(4100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(5100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2200.0f, 100.0f), sf::Vector2f(8900.0f, 670.0f)));

	bool slide;
	int Bul = 0;
	float deltaTime = 0.0f;
	sf::Clock clock;



	while (window.isOpen())
	{
		slide = false;

		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';

		player.update(deltaTime);
		rakai.update(deltaTime,player, player.GetPosition());
		//rakai.update(deltaTime, player.GetPosition());
		for (int i = 0; i < starVector.size(); i++) {
			starVector[i].update(deltaTime,player);
		}
		
		for (int i = 0; i < alienVector.size(); i++) {
			alienVector[i].update(deltaTime, player);
		}
		//star1.update(deltaTime,player);

		sf::Vector2f direction;

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		view.setCenter(player.GetPosition().x, 360.0f);
		if (view.getCenter().x - 540.0f <= 0.0f)
		{
			view.setCenter(540.0f, 360.0f);
		}
		if (view.getCenter().x + 540.0f >= 10000.0f)
		{
			view.setCenter(9460.0f, 360.0f);
		}

		window.clear();
		menu.draw(window);
		window.setView(view);//view
		window.draw(background);  
		for (Platform& platform : platforms)
		{
			platform.Draw(window);
		}
		//window.draw(background2);
		//window.draw(background);
		player.Draw(window);
		rakai.draw(window);

		for (int i = 0; i < starVector.size(); i++) {
			starVector[i].draw(window);
		}
		/*star1.draw(window);*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			bullet1.attack(pos);
			Bul = 1;
		}
		if (Bul == 1)
		{			
			bullet1.update(deltaTime);
			bullet1.draw(window);
		}
		if(player.GetPosition().x - bullet1.GetPosition().x <= -1000.0f)
		{
			Bul = 0;
			bullet1.isAvaliable();
		}
		window.display();
	}
	return 0;
}