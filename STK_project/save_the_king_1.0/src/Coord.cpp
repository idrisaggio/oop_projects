#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include "Coord.h"

//---------------------------------func section-------------------------------

// this is a placement new operator
Coord& Coord::operator=(const Coord& other) 
{
	if (&other != this) {
		m_col = other.m_col;
		m_row = other.m_row;
	}
	return *this;
}

//----------------------------------------------------------------------------

// this func checks if the coordinates are valid according to the board
// size that it recieves
bool Coord::isValid(int boardSize) const 
{
	return (m_col >= 0 && m_row >= 0
		&& m_col < boardSize && m_row < boardSize);
}

//----------------------------------------------------------------------------

// this operator checks if the 2 coordinates that it recieves are similar
bool operator==(const Coord& l, const Coord& r) {
	return (l.m_col == r.m_col && l.m_row == r.m_row);
}

//----------------------------------------------------------------------------

// this operator checks if the 2 coordinates that it recieves are different
bool operator!=(const Coord& l, const Coord& r) {
	return !(l == r);
}