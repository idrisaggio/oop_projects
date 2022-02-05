#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include "macros.h"

//---------------------------------class section------------------------------
class Figure {
public:
	Figure(FigureType, sf::Texture*, const sf::Vector2f&);
	
	void draw(sf::RenderWindow&) const;
	bool handleClick(const sf::Vector2f&);
	FigureType getType() const;

	Figure& operator=(const Figure&);

private:
	sf::Sprite create() const;

	FigureType m_FigureType = FigureType::Empty;
	sf::Vector2f m_position;
	sf::Texture* m_texture;
};