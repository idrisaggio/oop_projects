#pragma once

const int WINDOW_WIDTH = 1920,
WINDOW_HEIGHT = 1080,
NUM_OF_TYPES = 14,
TILE_SIZE = 52,
BOARD_SIZE = 181,
TEXT_SIZE = 5,
SETTINGS = 0,
PLAYABLE_CHARACTERS = 1,
OBJECTS = 2,
SPACE = 3,
BUTTON_HEIGHT = 60,
BUTTON_WIDTH = 104;

//-------------------------------------

enum FigureType
{
	King,	
	Mage,	
	Thief,	
	Warrior,
	Empty,	
	Wall,
	Fire,	
	Throne,	
	Orc,	
	Key,	
	Gate,
	Portal,
	Save,
	Clear

};

//-------------------------------------

enum ActionType
{	
	AddEmpty,
	AddWall,
	AddFire,
	AddThrone,
	AddOrc,
	AddKey,
	AddGate,
	AddPortal,
	AddKing,
	AddMage,
	AddThief,
	AddWarrior,
	SaveBoard,
	ClearBoard,	
	NoAction
};

//-------------------------------------

const char
	KING = 'K',
	MAGE = 'M',
	WARRIOR = 'W',
	THIEF = 'T',
	EMPTY = ' ',
	WALL = '=',
	GATE = '#',
	FIRE = '*',
	ORC = '!',
	KEY = 'F',
	PORTAL = 'X',
	THRONE = '@';

//-------------------------------------

const char FONT_PATH[30] = "C:/Windows/Fonts/ITCBLKAD.TTF";