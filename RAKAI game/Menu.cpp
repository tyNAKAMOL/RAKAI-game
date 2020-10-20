#include "Menu.h"

Menu::Menu(float W, float H)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//
	}
	menu[0].setFont(font);
	//menu[0].setColor(sf::Color::Red);
	menu[0].setString("PLAY");
	menu[0].setPosition(sf::Vector2f(W / 2, H / (MAX_NUMBER_OF_ITEMS + 1)*1));

	menu[1].setFont(font);
	//menu[1].setColor(sf::Color::White);
	menu[1].setString("SCORE");
	menu[1].setPosition(sf::Vector2f(W / 2, H / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	//menu[2].setColor(sf::Color::Blue);
	menu[2].setString("EXIT");
	menu[2].setPosition(sf::Vector2f(W / 2, H / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}
Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}