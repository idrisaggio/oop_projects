#pragma once

//--------------------------------include section-----------------------------

#include "Controller.h"

//----------------------------------func section------------------------------

Controller::Controller() 
{
	openBoardStream();
}

//----------------------------------------------------------------------------

// this func is the initialiser of the game.
// it calls to build the maps, locate the objects and start each level
// it will exit when the user wishes for that (by entering the ESC key)
void Controller::start()
{
	while (true)
	{
		if (m_exitProgram)
		{
			cout << "game exited..." << endl;
			break;
		}
		else if (m_level == LAST_LEVEL)
		{
			system("cls");

			cout << "WINNER WINNER, CHICKEN DINNER!!!" << endl;
			break;
		}
		
		m_level++;
		m_steps = 0;
		m_originalBoard = Board(m_boardStream);
		m_board = Board(m_originalBoard);
		locateObjects();
		runLevel();
	}
}

//----------------------------------------------------------------------------

// this func prints the UI to provide info and stats for the user
void Controller::UI() const
{
	cout << "The control character : " << m_pcTurn << endl;
	
	cout << "The sum of steps : " << m_steps << endl;
	
	cout << "Does the Thief has a key? : " ; 
	
	if (m_thief.checkHasKey())
		cout << "YES";
	else
		cout << "NO";	

	cout << endl << endl;
}

//----------------------------------------------------------------------------

// this func runs each level separately. it updates the board with each
// input the user enters. it will exit when the user wishes for that 
// (by entering the ESC key)
void Controller::runLevel()
{
	while (true)
	{
		if (m_exitProgram)
			break;

		system("cls");
		UI();
		m_board.print();

		if (m_originalBoard.getChar(m_king.getCoord()) == THRONE)
			break;

		switch (m_pcTurn)
		{
		case KING:
		{
			Coord oldKingCoord = m_king.getCoord();
			Coord currKingCoord = m_king.controlKing(m_board, m_currTurn, m_exitProgram);

			while (oldKingCoord == currKingCoord && m_currTurn && !m_exitProgram)
			{
				oldKingCoord = m_king.getCoord();
				currKingCoord = m_king.controlKing(m_board, m_currTurn, m_exitProgram);
				m_steps++;
			}
			if (m_currTurn)
				moveKing(oldKingCoord);
			else
				m_pcTurn = MAGE;
			m_currTurn = true;

			break;
		}
		case MAGE:
		{

			Coord oldMageCoord = m_mage.getCoord();
			Coord currMageCoord = m_mage.controlMage(m_board, m_currTurn, m_exitProgram);

			while (oldMageCoord == currMageCoord && m_currTurn && !m_exitProgram)
			{
				oldMageCoord = m_mage.getCoord();
				currMageCoord = m_mage.controlMage(m_board, m_currTurn, m_exitProgram);
				m_steps++;
			}
			if (m_currTurn)
				moveMage(oldMageCoord);
			else
				m_pcTurn = WARRIOR;
			m_currTurn = true;
			break;
		}
		case WARRIOR:
		{
			Coord oldWarriorCoord = m_warrior.getCoord();
			Coord currWarriorCoord = m_warrior.controlWarrior(m_board, m_currTurn, m_exitProgram);

			while (oldWarriorCoord == currWarriorCoord && m_currTurn && !m_exitProgram)
			{
				oldWarriorCoord = m_warrior.getCoord();
				currWarriorCoord = m_warrior.controlWarrior(m_board, m_currTurn, m_exitProgram);
				m_steps++;
			}
			if (m_currTurn)
				moveWarrior(oldWarriorCoord);
			else
				m_pcTurn = THIEF;
			m_currTurn = true;
			break;
		}
		case THIEF:
		{
			Coord oldThiefCoord = m_thief.getCoord();
			Coord currThiefCoord = m_thief.controlThief(m_board, m_currTurn, m_exitProgram);

			while (oldThiefCoord == currThiefCoord && m_currTurn && !m_exitProgram)
			{
				oldThiefCoord = m_thief.getCoord();
				currThiefCoord = m_thief.controlThief(m_board, m_currTurn, m_exitProgram);
				m_steps++;
			}
			if (m_currTurn)
				moveThief(oldThiefCoord);
			else
				m_pcTurn = KING;
			m_currTurn = true;
			break;
		}

		default:
			break;
		}
	}
}

//----------------------------------------------------------------------------

// this func locates each PC, saves its coordinates and creates the objects
// according to the PC
void Controller::locateObjects()
{
	int boardSize = m_originalBoard.getSize();
	char currPC;

	for (int row = 0; row < boardSize; row++) 
	{
		for (int col = 0; col < boardSize; col++) 
		{
			Coord currCoord(col, row);
			currPC = m_originalBoard.getChar(currCoord);
			if (currPC == KING)
				m_king = King(currCoord);
			
			if (currPC == MAGE)
				m_mage = Mage(currCoord);
			
			if (currPC == WARRIOR)
				m_warrior = Warrior(currCoord);
			
			if (currPC == THIEF)
				m_thief = Thief(currCoord);

			if (currPC == PORTAL)
					m_portalSystem.push_back(Portal(currCoord)); // create portal system	
		}
	}
}

//----------------------------------------------------------------------------

// this func is responible for the following:
// each tile the king passes, that tile will be filled with another character.
// and that is according to what the king can and can't iteract with.
void Controller::moveKing(const struct Coord oldKingCoord)
{
	Coord otherSide;
	m_board.setChar(m_king.getCoord(), KING);

	if (m_originalBoard.getChar(oldKingCoord) == PORTAL)
			m_board.setChar(oldKingCoord, PORTAL);
	else 
		m_board.setChar(oldKingCoord, EMPTY);

	if (m_board.getChar(oldKingCoord) == KEY)
	{
		m_board.setChar(oldKingCoord, KEY);
	}

	else if (m_originalBoard.getChar(m_king.getCoord()) == PORTAL)
	{
		
	    Coord pos = m_king.getCoord();
		teleportPC(otherSide, pos);

		m_board.setChar(m_king.getCoord(), PORTAL);
		m_king.setCoord(otherSide);
		m_originalBoard.setChar(otherSide, PORTAL);
		m_board.setChar(otherSide, KING);
	}
}

//----------------------------------------------------------------------------

// this func is responible for the following:
// each tile the mage passes, that tile will be filled with another character.
// and that is according to what the mage can and can't iteract with.
void Controller::moveMage(const struct Coord oldMageCoord)
{

	m_board.setChar(m_mage.getCoord(), MAGE);

	if (m_board.getChar(oldMageCoord) == MAGE ||
		m_board.getChar(oldMageCoord) == EMPTY)

		m_board.setChar(oldMageCoord, EMPTY);

	if (m_board.getChar(oldMageCoord) == FIRE)
		m_board.setChar(oldMageCoord, FIRE);

	else if (m_board.getChar(oldMageCoord) == KEY)
		m_board.setChar(oldMageCoord, KEY);
	else if (m_originalBoard.getChar(oldMageCoord) == PORTAL)
	{
		m_board.setChar(oldMageCoord, PORTAL);
		m_originalBoard.setChar(oldMageCoord, PORTAL);
	}
}

//----------------------------------------------------------------------------

// this func is responible for the following:
// each tile the warrior passes, that tile will be filled with another character.
// and that is according to what the warrior can and can't iteract with.
void Controller::moveWarrior(const struct Coord oldWarriorCoord)
{
	Coord otherSide;

	m_board.setChar(m_warrior.getCoord(), WARRIOR);

	if (m_originalBoard.getChar(oldWarriorCoord) == PORTAL)
		m_board.setChar(oldWarriorCoord, PORTAL);
	else
		m_board.setChar(oldWarriorCoord, EMPTY);

	if (m_originalBoard.getChar(oldWarriorCoord) == ORC)
	{
		m_originalBoard.setChar(oldWarriorCoord, KEY);
		m_board.setChar(oldWarriorCoord, KEY);
	}

	else if (m_originalBoard.getChar(oldWarriorCoord) == KEY)
	{
		m_board.setChar(oldWarriorCoord, KEY);
	}
	else if (m_originalBoard.getChar(m_warrior.getCoord()) == PORTAL)
	{

		Coord pos = m_warrior.getCoord();
		teleportPC(otherSide, pos);

		m_board.setChar(m_warrior.getCoord(), PORTAL);
		m_warrior.setCoord(otherSide);
		m_originalBoard.setChar(otherSide, PORTAL);
		m_board.setChar(otherSide, WARRIOR);
	}
}

//----------------------------------------------------------------------------

// this func is responible for the following:
// each tile the thief passes, that tile will be filled with another character.
// and that is according to what the thief can and can't iteract with.
void Controller::moveThief(const struct Coord oldThiefCoord)
{
	Coord otherSide;

	m_board.setChar(m_thief.getCoord(), THIEF);
	m_board.setChar(oldThiefCoord, m_originalBoard.getChar(oldThiefCoord));

	if (m_board.getChar(oldThiefCoord) != KEY && m_board.getChar(oldThiefCoord) != PORTAL)
		m_board.setChar(oldThiefCoord, EMPTY);

	if (m_originalBoard.getChar(oldThiefCoord) == PORTAL)
		m_board.setChar(oldThiefCoord, PORTAL);

	if (m_originalBoard.getChar(oldThiefCoord) == THIEF)
	{
		m_board.setChar(oldThiefCoord, EMPTY);
		m_originalBoard.setChar(oldThiefCoord, EMPTY);
	}

	else if (m_originalBoard.getChar(m_thief.getCoord()) == KEY)
	{
		if (!m_thief.checkHasKey())
		{
			m_thief.key();
			m_originalBoard.setChar(m_thief.getCoord(), EMPTY);
			m_board.setChar(oldThiefCoord, EMPTY);
		}
	}
	else if (m_originalBoard.getChar(m_thief.getCoord()) ==
		GATE && m_thief.checkHasKey())
	{
		m_thief.key();
		m_board.setChar(oldThiefCoord, EMPTY);
		m_originalBoard.setChar(m_thief.getCoord(), EMPTY);
	}
	else if (m_originalBoard.getChar(m_thief.getCoord()) == PORTAL)
	{

		Coord pos = m_thief.getCoord();
		teleportPC(otherSide, pos);

		m_board.setChar(m_thief.getCoord(), PORTAL);
		m_thief.setCoord(otherSide);
		m_originalBoard.setChar(otherSide, PORTAL);
		m_board.setChar(otherSide, THIEF);
	}
}

//----------------------------------------------------------------------------

// this func makes sure that the portals that the PC went through are
// compatable. it updates the compatable portal that it recieves
void Controller::teleportPC(Coord& otherSide, Coord m_pcCoord)
{
	for (int i = 0; i < m_portalSystem.size(); i++)
	{
		if (m_pcCoord == m_portalSystem[i].getCoord())
		{
			if (i % 2 == 0)
			{
				otherSide = m_portalSystem[i + 1].getCoord();
			}
			else
			{
				otherSide = m_portalSystem[i - 1].getCoord();
			}
		}
	}
}

//----------------------------------------------------------------------------

// this func opens the text file that contains the levels
void Controller::openBoardStream()
{
	m_boardStream.open("Board.txt");
	if (!m_boardStream.is_open())
	{
		cerr << "Cannot open the map file\n";
		exit(EXIT_FAILURE);
	}
}