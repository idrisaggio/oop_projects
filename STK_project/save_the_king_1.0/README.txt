11/11/2021

Project guide (Save The King 1.0)
==============================================================================
Authors: Raed Barhoum, Anton Nahhas

..................................


Introduction:
-------------
This project is a program simulating a video game. 
The game has 4 interchangeable PCs (playable characters): King, Mage, Warrior and Thief.
Each character has special abilities that others don't have.
the objective of this video game is to reach the goal, which is reaching the throne by the king.


++++++++++++++++++++++++


Design:
-------

The game is built with 3 unique levels that are N*N by scale. Each level has different challenges.
These challenges are designed by tiles which consist of items and obstacles:
A non-obstacle/item tile is the empty tile (signed ‘ ‘), which all PCs can pass through.

Items:
	Key (signed ‘F’): drops by killing an Orc and used to open gates only by the thief. 
			  All PCs can pass through it.
	Throne (signed ‘@’): represents the goal that must be reached by the king to finish a level.
	Portal (signed ‘X’): can be used by all PCs (except the Mage) to teleport back and forth through it.
			     Each teleportation system has 2 unique end (two portals ‘X’).
			     The Mage can only pass a portal but not use it.

Obstacles:
	Wall (signed ‘=’):  a blockade that no PC can interact with.
	Orc (signed ‘!’): a mob that blocks most PCs. When killed drops a key.
	Gate (signed ‘#’): a blockade that only can be passed by opening it with a key.
	Fire (signed ‘*’): a blockade that no PC can interact with, but the Mage. 
			   The Mage can extinguish the fire to make way for other PCs.

As said, the user will have 4 different PCs to utilize and win the game, in which each one has unique abilities. 
The game demands using each PC to finish a level. The PCs are interchangeable (using the Keyboard key ‘p’). 
These PCs are:

King: The object of the game is to bring the king to the throne. 
      The king can walk on empty tiles, on tiles that have a key 
      (but does not take it) and enter a portal to pass with its help.

Mage: The Mage’s special ability is to put out a fire.
      The Mage can walk on empty tiles, on fire tiles (extinguishes it immediately and the tile becomes an empty tile),
      tiles that have a key (but does not take it) and can stand on a teleport cell (but not pass with his help).

Warrior: The warrior's special ability is to kill the orcs.
         The warrior can walk on empty tiles and those that have orcs (so the player makes him kill them).
         He can also enter a portal and teleport, can stand on tiles that have a key (But does not take it.)
         When the warrior kills the orc, a key drops from it.

Thief: The thief's special ability is to take a key that appears on the board when the warrior kills an orc 
       (and opens a gate with it. One key for one gate, without any uniqueness) that is, 
       each key opens each gate (the next gate will need another key. The thief can carry only one key at once.) 
       When key is taken it turns the gate tile into an empty tile.


++++++++++++++++++++++++


Program's Files:
----------------

Board.h/.cpp:
The class Board is responsible for presenting the maps of the game on the Console. This class streams the sizes of the maps and the maps themselves.

Board.txt:
This file includes the maps and their sizes.

Controller.h/.cpp:
The class Controller is responsible for monitoring and controlling everything thing that’s happening during the game (PCs’ movement, interactions etc.) 

Coord.h/.cpp:
The coordinates struct (vertices), is a struct that indicates a point on the map. It helps to locates objects.
We included a couple of “coordinates comparing” operators for the ease of coding.

io.h/.cpp:
given file.

King.h/.cpp:
The class of King represent the PC King.
Through it we can get all the information we need about the object (coordinates, which tile it’s trying to interact with, etc.) 

Location.h:
The coordinates struct (vertices), is a struct that indicates a point on the map.
It helps to locates objects. We included a couple of “coordinates comparing” operators for the ease of coding.

Macros.h:
this file has all the constants that are needed for the game

Mage.h/.cpp:
The class of Mage represent the PC Mage.
Through it we can get all the information we need about the object (coordinates, which tile it’s trying to interact with, etc.) 

main.cpp:
The main function’s only function is just to call the Ccontroller and initialize the game.

Portal.h/.cpp:
The class Portal represents the portal system.
Through it we can get all the information we need about the object (coordinates, which portals are connected, etc.)

Thief.h/.cpp:
The class of Thief represent the PC Thief.
Through it we can get all the information we need about the object (coordinates, which tile it’s trying to interact with, etc.) 

Warrior.h/.cpp:
The class of Warrior represent the PC Warrior.
Through it we can get all the information we need about the object (coordinates, which tile it’s trying to interact with, etc.) 


++++++++++++++++++++++++


data structures:
----------------

We created a vector to help us build a portal system.
we make sure after two portals found, those portals are now partners,
meaning if you go through one of them, the PCs only get out of the other side and vice versa.
we do this by adding them into the "portal system" vector. this way each and every 2 portals are unique to each other.


++++++++++++++++++++++++


Algorithms worth mentioning:
----------------------------

N/A.


++++++++++++++++++++++++


known bugs:
-----------

no bugs where noticed during the program process.

 
++++++++++++++++++++++++


Other Notes:
------------
	
This project was complicated but very intriguing. It gave me more insight on how objects
actually work than the first exercise. I had a lot fun and laughs while working at, however
it gave me as much trouble. I tried to make the project more generic but
the set of skills that I have right now didn't make me realize that, and that's resulted in
a duplicated code. Either way, I think the project works perfectly.


++++++++++++++++++++++++

