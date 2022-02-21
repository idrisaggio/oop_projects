#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include "Macros.h"
#include "Figure.h"

//---------------------------------using section------------------------------

namespace fs = std::filesystem;

//---------------------------------class section------------------------------

class Board
{
public:
	
	Board();
	Board(int, int, sf::Texture* []);

	void readExistingBoard(std::ifstream&, sf::Texture* []);
	void setNewBoard(int, int, sf::Texture* []);
	FigureType charToType(char) const;
	char typeToChar(FigureType) const;
	void draw(sf::RenderWindow&) const;
	void setFigure(FigureType, const sf::Vector2f&, sf::Texture* []);
	void save() const;

	int getHeight() const;
	int getWidth() const;


private:
	int m_height = 0;
	int m_width = 0;
	
	std::vector<std::vector<Figure>> m_mapObjects;
};