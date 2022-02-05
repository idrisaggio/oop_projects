#pragma once

//-------------------------------include section------------------------------
#include "Panel.h"

//---------------------------------func section-------------------------------

//this func initiates the panel and writes the names of each button category
void Panel::initPanel(sf::Texture* txrArray[])
{

	m_font.loadFromFile(FONT_PATH);

	m_text.push_back(Text("Players:", { 0, 0 }, m_font));
	m_text.push_back(Text("Objects:", { 190, 0 }, m_font));
	m_text.push_back(Text("Settings:", { 580,0 }, m_font));
	m_text.push_back(Text("Delete", { 200,60 }, m_font));

	int i = 0;

	for (int col = 0, x = 0; col < 7; col++, x += 100)
		for (int row = 0, y = 60; row < 2; row++, y += 60)
		{
			m_figureButton.push_back(FigureButton(txrArray[i],
				sf::Vector2f(x, y), FigureType(i)));
			i++;
		}
}

//----------------------------------------------------------------------------
ActionType Panel::handleClick(const sf::Vector2f& location) const 
{
	for (int figureType = 0; figureType < NUM_OF_TYPES; figureType++) 
	{
		if (m_figureButton[figureType].handleClick(location))
			return ActionType(int(m_figureButton[figureType].getType()));
	}

	return NoAction;
}

//----------------------------------------------------------------------------
//this func draws a button for each figure in the panel
void Panel::drawButton(sf::RenderWindow& window) const
{
	
	m_text[SETTINGS].draw(window);
	m_text[PLAYABLE_CHARACTERS].draw(window);
	m_text[OBJECTS].draw(window);
	m_text[SPACE].draw(window);

	for (int figureType = 0; figureType < NUM_OF_TYPES; figureType++)
		m_figureButton[figureType].draw(window);
}