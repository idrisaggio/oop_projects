#pragma once

//--------------------------------include section-----------------------------

#include "Board.h"

//----------------------------------func section------------------------------

// board c-tor. it recieves an input streamer by reference and reads data
// from the file
Board::Board(ifstream& boardStream) 
{
	boardStream >> m_size;
	boardStream.get();

	for (int row = 0; row <= m_size; row++) 
	{
		string tempRow;
		getline(boardStream, tempRow);
		m_map.push_back(tempRow);
	}
}

//----------------------------------------------------------------------------

// this func creates a copy of the original map.
Board::Board(const Board& boardCopy)
{
	m_size = boardCopy.getSize();
	for (int row = 0; row <= m_size; row++) 
		m_map.push_back(boardCopy.getRow(row));
}

//----------------------------------------------------------------------------

// this func prints a PC in a specific coordinates.
// it recieves the wanted coordinates and PC.
void Board::setChar(const Coord& coord, char pc)
{
	m_map[coord.m_row][coord.m_col] = pc;
}

//----------------------------------------------------------------------------

// this func returns a row in the map
string Board::getRow(int row) const
{
	return(m_map[row]);
}

//----------------------------------------------------------------------------

// this func returns the character in the coordinates that it recieves
char Board::getChar(const Coord& coord) const
{
	if (!coord.isValid(m_size))
		return WALL;
	
	return m_map[coord.m_row][coord.m_col];
}

//----------------------------------------------------------------------------

// this func returns the size of the map
int Board::getSize() const
{
	return m_size;
}

//----------------------------------------------------------------------------

// this func prints the map on the console
void Board::print() const
{
	for (int row = 0; row < m_size; row++)
		cout << m_map[row] << endl;
}