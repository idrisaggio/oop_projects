#pragma once

//--------------------------------include section-----------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Portal.h"
#include "Board.h"
#include "Coord.h"
#include "Macros.h"

//---------------------------------using section------------------------------

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::cerr;

//---------------------------------class section------------------------------

class Controller
{

public:

	Controller();	// default c-tor
	void start();
	void UI()const;

private:

	void runLevel();
	void locateObjects();
	void moveKing(const struct Coord);
	void moveMage(const struct Coord);
	void moveWarrior(const struct Coord);
	void moveThief(const struct Coord);
	void teleportPC(Coord&, Coord);
	void openBoardStream();
	
	bool m_currTurn = true;			// indicates if it's the turn of a PC
	bool m_exitProgram = false;		// indicates if ESC key has been entered

	int m_steps = 0;				// counts how many steps the user made
	int m_level = 0;				// holds the number of current level
	char m_pcTurn = KING;			// holds which pc is playing currently
									// (starts with the king)

	ifstream m_boardStream;			// input streamer for the board
	Board m_originalBoard = Board();// holds the original board
	Board m_board = Board();		// holds the original board's copy

	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Thief m_thief;
	vector<Portal> m_portalSystem;	// portal system vector
};