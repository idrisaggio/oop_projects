#pragma once

// board's file name
const std::string FILE_NAME = "board.txt";

// consumables types
const int INC = 0;
const int DEC = 1;
const int DIS = 2;

const int DEFAULT_CASE = -1;
const int NO_TIME_LIMIT = -1;

// dynamic objects' speeds
const float PC_SPEED = 185.f;
const float GNOME_SPEED = 185.f;

// sizes
const unsigned BUTTON_SIZE = 100;
const unsigned HEIGHT = 170;
const int CONSUMABLE_SIZE = 40;
const int QUIT_BUTTON_SIZE = 25;
const int MARGE = 45;
const float CELL = 60; 
const int TEXT_SIZE = 75;
const unsigned int FONT_SIZE = 24;

const size_t NUM_OF_TEXTURES = 21;
const size_t NUM_OF_SOUNDS = 10;

//----------------------------------------------------------------------------

const std::string LEVEL_PASSED_MSG = "CONGRATS! LEVEL PASSED!";
const std::string LEVEL_START = "GET READY! LEVEL STARTS IN";

//----------------------------------------------------------------------------

enum ObjectType_t 
{
	O_KING = 'K',
	O_MAGE = 'M',
	O_WARRIOR = 'W',
	O_THIEF = 'T',
	O_GNOME = '^',
	O_EMPTY = ' ',
	O_WALL = '=',
	O_GATE = '#',
	O_FIRE = '*',
	O_ORC = '!',
	O_KEY = 'F',
	O_PORTAL = 'X',
	O_THRONE = '@',
	O_CONSUMABLE = '+'
};

//----------------------------------------------------------------------------

enum Texture_t 
{
	T_KING,
	T_MAGE,
	T_WARRIOR,
	T_THIEF,
	T_GNOME,
	T_TILE,
	T_WALL,
	T_GATE,
	T_FIRE,
	T_ORC,
	T_KEY,
	T_PORTAL,
	T_THRONE,
	T_CONSUMABLE,
	T_BUTTON,
	T_MENU_BACKGROUND,
	T_HELP_BACKGROUND,
	T_STATUS_BAR,
	T_NO_KEY,
	T_END_BACKGROUND,
	T_QUIT
};

//----------------------------------------------------------------------------

enum Sounds_t
{
	S_ORC_KILLED,
	S_KEY_TAKEN,
	S_GATE_OPENED,
	S_FIRE_EXTINGUISHED,
	S_PORTAL_ENTERDED,
	S_INC_TIME,
	S_DEC_TIME,
	S_DIS_GNOMES,
	S_LEVEL_PASSED,
	S_TIMES_UP
};