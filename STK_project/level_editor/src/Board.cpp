#pragma once

//--------------------------------include section-----------------------------

#include "Board.h"

//---------------------------------func section------------------------------

//default contrusctor
Board::Board() :
	m_height(0), m_width(0) {}

//----------------------------------------------------------------------------

Board::Board(int height, int width, sf::Texture* txrArray[]) 
{
	setNewBoard(height, width, txrArray);
}

//----------------------------------------------------------------------------

//this func reads from board after the user saved one in the board.txt file
void Board::readExistingBoard(std::ifstream& boardDesc, sf::Texture* txrArray[]) 
{
	std::vector<std::vector<Figure>> existingBoard;
	FigureType currType;
	char object;
	boardDesc >> m_height >> m_width;
	boardDesc.get();
	
	object = boardDesc.get();
	for (int y = 0; !boardDesc.eof(); y++)
	{
		std::vector<Figure> tempRow;
		for (int x = 0; object != '\n' && !boardDesc.eof(); x++) 
		{
			currType = charToType(object);
			
			tempRow.push_back(Figure(currType, txrArray[currType],
				sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE + BOARD_SIZE)));
			object = boardDesc.get();
		}
		
		existingBoard.push_back(tempRow);
		object = boardDesc.get();
	}
	
	m_mapObjects = existingBoard;
	m_height = int(m_mapObjects.size());
	m_width = int((m_height > 0 ? m_mapObjects[0].size() : 0));
}

//----------------------------------------------------------------------------

//this func makes a new board when the user clicks on the clear button
//it reads the height and the width of the new board and creates it
void Board::setNewBoard(int height, int width, sf::Texture* txrArray[]) 
{
	m_height = height;
	m_width = width;
	std::vector<std::vector<Figure>> newBoard;
	
	for (int y = 0; y <= m_height; y++)  
	{
		std::vector<Figure> tempRow;
		//creating a line of objects
		for (int x = 0; x <= m_width; x++)   
		{
			tempRow.push_back(Figure(FigureType::Empty, txrArray[FigureType::Empty], 
				sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE + BOARD_SIZE)));
		}
		newBoard.push_back(tempRow);
	}
	m_mapObjects = newBoard;
}

//----------------------------------------------------------------------------

//this func converts a character to a FigureType
FigureType Board::charToType(char currChar) const
{
	switch (currChar) 
	{
	case KING:
		return FigureType::King;
	case MAGE:
		return FigureType::Mage;
	case WARRIOR:
		return FigureType::Warrior;
	case THIEF:
		return FigureType::Thief;
	case EMPTY:
		return FigureType::Empty;
	case WALL:
		return FigureType::Wall;
	case GATE:
		return FigureType::Gate;
	case FIRE:
		return FigureType::Fire;
	case ORC:
		return FigureType::Orc;
	case KEY:
		return FigureType::Key;
	case PORTAL:
		return FigureType::Portal;
	case THRONE:
		return FigureType::Throne;
	default: 
		break;
	}
}

//----------------------------------------------------------------------------

//this func converts a FigureType to a Character
char Board::typeToChar(FigureType currType) const
{
	switch (currType) 
	{
	case FigureType::King:
		return KING;
	case FigureType::Mage:
		return MAGE;
	case FigureType::Warrior:
		return WARRIOR;
	case FigureType::Thief:
		return THIEF;
	case FigureType::Empty:
		return EMPTY;
	case FigureType::Wall:
		return WALL;
	case FigureType::Gate:
		return GATE;
	case FigureType::Fire:
		return FIRE;
	case FigureType::Orc:
		return ORC;
	case FigureType::Key:
		return KEY;
	case FigureType::Portal:
		return PORTAL;
	case FigureType::Throne:
		return THRONE;
	default: 
		return NULL;
	}
}

//----------------------------------------------------------------------------

void Board::draw(sf::RenderWindow& window) const
{
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			m_mapObjects[row][col].draw(window);
}

//----------------------------------------------------------------------------

void Board::setFigure(FigureType type, const sf::Vector2f& location, sf::Texture* txrArray[]) 
{

	int newCol = int(location.x) / TILE_SIZE; 
	int newRow = int(location.y - BOARD_SIZE) / TILE_SIZE;
	int xPos = (int(location.x) / TILE_SIZE) * TILE_SIZE; 
	int yPos = ((int(location.y) - BOARD_SIZE) / TILE_SIZE) * TILE_SIZE + BOARD_SIZE;

	if (type == FigureType::King || type == FigureType::Mage 
		|| type == FigureType::Warrior || type == FigureType::Thief
		|| type == FigureType::Throne)
	{
		for (int row = 0; row < m_height; row++) 
		{
			for (int col = 0; col < m_width; col++) 
			{
				if (m_mapObjects[row][col].getType() == type) 
				{
					m_mapObjects[row][col] = Figure(FigureType::Empty, txrArray[FigureType::Empty],
						sf::Vector2f(col * TILE_SIZE + BOARD_SIZE, row * TILE_SIZE));
					break;
				}
			}
		}
	}

	if (newRow < m_height && newCol < m_width)
		m_mapObjects[newRow][newCol] = Figure(type, txrArray[type], sf::Vector2f(xPos, yPos));
}

//----------------------------------------------------------------------------

int Board::getHeight() const
{
	return m_height;
}

//----------------------------------------------------------------------------

int Board::getWidth() const
{
	return m_width;
}

//----------------------------------------------------------------------------

void Board::save() const 
{
	
	fs::path outPath = "C:Board.txt";
	std::ofstream out(fs::absolute(outPath));
	
	out << m_height << " " << m_width << std::endl;

	for (int row = 0; row < m_height; row++) 
	{
		for (int col = 0; col < m_width; col++) 
		{
			out.put(typeToChar(m_mapObjects[row][col].getType()));
		}
		if (row != m_height - 1)
			out.put('\n');
	}
	out.close();
}