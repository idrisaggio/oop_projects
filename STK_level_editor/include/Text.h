#pragma once

//-------------------------------include section------------------------------

#include "macros.h"
#include <SFML/Graphics.hpp>

//---------------------------------class section------------------------------

class Text{
public:
	Text(const std::string&, const sf::Vector2f&, const sf::Font&);
	//----------------------------------------------
	void draw(sf::RenderWindow& window) const;
private:
	sf::Vector2f m_position;
	std::string m_text;
	sf::Font m_font;
};