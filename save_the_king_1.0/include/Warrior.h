#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include "conio.h"
#include "io.h"
#include "Coord.h"
#include "Macros.h"
#include "Board.h"

//---------------------------------class section------------------------------

class Warrior 
{
public:
	Warrior() : m_coord() {}	// default c-tor
	Warrior(const Coord& coord) : m_coord(coord) {}

	Coord getCoord() const;
	void setCoord(Coord);
	Coord controlWarrior(const Board&, bool&, bool&);

private:
	bool checkObject(char obj)const;

	Coord m_coord;
};