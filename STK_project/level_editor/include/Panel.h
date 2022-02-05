#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Text.h"
#include "FigureButton.h"


//---------------------------------class section------------------------------

class Panel {
public:
	Panel() {};
	void initPanel(sf::Texture* []);
	ActionType handleClick(const sf::Vector2f&) const;
	void drawButton(sf::RenderWindow&) const;
	
	//void highLight(const Vector2f&);
	//void unHighLight(const Vector2f&);

private:
	std::vector<FigureButton> m_figureButton;
	std::vector<Text> m_text;
	sf::Font m_font;
};