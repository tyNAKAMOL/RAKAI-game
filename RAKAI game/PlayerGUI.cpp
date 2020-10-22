//#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont()
{
	this->font.loadFromFile("Font/FiraCode-Light");
}

void PlayerGUI::initHPBar()
{
	float w = 300.0f;
	float h = 50.0f;
	float x = 20.0f;
	float y = 20.0f;

	this->hpBarBack.setSize(sf::Vector2f(w, h));
	this->hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBarBack.setPosition(x, y);

	this->hpBarInner.setSize(sf::Vector2f(w, h));
	this->hpBarInner.setFillColor(sf::Color(250, 20, 20, 200));
	this->hpBarInner.setPosition(this->hpBarBack.getPosition());
}
PlayerGUI::PlayerGUI(Player* player)
{
	this->player = player;
	
	this->initFont();
	this->initHPBar();
}
PlayerGUI::~PlayerGUI()
{
		
}

void PlayerGUI::updateHPBar()
{
}

//Funtions
void PlayerGUI::update(const float& dt)
{

}
void PlayerGUI::renderHPBar(sf::RenderWindow& window)
{
	window.draw(this->hpBarInner);
	window.draw(this->hpBarInner);
}
void PlayerGUI::render(sf::RenderWindow& window)
{
	this->renderHPBar(window);
}