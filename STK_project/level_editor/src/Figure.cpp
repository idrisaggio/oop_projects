#pragma once

//--------------------------------include section-----------------------------

#include "Figure.h"

//---------------------------------func section------------------------------

//c-tor
Figure::Figure(FigureType FigureType, sf::Texture* texture,
						const sf::Vector2f& position) :
	m_FigureType(FigureType), m_texture(texture), m_position(position){}


//----------------------------------------------------------------------------
void Figure::draw(sf::RenderWindow& window) const
{
	window.draw(create());
}

//----------------------------------------------------------------------------
bool Figure::handleClick(const sf::Vector2f& position)
{
	return create().getGlobalBounds().contains(position);
}

//----------------------------------------------------------------------------
FigureType Figure::getType() const 
{
	return m_FigureType;
}

//----------------------------------------------------------------------------
//assignment operator
 Figure& Figure::operator=(const Figure& other) 
 {
	m_FigureType = other.m_FigureType;
	m_texture = other.m_texture;
	m_position = other.m_position;
	return *this;
}

//----------------------------------------------------------------------------
sf::Sprite Figure::create() const
{
	auto sprite = sf::Sprite(*m_texture);
	sprite.setPosition(m_position);
	return sprite;
}