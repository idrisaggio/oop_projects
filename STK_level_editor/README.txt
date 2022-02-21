11/12/2021

Project guide (Level Editor)
==============================================================================
Authors: Raed Barhoum, Anton Nahhas

..................................


Introduction:
-------------

This project is a level editor program, for the video game "Save The King 1.0". 
The editor is able to create maps compatible with the game.
The editor will provide a panel to choose items from, and a board to insert
objects upon.

! IMPORTANT NOTE !:
-------------------

the levels created by this editor can be used fully in "Save The King 1.0".
they can be used in "Save The King 2.0" however some assets won't be able to be added
because they are missing in the level editor (e.g: gnomes, consumables)


++++++++++++++++++++++++


Design:
-------

Panel:
The provided panel will include every figure and object in the game, for the user to use.
It will be seperated into 3 categories: Players, Objects and settings.
each one will include the following:

	Players: King, Mage, Warrior, Thief

	Objects: Empty (tile), Wall, Orc, Key, Gate, Fire, Portal, Throne

	Settings: Save, Clear


Board:
In addition, there will be a board that contains tiles, in which the user can insert
figures into them. 
If a board already exists, the program will the read the map's
height and width, then it will ready the map itself and draw it on the window.
If the file (board) doesn't exist, it will create a new empty board full of spaces.
If the user wants to save a board, it will be possible to achieve by pressing
the save button (represented as a floppy disc) 
If the users wants a clear board, it will be posible to achieve by pressing 
the the clear button  (represented as a red "X") 
The user will have all the figures that exist in the game.

these are figures, and how they will be saved as characters (sign):

	Key (signed ‘F’)
	Throne (signed ‘@’)
	Portal (signed ‘X’)
	Wall (signed ‘=’)
	Orc (signed ‘!’)
	Gate (signed ‘#’)
	Fire (signed ‘*’)
	King (signed ‘*’)
	Mage (signed ‘*’)
	Warrior (signed ‘*’)
	Thief (signed ‘*’)


++++++++++++++++++++++++


Program's Files:
----------------

Board.h/.cpp:
The class Board is responsible for presenting the maps of the game on the Window. and saving maps created by the user.

Editor.h/.cpp:
The class Editor is responsible for monitoring and controlling everything thing that’s happening during the program

Figure.h/.cpp:
The class Figure is responsible for setting the textures of the sprites and assigning them to
their suitable buttons.

Panel.h/.cpp:
The class Panel is responsible for creating and setting the panel on the windows

Macros.h:
this file has all the constants and enums that are needed for the game

FigureButton.h/.cpp:
the class FigureButtons is responsible for creating the buttons of the figures on the window.
each button will have a unique sprite drawn upon it to indicate its functionality

main.cpp:
The main function’s only function is just to start the Editor and initialize the program.

Text.h/.cpp:
The class text is responsible for writing texts on the window


++++++++++++++++++++++++


data structures:
----------------

We used the data stucture Vector, to store rows of the maps in the editor.
In addition we used them to set positions of many items of the window


++++++++++++++++++++++++


Algorithms worth mentioning:
----------------------------

N/A.


++++++++++++++++++++++++


known bugs:
-----------

no bugs where noticed during the program process.

 
++++++++++++++++++++++++


other Notes:
------------	

This project introduced me to the libraries of SFML.
I understood thoroughly how to utilize SFML and any graphically represented programs work.


++++++++++++++++++++++++

