#pragma once

//--------------------------------include section-----------------------------

#include <iosfwd>

//------------------------ --------struct section-----------------------------

struct Coord
{
	Coord() : m_col(0), m_row(0) {} // default c-tor
	Coord(int c, int r) : m_col(c), m_row(r) {}

	int m_col;
	int	m_row;

	Coord& operator=(const Coord& other);

	bool isValid(int) const;
};

bool operator==(const Coord& l, const Coord& r);

bool operator!=(const Coord& l, const Coord& r);