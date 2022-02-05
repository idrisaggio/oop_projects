#pragma once

//--------------------------------include section-----------------------------

#include "Text.h"
#include "macros.h"

//---------------------------------func section-------------------------------

//c-tor
Text::Text(const std::string& text,
	const sf::Vector2f& position,
	const sf::Font& font) 
	: m_text(text), m_font(font) 
{
	m_position = position;
}

//----------------------------------------------------------------------------
void Text::draw(sf::RenderWindow& window) const 
{
	auto text = sf::Text(m_text, m_font);
	text.setPosition({ m_position.x + 20, m_position.y + 4 });
	window.draw(text);
}
