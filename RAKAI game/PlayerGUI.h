#pragma once
#include "Player.h"

class Player;
class sf::RectangleShape;

class PlayerGUI
{
private:
	Player* player;

	sf::Font font;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	void initFont();
	void initHPBar();

public:
	PlayerGUI(Player* player);
	virtual ~PlayerGUI();

	//Functions
	void updateHPBar();
	void update(const float& dt);

	void renderHPBar(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};
