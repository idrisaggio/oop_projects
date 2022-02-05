#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include "Macros.h"
#include "Coord.h"

//---------------------------------using section------------------------------

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

//---------------------------------class section------------------------------

class Board
{
public:
	
	Board() : m_size(0) {}	// default c-tor
	Board(ifstream&);
	Board(const Board&);

	void setChar(const Coord&, char);
	string getRow(int) const;
	char getChar(const Coord&) const;
	int getSize() const;
	void print() const;

private:

	int m_size;

	vector <string> m_map;
};