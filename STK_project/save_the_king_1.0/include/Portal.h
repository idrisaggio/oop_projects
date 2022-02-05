#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include "conio.h"
#include "io.h"
#include "Coord.h"
#include "Macros.h"
#include "Board.h"

//---------------------------------class section------------------------------

class Portal
{
public:
	Portal() : m_coord() {}
	Portal(const Coord& coord) : m_coord(coord) {}
	Coord getCoord()const;

private:
	Coord m_coord;
};