#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include <memory>
#include "LoadResources.h"
#include "Macros.h"


//--------------------------------using section-------------------------------

using sf::Color;
using sf::Sprite;
using sf::RenderWindow;
using sf::RenderTexture;
using sf::Texture;
using sf::Vector2f;
using sf::RectangleShape;

//--------------------------------class section-------------------------------

class Board
{
public:

	Board() {}; // C-tor
	~Board() {}; // D-tor

	void create(const Vector2f&, unsigned, unsigned);
	void loadBoard(const Texture&);
	RenderTexture& getWindowSpace();
	void draw();
	void display(RenderWindow& window);
	void clearBoard();
	RectangleShape createWindowMsg(const Vector2f&);
	void loadingScreen(std::string, RenderWindow&, const Font&);
	void gameMessage(string, Vector2f, RenderWindow&, bool, const Font&);
	sf::Text setMsg(string, Vector2f, bool, const Font&);
	void waitEventGame(RenderWindow&);
	void endMsg(RenderWindow&, const Texture&, const Font&);

protected:
	RenderTexture m_windowSpace;
	Sprite m_sprite;

private:
	RectangleShape m_board;

};