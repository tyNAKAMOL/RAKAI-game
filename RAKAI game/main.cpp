#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <utility>
#include <algorithm>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "Dog.h"
#include "star.h"
#include "Enemy.h"
#include "Bloodup.h"
#include "Buff.h"
#include "Boss.h"
using namespace std;

void HighScore(int x, int y, string str, sf::RenderWindow& window, sf::Font* font) {
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(str);
	text.setCharacterSize(50);
	window.draw(text);
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Rakai");
	sf::View view(sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1080.0f, 720.0f));//view

	///////////////////////////////////////////////////////////
	//BGMENU1
	sf::RectangleShape bg(sf::Vector2f(1080.0f, 720.0f));
	bg.setPosition(0.0f, 0.0f);
	sf::Texture s;
	s.loadFromFile("a/statestart.png");
	bg.setTexture(&s);

	//BGBGMENU2
	sf::RectangleShape bg1(sf::Vector2f(1080.0f, 720.0f));
	bg1.setPosition(0.0f, 0.0f);
	sf::Texture s1;
	s1.loadFromFile("a/state1.png");
	bg1.setTexture(&s1);

	//BGMENU3
	sf::RectangleShape bg2(sf::Vector2f(1080.0f, 720.0f));
	bg2.setPosition(0.0f, 0.0f);
	sf::Texture s2;
	s2.loadFromFile("a/state2.png");
	bg2.setTexture(&s2);

	//BGMENU3
	sf::RectangleShape bg3(sf::Vector2f(1080.0f, 720.0f));
	bg3.setPosition(0.0f, 0.0f);
	sf::Texture s3;
	s3.loadFromFile("a/state3.png");
	bg3.setTexture(&s3);

	//BGMENU4
	sf::RectangleShape bg4(sf::Vector2f(1080.0f, 720.0f));
	bg4.setPosition(0.0f, 0.0f);
	sf::Texture s4;
	s4.loadFromFile("a/state4.png");
	bg4.setTexture(&s4);
	//////////////////////////////////////////////////////////

	//BG1
	sf::RectangleShape background(sf::Vector2f(10000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("a/BG7.png");
	background.setTexture(&space);

	//BG2
	sf::RectangleShape background1(sf::Vector2f(10000.0f, 720.0f));
	background1.setPosition(10000.0f, 0.0f);
	sf::Texture space1;
	space1.loadFromFile("a/BGG3.png");
	background1.setTexture(&space1);

	//BG3
	sf::RectangleShape background2(sf::Vector2f(10000.0f, 720.0f));
	background2.setPosition(20000.0f, 0.0f);
	sf::Texture space2;
	space2.loadFromFile("a/BGG4.png");
	background2.setTexture(&space2);

	//Music
	sf::SoundBuffer sound1;
	if (!sound1.loadFromFile("a/Flowing Rocks.ogg"))
		return -1;

	sf::Sound Sound;
	Sound.setBuffer(sound1);
	//Sound.setLoop(true);
	//Sound.play();

	//Music2
	sf::SoundBuffer sound2;
	if (!sound2.loadFromFile("a/laser5.ogg"))
		return -1;

	sf::Sound Sound1;
	Sound1.setBuffer(sound2);

	//soundjump
	sf::SoundBuffer soundjump;
	soundjump.loadFromFile("a/phaseJump4.ogg");
	sf::Sound Sound2;
	Sound2.setBuffer(soundjump);

	//Scorestar
	int countscorestar = 0;
	sf::Font font;
	font.loadFromFile("a/CookieRun-Bold.otf");
	std::ostringstream score;
	sf::Text Score;
	Score.setCharacterSize(30);
	Score.setString(score.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::Yellow);

	//scoregame

	int countscore = 0;
	sf::Font SCORE;
	SCORE.loadFromFile("a/CookieRun-Bold.otf");
	std::ostringstream score1;
	sf::Text scoregame;
	scoregame.setCharacterSize(50);
	scoregame.setString(score1.str());
	scoregame.setFont(SCORE);
	scoregame.setFillColor(sf::Color::Yellow);

	//hp font
	sf::Font Hppush;
	Hppush.loadFromFile("a/CookieRun-Bold.otf");
	std::ostringstream hppush;
	sf::Text Hpblood;
	Hpblood.setCharacterSize(30);
	Hpblood.setString(hppush.str());
	Hpblood.setFont(font);
	Hpblood.setFillColor(sf::Color::Red);

	sf::Text Hpblood2;
	Hpblood2.setCharacterSize(30);
	Hpblood2.setString(hppush.str());
	Hpblood2.setFont(font);
	Hpblood2.setFillColor(sf::Color::Red);

	sf::Text bulA;
	bulA.setCharacterSize(30);
	bulA.setString(hppush.str());
	bulA.setFont(font);
	bulA.setFillColor(sf::Color::Red);

	//Player
	sf::Texture playertexture;
	playertexture.loadFromFile("a/as2.png");
	Player player(&playertexture, sf::Vector2u(6, 5), 0.15f, 250.0f, 200.0f);

	//ITEM
	//Bloodup
	sf::Texture BLOODUP;
	BLOODUP.loadFromFile("a/up2.png");
	std::vector <Bloodup> BloodupVector;
	BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(3, 1), 0.08f, 3456.0f, 180.0f));
	BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(3, 1), 0.08f, 8474.0f, 540.0f));
	BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(3, 1), 0.08f, 12033.0f, 370.0f));
	BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(3, 1), 0.08f, 14818.0f, 390.0f));
	BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(3, 1), 0.08f, 23532.0f, 370.0f));
	BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(3, 1), 0.08f, 27265.0f, 180.0f));

	//Blooddown
	sf::Texture BLOODDOWN;
	BLOODDOWN.loadFromFile("a/down.png");
	std::vector <Bloodup> BlooddownVector;
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 2192.0f, 545.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 3249.0f, 370.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 6840.0f, 280.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 4655.0f, 545.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 8003.0f, 545.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 14090.0f, 545.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 21981.0f, 370.0f));
	BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(3, 1), 0.08f, 26445.0f, 280.0f));

	//X10
	sf::Texture POINTX2;
	POINTX2.loadFromFile("a/iconx10.png");
	std::vector <Buff> X2Vector;
	X2Vector.push_back(Buff(&POINTX2, sf::Vector2u(3, 1), 0.08f, 5506.0f, 380.0f));
	X2Vector.push_back(Buff(&POINTX2, sf::Vector2u(3, 1), 0.08f, 13442.0f, 545.0f));
	X2Vector.push_back(Buff(&POINTX2, sf::Vector2u(3, 1), 0.08f, 27265.0f, 545.0f));

	sf::Texture stateX10;
	stateX10.loadFromFile("a/xx10.png");
	sf::RectangleShape x10(sf::Vector2f(180, 180));
	x10.setTexture(&stateX10);

	//key
	sf::Texture keyW;
	keyW.loadFromFile("a/ww.png");
	sf::RectangleShape ww(sf::Vector2f(32, 32));
	ww.setPosition(sf::Vector2f(850, 30));
	ww.setTexture(&keyW);
	sf::Texture keyS;
	keyS.loadFromFile("a/ss.png");
	sf::RectangleShape ss(sf::Vector2f(32, 32));
	ss.setPosition(sf::Vector2f(850, 67));
	ss.setTexture(&keyS);
	sf::Texture keyD;
	keyD.loadFromFile("a/ddd.png");
	sf::RectangleShape dd(sf::Vector2f(32, 32));
	dd.setPosition(sf::Vector2f(850, 106));
	dd.setTexture(&keyD);
	sf::Texture keySP;
	keySP.loadFromFile("a/spp.png");
	sf::RectangleShape sp(sf::Vector2f(32, 32));
	sp.setPosition(sf::Vector2f(850, 146));
	sp.setTexture(&keySP);
	
	
	sf::Text jump2;
	jump2.setCharacterSize(25);
	jump2.setString(hppush.str());
	jump2.setFont(font);
	jump2.setFillColor(sf::Color::White);
	sf::Text slide2;
	slide2.setCharacterSize(25);
	slide2.setString(hppush.str());
	slide2.setFont(font);
	slide2.setFillColor(sf::Color::White);
	sf::Text run;
	run.setCharacterSize(25);
	run.setString(hppush.str());
	run.setFont(font);
	run.setFillColor(sf::Color::White);
	sf::Text attack2;
	attack2.setCharacterSize(25);
	attack2.setString(hppush.str());
	attack2.setFont(font);
	attack2.setFillColor(sf::Color::White);
	////////////////////////////////////////////////////////////
	//endscore
	int EndScore = 0;
	sf::Text Send;
	Send.setCharacterSize(40);
	//Send.setString(hppush.str());
	Send.setFont(font);
	Send.setFillColor(sf::Color::White);
	//Send.setPosition(100, 150);

	//endscorestar
	int EndNumStar = 0;
	sf::Text CSTER;
	sf::Font gameover;
	gameover.loadFromFile("a/CookieRun-Bold.otf");
	CSTER.setCharacterSize(40);
	CSTER.setString(hppush.str());
	CSTER.setFont(gameover);
	CSTER.setFillColor(sf::Color::White);
	//CSTER.setPosition(100, 200);

	//newscore
	sf::Text NewScore;
	NewScore.setCharacterSize(60);
	NewScore.setString(hppush.str());
	NewScore.setFont(font);
	NewScore.setFillColor(sf::Color::White);
	//NewScore.setPosition(100, 100);
	//////////////////////////////////////////////////////////////////////////////////
	//HPbar
	sf::Texture HPbar;
	HPbar.loadFromFile("a/Blo.png");
	sf::Sprite hpbar;
	hpbar.setTexture(HPbar);
	hpbar.setPosition(300, -100);

	float MyHP = 78000;
	hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(MyHP / 250.0f, 30));
	HP.setPosition(sf::Vector2f(450, 46));
	HP.setFillColor(sf::Color::Magenta);
	HP.setSize(sf::Vector2f(MyHP / 320.f, 15));

	//HP Boss
	float HPBoss = 50000;
	//hpbar.setTexture(HPbar);
	sf::RectangleShape Hp(sf::Vector2f(HPBoss / 250.0f, 30));
	Hp.setPosition(sf::Vector2f(450, 446));
	Hp.setFillColor(sf::Color::Black);
	Hp.setSize(sf::Vector2f(HPBoss / 320.f, 15));

	//Star
	sf::Texture STAR;
	STAR.loadFromFile("a/star4.png");
	std::vector <star*> starVector;
	
	//map1
	for (int posi = 0; posi < 1550; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 800.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 200; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 2630.0f + posi, 370.0f));
	}
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 2850.0f, 320.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 2900.0f, 300.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 2950.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 3000.0f, 300.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 3050.0f, 320.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 3100.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 3150.0f, 370.0f));

	for (int posi = 0; posi < 1300; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 3500.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 500; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 4700.0f + posi, 550.0f));
	}
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 5743.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 5770.0f, 330.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 5800.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 5850.0f, 260.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 5900.0f, 240.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 5950.0f, 260.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6000.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6030.0f, 330.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6070.0f, 370.0f));

	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6167.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6180.0f, 340.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6210.0f, 310.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6250.0f, 305.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6300.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6340.0f, 250.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6451.0f, 310.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6340.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6451.0f, 280.0f));

	for (int posi = 0; posi < 600; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 7250.0f + posi, 370.0f));
	}

	//map2
	for (int posi = 0; posi < 1550; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 10800.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 200; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 12630.0f + posi, 370.0f));
	}
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 12850.0f, 320.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 12900.0f, 300.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 12950.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 13000.0f, 300.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 13050.0f, 320.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 13100.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 13150.0f, 370.0f));

	for (int posi = 0; posi < 1300; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 13500.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 80; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 14700.0f + posi, 550.0f));
	}
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 15743.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 15770.0f, 330.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 15800.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 15850.0f, 260.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 15900.0f, 240.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 15950.0f, 260.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16000.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16030.0f, 330.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16070.0f, 370.0f));

	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16167.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16180.0f, 340.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16210.0f, 310.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16250.0f, 305.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16300.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16340.0f, 250.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16400.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16451.0f, 310.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16340.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16400.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 16451.0f, 280.0f));

	for (int posi = 0; posi < 600; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 17250.0f + posi, 370.0f));
	}

	//map3
	for (int posi = 0; posi < 1550; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 20800.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 200; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 22630.0f + posi, 370.0f));
	}
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 22850.0f, 320.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 22900.0f, 300.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 22950.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 23000.0f, 300.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 23050.0f, 320.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 23100.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 23150.0f, 370.0f));

	for (int posi = 0; posi < 1300; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 23500.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 500; posi += 60){
		starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 24700.0f + posi, 550.0f));
	}
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 25743.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 25770.0f, 330.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 25800.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 25850.0f, 260.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 25900.0f, 240.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 25950.0f, 260.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26000.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26030.0f, 330.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26070.0f, 370.0f));

	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26167.0f, 370.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26180.0f, 340.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26210.0f, 310.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26250.0f, 305.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26300.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26340.0f, 250.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 26400.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6451.0f, 310.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6340.0f, 290.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
	starVector.push_back(new star(&STAR, sf::Vector2u(9, 1), 0.08f, 6451.0f, 280.0f));

	//Alien
	sf::Texture alien;
	alien.loadFromFile("a/alien3.png");
	std::vector <Enemy> alienVector;
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 2331.0f, 564.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 3071.0f, 377.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 5337.0f, 564.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 6815.0f, 280.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 8928.0f, 564.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 11580.0f, 564.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 15504.0f, 564.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 16943.0f, 280.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 22955.0f, 377.0f));
	alienVector.push_back(Enemy(&alien, sf::Vector2u(12, 8), 0.08f, 25416.0f, 564.0f));

	//Boss
	sf::Texture Bossalien;
	Bossalien.loadFromFile("a/boss.png");
	std::vector <Boss> BossV;
	BossV.push_back(Boss(&Bossalien, sf::Vector2u(4, 4), 0.08f, 500.0f, 655.0f));

	//Bullet
	sf::Texture BULLET;
	BULLET.loadFromFile("a/bullet1.png");
	Bullet bullet1(&BULLET, sf::Vector2u(3, 1), 0.15f, 600.0f, player.GetPosition());

	//Dog
	sf::Texture DOGRAKAI;
	DOGRAKAI.loadFromFile("a/dd.png");
	Dog rakai(&DOGRAKAI, sf::Vector2u(4, 9), 0.15f, player.GetPosition());

	//Platform
	std::vector<Platform> platforms;

	//map1
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
	platforms.push_back(Platform(nullptr, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(7800.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(20000.0f, 100.0f), sf::Vector2f(10000.0f, 670.0f)));
	//map2
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(11700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(12900.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 100.0f), sf::Vector2f(16693.0f, 160.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 120.0f), sf::Vector2f(14793.0f, 545.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(17500.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 50.0f), sf::Vector2f(15700.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 50.0f), sf::Vector2f(16100.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(16700.0f, 380.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(14050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(11250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(13650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(14100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(15100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(17800.0f, 670.0f)));
	//map3
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(21700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(22900.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 50.0f), sf::Vector2f(25700.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 50.0f), sf::Vector2f(26100.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(26700.0f, 380.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(24050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(21250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(23650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(24100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(25100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(30000.0f, 100.0f), sf::Vector2f(20000.0f, 670.0f)));

	sf::Texture doorwarp;
	doorwarp.loadFromFile("a/door5.png");

	sf::Texture doorwarp1;
	doorwarp1.loadFromFile("a/door.png");

	//เปลี่ยนด่าน
	sf::RectangleShape warpPoint(sf::Vector2f(200, 300));
	warpPoint.setPosition(sf::Vector2f(9221.67, 320));
	warpPoint.setTexture(&doorwarp);

	sf::RectangleShape warpPoint1(sf::Vector2f(200, 300));
	warpPoint1.setPosition(sf::Vector2f(18805, 320));
	warpPoint1.setTexture(&doorwarp1);

	//starup
	sf::Texture starup;
	starup.loadFromFile("a/starpoint.png");
	sf::RectangleShape starPoint(sf::Vector2f(50, 50));
	starPoint.setPosition(sf::Vector2f(80, 80));
	starPoint.setTexture(&starup);

	//end
	sf::Texture end;
	end.loadFromFile("a/enggame.png");
	sf::RectangleShape ee(sf::Vector2f(1080, 720));
	ee.setTexture(&end);

	/// <summary>
	/// ////////////////////////////////////////////////////////////////////////
	/// </summary>
	/// <returns></returns>
	sf::Text endGametext;
	sf::Text endScore;
	sf::Font texegame;

	texegame.loadFromFile("a/CookieRun-Bold.otf");
	endGametext.setFont(texegame);
	endGametext.setFillColor(sf::Color::Red);
	endGametext.setCharacterSize(50);
	endGametext.setString("Game Over");

	endScore.setFont(font);
	endScore.setFillColor(sf::Color::Red);
	endScore.setCharacterSize(50);
	endScore.setPosition(30, 150);
	//////////////////////////////////////////////////////////////////////////
	int Bul = 0;
	int count, i = 0;
	int scoreX2 = 1;
	int state = 0;
	int f = 0;
	
	float deltaTime = 0.0f;
	float countTimeAdd = 0;
	float countTimeSub = 0;
	float countTimeBul = 0;
	float countTimex2 = 0;

	sf::Clock clock;
	
	bool slide;
	bool checkBul = false;
	bool checkAdd = false;
	bool checkSub = false;
	bool checkx2 = false;
	bool START = false;
	bool MENU = true;
	bool SCORE1 = true;
	bool endGame = false;

	bool DebouceDown = false;
	bool DebouceUp = false;

	while (window.isOpen())
	{
		while (MENU == true)
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			std::cout << mouesPosition.x << ' ' << mouesPosition.y << '\n';

			deltaTime = clock.restart().asSeconds();
			window.draw(bg);
			window.draw(bg1);
			window.display();

			if ((mouesPosition.x >= 427 && mouesPosition.x <= 660) && (mouesPosition.y >= 275 && mouesPosition.y <= 348)) {
				window.draw(bg);
				window.draw(bg2);
				window.display();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					MENU = false;
					START = true;
				}
			}
			else if ((mouesPosition.x >= 427 && mouesPosition.x <= 660) && (mouesPosition.y >= 395 && mouesPosition.y <= 466)) {
				window.draw(bg);
				window.draw(bg3);
				window.display();
			}
			else if ((mouesPosition.x >= 427 && mouesPosition.x <= 660) && (mouesPosition.y >= 515 && mouesPosition.y <= 584)) {
				window.draw(bg);
				window.draw(bg4);
				window.display();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					window.close();
					break;
				}
			}
		}	

		while (START == true){
			
			slide = false;
			count = player.GetPosition().x;

			deltaTime = clock.restart().asSeconds();
			sf::Vector2f pos = player.GetPosition();
			std::cout << pos.x << ' ' << pos.y << '\n';

			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			player.update(deltaTime, starVector,X2Vector);
			rakai.update(deltaTime, player, player.GetPosition());

			//Star
			for (int i = 0; i < starVector.size(); i++){
				starVector[i]->update(deltaTime);
			}
			//Bloodup
			for (int i = 0; i < BloodupVector.size(); i++){
				BloodupVector[i].update(deltaTime, player);
			}

			//Blooddown
			for (int i = 0; i < BlooddownVector.size(); i++){
				BlooddownVector[i].update(deltaTime, player);
			}

			//X10
			for (int i = 0; i < X2Vector.size(); i++){
				X2Vector[i].update(deltaTime);
			}

			//Alien
			for (int i = 0; i < alienVector.size(); i++){
				alienVector[i].update1(deltaTime, bullet1);
				alienVector[i].update2(deltaTime, player);
			}

			//Boss
			for (int i = 0; i < BossV.size(); i++) {
				BossV[i].updateBoss(deltaTime, bullet1);
				//BossV[i].updateMove(deltaTime, player);
			}
			
			sf::Vector2f direction;
			for (Platform& platform : platforms)
				if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
					player.OnCollision(direction);

			score1.str(" ");
			score1 << "SCORE :  " << int(pos.x - 200);
			EndScore = int(pos.x - 200);
			EndNumStar = player.getNumStar();
			scoregame.setPosition({ 40,30 });
			scoregame.setString(score1.str());
			
			hppush.str(" ");
			hppush << "JUMP";
			jump2.setString(hppush.str());

			hppush.str(" ");
			hppush << "SLIDE";
			slide2.setString(hppush.str());

			hppush.str(" ");
			hppush << "RUN";
			run.setString(hppush.str());

			hppush.str(" ");
			hppush << "ATTACK";
			attack2.setString(hppush.str());

			Score.setPosition({ 425, 90 });
			jump2.setPosition({ 900, 30 });
			slide2.setPosition({ 900, 67 });
			run.setPosition({ 900, 106 });
			attack2.setPosition({ 900,146 });
			
			if (pos.x > 500){
				hpbar.setPosition(view.getCenter().x - 210, -90); // blood
				HP.setPosition(view.getCenter().x - 60, 56);
				Score.setPosition(view.getCenter().x - 485, 95);
				scoregame.setPosition(view.getCenter().x - 510, 30);
				starPoint.setPosition(view.getCenter().x - 480 , 88);

				jump2.setPosition({ view.getCenter().x + 370 , 30 });
				slide2.setPosition({ view.getCenter().x + 370 , 67 });
				run.setPosition({ view.getCenter().x + 370 , 106 });
				attack2.setPosition({ view.getCenter().x + 370 , 146 });

				ww.setPosition({ view.getCenter().x + 330 , 30 });
				ss.setPosition({ view.getCenter().x + 330 , 67 });
				dd.setPosition({ view.getCenter().x + 330 , 106 });
				sp.setPosition({ view.getCenter().x + 330 , 146 });
			}

			view.setCenter(player.GetPosition().x, 360.0f);
			if (view.getCenter().x - 540.0f <= 0.0f){
				view.setCenter(540.0f, 360.0f);
			}
			if (view.getCenter().x + 540.0f >= 30000.0f){
				view.setCenter(29460.0f, 360.0f);
			}

			//Score
			score.str(" ");
			score << "      " << player.getNumStar();
			Score.setString(score.str());
			
			//
			hppush.str(" ");
			hppush << "  " << EndScore;
			Send.setString(hppush.str());
			
			hppush.str(" ");
			hppush << "  " << EndNumStar;
			CSTER.setString(hppush.str());
			
			hppush.str(" ");
			hppush << "  " << EndScore + EndNumStar;
			NewScore.setString(hppush.str());

			//Alien
			for (i = 0; i < alienVector.size(); i++) {
				if (alienVector[i].colAlien() == 2){
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
				}
			}

			//Bloodup
			for (i = 0; i < BloodupVector.size(); i++) {
				if (BloodupVector[i].colBloodup() == 1){
					MyHP += 5000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					if (MyHP > 78000) MyHP = 78000;
					hppush.str(" ");
					hppush << "+5000 HP";
					Hpblood.setString(hppush.str());
					Hpblood.setPosition({ player.GetPosition().x,player.GetPosition().y - 90 });
					checkAdd = true;
				}
			}
			if (checkAdd == true) {
				countTimeAdd += deltaTime;
				if (countTimeAdd > 0.75) {
					Hpblood.setPosition({ -800, 350 });
					countTimeAdd = 0;
					checkAdd = false;
				}
			}
			//Blooddown
			for (i = 0; i < BlooddownVector.size(); i++) {
				if (BlooddownVector[i].colBlooddown() == 2){
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					hppush.str(" ");
					hppush << "-5000 HP";
					Hpblood2.setString(hppush.str());
					Hpblood2.setPosition({ player.GetPosition().x,player.GetPosition().y - 90 });
					checkSub = true;
				}
			}
			if (checkSub == true) {
				countTimeSub += deltaTime;
				if (countTimeSub > 0.75) {
					Hpblood2.setPosition({ -800, 350 });
					countTimeSub = 0;
					checkSub = false;
				}
			}
			
			//X10
			x10.setPosition(player.GetPosition().x , player.GetPosition().y-30);
			if (player.getBuffStatus() == true) {
				std::cout << "YUITORPP";
				state = 1;
				window.draw(x10);
			}
			else {
				state = 0;
			}

			//เลือดลด
			
			endGametext.setPosition(view.getCenter().x - 150 , view.getCenter().y);
			ee.setPosition(view.getCenter().x - 540,0);
			Send.setPosition(view.getCenter().x-100 ,440);
			CSTER.setPosition(view.getCenter().x-100,516);
			NewScore.setPosition(view.getCenter().x-108 ,277);

			MyHP -= 5;
			if (MyHP < 78000){
				HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
				if (MyHP < 0){
					MyHP = 0; 
					endGame = true;
				}
			}
			if (endGame == true) {
				f = 5;
				state = 2;
			}
			//วาป
			if ((player.GetPosition().x >= 9221 && player.GetPosition().x <= 9300) && player.GetPosition().y == 545){
				player.SetPosition(10568, 40);
				rakai.SetPosition(10568, 40);
			}
			if ((player.GetPosition().x >= 18805 && player.GetPosition().x <= 18820) && player.GetPosition().y == 545){
				player.SetPosition(20568, 40);
				rakai.SetPosition(20568, 40);
			}

			//Boss
			for (int i = 0; i < BossV.size(); i++) {
				if (BossV[i].hit() == 1) {
					HPBoss -= 50;
					Hp.setSize(sf::Vector2f(HPBoss / 320.f, 15));
					if (HPBoss < 0)
					{
						HPBoss = 0;
						BossV[i].MOVE();
					}
				}
			}

			window.clear();
			window.setView(view);//view
			for (Platform& platform : platforms){
				platform.Draw(window);
			}
			
			//draw
			window.draw(background);
			window.draw(background1);
			window.draw(background2);
			window.draw(warpPoint);
			window.draw(warpPoint1);
			window.draw(starPoint);
			window.draw(ss);
			window.draw(dd);
			window.draw(ww);
			window.draw(sp);
			//HighScore(10, 40, "HIGHSCORE", window, &font);
			if (state == 1) {
				window.draw(x10);
			}
			player.Draw(window);
			rakai.draw(window);
			window.draw(hpbar);
			window.draw(HP);
			window.draw(Hp);
			window.draw(Score);
			window.draw(jump2);
			window.draw(slide2);
			window.draw(run);
			window.draw(attack2);
			window.draw(scoregame);
			window.draw(Hpblood);
			window.draw(Hpblood2);
			for (int i = 0; i < starVector.size(); i++){
				starVector[i]->draw(window);
			}
			for (int i = 0; i < BloodupVector.size(); i++){
				BloodupVector[i].draw(window);
			}
			for (int i = 0; i < BlooddownVector.size(); i++){
				BlooddownVector[i].draw(window);
			}
			for (int i = 0; i < X2Vector.size(); i++){
				X2Vector[i].draw(window);
			}
			for (int i = 0; i < alienVector.size(); i++){
				alienVector[i].draw(window);
			}
			for (int i = 0; i < BossV.size(); i++) {
				BossV[i].draw(window);
			}
			if (state == 2) {
				window.draw(ee);
				window.draw(CSTER);
				window.draw(NewScore);
				window.draw(Send);
				//window.draw(endGametext);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
				Sound2.play();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
				Sound1.play();
				bullet1.attack(pos);
				Bul = 1;
			}
			if (Bul >= 1){
				bullet1.update(deltaTime);
				bullet1.draw(window);
				for (i = 0; i < 10; i++) {
					if (alienVector[i].hit() == 1){
						countscorestar += 500;
						hppush.str(" ");
						hppush << "+500";
						bulA.setString(hppush.str());
						bulA.setPosition({ bullet1.GetPosition().x,bullet1.GetPosition().y - 90 });
						bullet1.del();
						checkBul = true;
					}
				}
				if (checkBul == true) {
					countTimeBul += deltaTime;
					if (countTimeBul > 0.35) {
						bulA.setPosition({ -800, 350 });
						countTimeBul = 0;
						checkBul = false;
					}
				}
			}
			if (player.GetPosition().x - bullet1.GetPosition().x <= -1000.0f){
				Bul = 0;
				bullet1.isAvaliable();
			}
			window.draw(bulA);
			window.display();
		}

	}
	return 0;
}