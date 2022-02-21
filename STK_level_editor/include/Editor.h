#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include "Macros.h"
#include "Board.h"
#include "Panel.h"

//---------------------------------using section------------------------------

namespace fs = std::filesystem;

//---------------------------------class section------------------------------

class Editor {
public:
	Editor();
	void run();

private:
	void handleClick(const sf::Vector2f&);
	void initBoard();
	void initTxrArray();

	sf::RenderWindow m_window;
	Board m_board;
	Panel m_panel;
	ActionType m_clickMode = ActionType::NoAction;
	sf::Texture* m_txrArray[NUM_OF_TYPES];
};