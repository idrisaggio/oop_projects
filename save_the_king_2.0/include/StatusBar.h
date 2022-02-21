#pragma once

//-------------------------------include section------------------------------

#include "Board.h"

//--------------------------------using section-------------------------------

using std::to_string;
using sf::Text;
using sf::Font;

//--------------------------------class section-------------------------------

class StatusBar : public Board
{
public:
	// Building Board for data tools
	using Board::Board;

	~StatusBar() {};
	// Get the icon image from LoadResources Class
	void loadStatusBar(float, const LoadResources&);

	// Get current time of the game
	float getTimer() const;

	// Update the Level of game
	void updateLevel();

	// Update Clock for the game
	void updateTimer(float);

	// Draw all Data about the game
	void draw();

	void loadCurrPlayer(const Texture&, const Font&, const string&);

	void updateKeyStatus(const Texture&);

private:
	// Set Icons and Get Icons Images 
	RectangleShape setRect(const Vector2f&, const Texture&, const Vector2f&);

	// Set Text for icon of databar
	Text setText(const Font&, const Vector2f&, unsigned, const Color&);

	float m_timer = 0; // the timer for the game 
	float m_elapsedTime = 0;
	int m_level = 0; // the current Level Game

	sf::Clock m_gameTime; // To set timer for the Game

	// Icons and Text for time.
	Text m_timerCounter;

	RectangleShape m_statusBar;

	RectangleShape m_currPlayer;
	Text m_playerName;

	RectangleShape m_keyStatus;

	// Icons and Text for Level.
	Text m_levelDisplay;

	Text m_text; // set a text
};