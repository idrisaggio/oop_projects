#pragma once

//-------------------------------include section------------------------------

#include "StatusBar.h"

//---------------------------------func section-------------------------------

void StatusBar::updateLevel()
{
	m_level++;
}

//----------------------------------------------------------------------------

//reset timer or the time elapsed 
void StatusBar::updateTimer(float time)
{
	m_gameTime.restart();
	m_timer = time;
	m_elapsedTime = time;
}

//----------------------------------------------------------------------------

//this function initiates texts found on the status bar
Text StatusBar::setText(const Font& font, const Vector2f& position, unsigned size, const Color& color)
{
	m_text.setFont(font);
	m_text.setCharacterSize(size);
	m_text.setFillColor(color);
	m_text.setPosition(position);
	m_text.setOrigin(-m_sprite.getGlobalBounds().width / 2 + m_text.getGlobalBounds().width / 2, 0);	
	return m_text;
}

//----------------------------------------------------------------------------

//this function sets status bar icons by giving them a rectangular shape
RectangleShape StatusBar::setRect(const Vector2f& size, const Texture& texture, const Vector2f& position)
{
	RectangleShape shape(size);
	shape.setTexture(&texture);
	shape.setPosition(position);
	shape.setOrigin(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2);
	
	return shape;
}

//----------------------------------------------------------------------------

float StatusBar::getTimer() const
{
	return m_timer;
}

//----------------------------------------------------------------------------

void StatusBar::draw()
{
	m_windowSpace.draw(m_statusBar);
	m_levelDisplay.setString(to_string((int)m_level + 1));
	m_windowSpace.draw(m_levelDisplay);
	
	m_windowSpace.draw(m_currPlayer);
	m_windowSpace.draw(m_playerName);
	

	if (m_timer == -1)//if theres no timer show elapsed time	
	{
		float dt = m_gameTime.restart().asSeconds();
		m_elapsedTime += dt;
		m_timerCounter.setString(to_string((int)m_elapsedTime));

		m_windowSpace.draw(m_timerCounter);
	}

	else//if theres no elapsed time show timer
	{
		float dt = m_gameTime.restart().asSeconds();	
		m_timer -= dt;	
		m_timerCounter.setString(to_string((int)m_timer));
		if (m_timer > 11)
			m_timerCounter.setColor(Color::White);
		else
			m_timerCounter.setColor(Color::Red);
			//set a warning for player to show him he has 10 
			//seconds left, by turning the timer red
		
		m_windowSpace.draw(m_timerCounter);
	}
}

//----------------------------------------------------------------------------

//set the features needed for each text or button on the status bar
void StatusBar::loadStatusBar(float icon, const LoadResources& m_resource)
{
	const float middleHeight = (float)m_windowSpace.getSize().y / 2;
	const float middleWidth = (float)m_windowSpace.getSize().x / 2;

	m_statusBar = setRect({ 1920, HEIGHT }, m_resource.getStatusBarTxr(), { middleWidth, middleHeight });

	m_levelDisplay = setText(m_resource.getFont(), { -750, middleHeight - 60 }, TEXT_SIZE, Color::Yellow);

	m_timerCounter = setText(m_resource.getFont(), { 60 , middleHeight - 60 }, TEXT_SIZE, Color::White);
}

//----------------------------------------------------------------------------
//set features needed for the current player controlled by the user
void StatusBar::loadCurrPlayer(const Texture &txr, const Font &font, const string &name)
{ 
	m_currPlayer = setRect({ 84, 100 }, txr, {615, 90});
	m_playerName = setText(font, { -383, 20 }, TEXT_SIZE - 60, Color::Black);
	m_playerName.setString(name);
}

//----------------------------------------------------------------------------
//set features needed for the status of the key, if thief has it or not
void StatusBar::updateKeyStatus(const Texture& txr)
{
	m_keyStatus = setRect({ 50, 70 },txr, { 1500, 80 });
	m_windowSpace.draw(m_keyStatus);
}