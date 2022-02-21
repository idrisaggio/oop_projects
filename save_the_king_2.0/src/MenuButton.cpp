#pragma once

//-------------------------------include section------------------------------

#include "MenuButton.h"

//---------------------------------func section-------------------------------

//c-tor of rectangle  button for main menu
MenuButton::MenuButton(const Texture& texture, const Vector2f& position, unsigned btnSize, string text)
{
	m_button.setTexture(texture);	 //texture btn for main menu with sprite
	m_button.setPosition(position);
	m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);	// set origin to the middle
	//set text of button
	m_text.setString(text);

	m_font.loadFromFile("pixel.ttf");// change 
	m_text.setFont(m_font);	//font					
	m_text.setCharacterSize(btnSize - MARGE);//size of letters
	////position in game
	m_text.setPosition(m_button.getPosition().x, m_button.getPosition().y + 32);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().width / 2);
}

//----------------------------------------------------------------------------

void MenuButton::draw(RenderWindow& window)
{
	window.draw(m_button); //for main menu
	window.draw(m_text); //for main menu
}

//----------------------------------------------------------------------------

bool MenuButton::contains(const Vector2f& posistion) const
{
	//if mouse in play or exit
	return (m_button.getGlobalBounds().contains(posistion) ||
		m_exitButton.getGlobalBounds().contains(posistion));
}

//----------------------------------------------------------------------------

void MenuButton::highlight()
{
	m_button.setColor(sf::Color::Red);
}

//----------------------------------------------------------------------------

void MenuButton::unhighlight()
{
	m_button.setColor(sf::Color::Cyan);
}

//----------------------------------------------------------------------------

Vector2f MenuButton::getPosition() const
{
	return m_button.getPosition();
}