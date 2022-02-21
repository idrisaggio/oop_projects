#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include "conio.h"
#include "io.h"
#include "Coord.h"
#include "Macros.h"
#include "Board.h"

//---------------------------------class section------------------------------

class Thief 
{
public:
	
	// thief's c-tors
	Thief() : m_coord() {}
	Thief(const Coord& coord) : m_coord(coord) {}
	
	void key();
	bool checkHasKey()const;
	void setCoord(Coord);
	Coord getCoord()const;
	Coord controlThief(const Board&, bool&, bool&);

private:
	bool checkObject(char obj) const;
	
	bool m_hasKey = false;	// indicates if thief has a key

	Coord m_coord;
};