#pragma once

//--------------------------------include section-----------------------------

#include "Thief.h"

//---------------------------------func section-------------------------------

// this func returns the current coordinates of the thief
Coord Thief::getCoord()const
{
	return m_coord;
}

//----------------------------------------------------------------------------

// this func changes the position of the thief
void Thief::setCoord(Coord newCoord)
{
	m_coord = newCoord;
}

//----------------------------------------------------------------------------

// this func controls the movements of the Thief, by pressing the arrow keys.
// it makes sure that the new coordinates are valid, according to map's size.
// it recieves the board, the 2 boolean variables by reference:
// one to indicate the end of a turn, by pressing the key 'p'.
// the second is to exit the program whenever the user presses the ESC key
Coord Thief::controlThief(const Board& board, bool &m_currTurn, bool& exitProgram)	
{
	int row = m_coord.m_row;
	int	col = m_coord.m_col;

	switch (_getch())
	{
	case KB_UP:
		if (checkObject(board.getChar(Coord(col, row - 1))))
		{
			m_coord.m_row = m_coord.m_row - 1;
		}
		return m_coord;
	case KB_DOWN:
		if (checkObject(board.getChar(Coord(col, row + 1))))
		{
			m_coord.m_row = m_coord.m_row + 1;

		}
		return m_coord;
	case KB_RIGHT:
		if (checkObject(board.getChar(Coord(col + 1, row))))
		{
			m_coord.m_col = m_coord.m_col + 1;
		}
		return m_coord;
	case KB_LEFT:
		if (checkObject(board.getChar(Coord(col - 1, row))))
		{
			m_coord.m_col = m_coord.m_col - 1;
		}
		return m_coord;
	case KB_SWITCH:
		m_currTurn = false;
		return m_coord;
	case KB_Escape:
		exitProgram = true;
		return m_coord;
	default:

		return m_coord;
	}
}

//----------------------------------------------------------------------------

//this func updates if the thief has a key or not
void Thief::key()
{
	if (checkHasKey())
		m_hasKey = false;
	else
		m_hasKey = true;
}

//----------------------------------------------------------------------------

// this function checks if the thief has a key
bool Thief::checkHasKey()const
{
	return (m_hasKey ? true : false);	
}

//----------------------------------------------------------------------------

// this func checks which object the thief has interacted with.
// it will return true if interaction is valid. otherwise it will return false
bool Thief::checkObject(char obj) const
{

	if (obj == PORTAL || obj == EMPTY || obj == KEY || (obj == GATE && m_hasKey))
		return true;
	return false;

}