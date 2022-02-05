#pragma once

//--------------------------------include section-----------------------------

#include "Mage.h"

//---------------------------------func section-------------------------------

// this func returns the current coordinates of the mage
Coord Mage::getCoord() const
{
	return m_coord;
}

//----------------------------------------------------------------------------

// this func controls the movements of the mage, by pressing the arrow keys.
// it makes sure that the new coordinates are valid, according to map's size.
// it recieves the board, the 2 boolean variables by reference:
// one to indicate the end of a turn, by pressing the key 'p'.
// the second is to exit the program whenever the user presses the ESC key
Coord Mage::controlMage(const Board& board, bool &m_currTurn, bool &exitProgram)
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

// this func checks which object the mage has interacted with.
// it will return true if interaction is valid. otherwise it will return false
bool Mage::checkObject(char obj)const
{
	if (obj == PORTAL || obj == KEY || obj == FIRE || obj == EMPTY)
	{
		return true;
	}
	return false;
}