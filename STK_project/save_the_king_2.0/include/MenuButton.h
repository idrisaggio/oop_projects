#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include "LoadResources.h"

//--------------------------------using section-------------------------------

using sf::RectangleShape;
using sf::Texture;
using sf::Vector2f;
using sf::RenderWindow;
using sf::Text;
using sf::Sprite;

//--------------------------------class section-------------------------------

class MenuButton
{
public:
	MenuButton(const Texture&, const Vector2f&, unsigned, string);
	~MenuButton() {};

	void draw(RenderWindow&); //draw menu btn
	Vector2f getPosition() const; // get position of menu button
	bool contains(const Vector2f&) const; //mouse contains or not
	void highlight(); // highlight action
	void unhighlight(); // unhighlight action

private:

	Sprite m_button; // main menu btn
	Sprite m_exitButton;

	Text m_text; // text play exit
	Font m_font;
};

