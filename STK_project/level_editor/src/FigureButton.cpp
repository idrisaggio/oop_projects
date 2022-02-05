#pragma once

//--------------------------------include section-----------------------------

#include "FigureButton.h"

//---------------------------------func section-------------------------------

//c-tor
FigureButton::FigureButton(const sf::Texture* figure,
	const sf::Vector2f& position,
	FigureType type) 
	: m_figure(figure), m_figureType(type)
{
	m_position = position;
}

//----------------------------------------------------------------------------
//copy c-tor
void FigureButton::draw(sf::RenderWindow& window) const 
{
	window.draw(create());

	auto sprite = sf::Sprite(*m_figure);
	sprite.setPosition({ m_position.x + 32, m_position.y + 4 });
	window.draw(sprite);
}

//----------------------------------------------------------------------------
FigureType FigureButton::getType() const {
	return m_figureType;
}

//----------------------------------------------------------------------------
sf::RectangleShape FigureButton::create() const
{
	auto result = sf::RectangleShape({ BUTTON_WIDTH, BUTTON_HEIGHT });
	result.setPosition(m_position);
	result.setFillColor(sf::Color::Transparent);
	result.setOutlineColor(sf::Color::White);
	result.setOutlineThickness(-1);
	return result;
}

//----------------------------------------------------------------------------
bool FigureButton::handleClick(const sf::Vector2f location) const
{
	return (create().getGlobalBounds().contains(location));
}