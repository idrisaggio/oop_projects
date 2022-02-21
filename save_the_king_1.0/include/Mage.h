#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include "conio.h"
#include "io.h"
#include "Coord.h"
#include "Macros.h"
#include "Board.h"

//---------------------------------class section------------------------------

class Mage
{
public:
	Mage() : m_coord() {}	// default c-tor
	Mage(const Coord& coord) : m_coord(coord) {}

	Coord getCoord()const;
	Coord controlMage(const Board&, bool&, bool&);

private:
	bool checkObject(char obj)const;

	Coord m_coord;
};