#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

//-------------------------------include section------------------------------

#include "LoadResources.h"
#include "MenuButton.h"
#include "Board.h"

//--------------------------------using section-------------------------------

using std::unique_ptr;
using sf::RenderWindow;
using sf::RectangleShape;
using std::vector;
using sf::VideoMode;
using std::make_unique;
using sf::Vector2f;
using sf::Event;

//--------------------------------class section-------------------------------

class Menu
{
public:
	Menu() {};
	~Menu() {};

	void startMenu();
	void loadingScreen(std::string);
	void setMenuTxr(const vector<Texture>);

private:
	bool m_startGame = false;
	bool m_menuMusic = true;

	sf::Text m_status; //step game

	void draw(); // draw menu
	void handleEvents();

	vector<Texture> m_menuTxr;

	RenderWindow m_menuWindow; 	//window for menu
	RenderWindow m_helpWindow;

	RectangleShape m_menuBackground; // rectangle background
	RectangleShape m_helpBackground;

	unique_ptr<MenuButton> m_playButton; //play btn in main menu
	unique_ptr<MenuButton> m_instButton;
	unique_ptr<MenuButton> m_exitButton; //exit btn in main menu
};

