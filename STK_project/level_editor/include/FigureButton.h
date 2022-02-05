#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include "Macros.h"

//---------------------------------class section------------------------------

class FigureButton 
{
public:
	FigureButton(const sf::Texture*, const sf::Vector2f&, FigureType);

	sf::RectangleShape create() const;
	bool handleClick(const sf::Vector2f location) const;
	void draw(sf::RenderWindow& window) const;
	FigureType getType() const;

private:
	FigureType m_figureType;
	const sf::Texture* m_figure;
	sf::Vector2f m_position;
};