16/01/2022

Final project guide (Save The King 2.0)
==============================================================================
Authors: Raed Barhoum, Anton Nahhas

..................................


Introduction:
------------

This project is a graphical video game puzzle, built using the SFML graphic library. 
The game has 4 interchangeable PCs (playable characters): King, Mage, Warrior and Thief.
Each character has special abilities that others don't have.
the objective of this video game is to reach the goal, which is reaching the throne by the king.
If so, the level will be passed the next level will load. Otherwise the level will be reset
until passed by the user


++++++++++++++++++++++++


Design:
-------

The game is built with 3 unique levels (more levels can be added). Each level has different challenges.
Each level will be loaded from the file "board.txt" which contains them.
Above each level, there is a line of configurations: height, width and time.
When the time is -1 that means there is no timer and the time will be represented as elapsed time of the game.

These the levels consist of different types of object, which are static objects and dynamic objects

Static objects:
--------------
Items:
	Key (signed 'F'): drops by killing an Orc and used to open gates only by the thief. 
			  All PCs can pass through it.
	Throne (signed '@'): represents the goal that must be reached by the king to finish a level.
	Portal (signed 'X'): can be used by all PCs (except the Mage) to teleport back and forth through it.
			     Each teleportation system has 2 unique end (two portals ‘X’).
			     The Mage can only pass a portal but not use it.
	Consumables (signed '+'): scattered accros the levels, they represent good and bad gifts.
		 		  they are generated randomly and their content is mysterious to the user.
				  they are: time increasing gift (+10 sec), time decreasing gift(-10 sec)
				  and gnomes disposal gift (removes the gnomes off of the level)

Obstacles:
	Wall (signed '='):  a blockade that no PC can interact with.
	Orc (signed '!'): a mob that blocks most PCs. When killed drops a key.
	Gate (signed '#'): a blockade that only can be passed by opening it with a key.
	Fire (signed '*'): a blockade that no PC can interact with, but the Mage. 
			   The Mage can extinguish the fire to make way for other PCs.

Dynamic objects:
---------------

As said, the user will have 4 different PCs to utilize and win the game, in which each one has unique abilities. 
The game demands using each PC to finish a level. The PCs are interchangeable (using the Keyboard key ‘p’). 
These PCs are:

King (signed 'K'): The object of the game is to bring the king to the throne. 
                   The king can walk on empty tiles, on tiles that have a key 
      		   (but does not take it) and enter a portal to pass with its help.

Mage (signed 'M'): The Mage’s special ability is to put out a fire.
    		   The Mage can walk on empty tiles, on fire tiles (extinguishes it immediately and the tile becomes an empty tile),
     		   tiles that have a key (but does not take it) and can stand on a teleport cell (but not pass with his help).

Warrior (signed 'W'): The warrior's special ability is to kill the orcs.
         	      The warrior can walk on empty tiles and those that have orcs (so the player makes him kill them).
         	      He can also enter a portal and teleport, can stand on tiles that have a key (But does not take it.)
        	      When the warrior kills the orc, a key drops from it.

Thief (signed 'T'): The thief's special ability is to take a key that appears on the board when the warrior kills an orc 
       		    (and opens a gate with it. One key for one gate, without any uniqueness) that is, 
                    each key opens each gate (the next gate will need another key. The thief can carry only one key at once.) 
                    When key is taken it turns the gate tile into an empty tile.

NPCs:

Gnome (signed '^'): The gnomes will be an obsticle. when the players colide with a gnome, they will be
		    blocked by it. Therefore the user will need to change directions find a way around
		    The gnomes are not hostile to the players


++++++++++++++++++++++++


Program's Files:
----------------

Board.h/.cpp:
The class Board is responsible for presenting the maps of the game on the game window. This class streams the sizes of the maps and the maps themselves.

Consumable.h/.cpp:
This class is the base class for all consumable types in the game

Controller.h/.cpp:
The class Controller is responsible for monitoring and controlling everything that’s happening during the game (PCs’ movement, interactions etc.)

DecreaseTime.h/.cpp:
The class DecreaseTime is responsible for the bad gift of decreasing time of the timer

DynamicObject.h/.cpp:
This class is the base class for all dynamic objects in the game

Fire.h/.cpp:
The class of Fire represents fires
Through it we can get all the information we need about the object (position, collisions, etc.) 

GameObject.h/.cpp:
This class is the base class for all objects in the game

Gate.h/.cpp:
The class of Gate represents gates
Through it we can get all the information we need about the object (position, collisions, etc.) 

Gnome.h/.cpp:
The class of Gnome represents gnomes
Through it we can get all the information we need about the object (position, collisions, etc.) 

IncreaseTime.h/.cpp:
The class of IncreaseTime is responsible for the good gift of increasing time of the timer

Key.h/.cpp:
The class of Key represents keys
Through it we can get all the information we need about the object (position, collisions, etc.) 

King.h/.cpp:
The class of King represent the PC King.
Through it we can get all the information we need about the object (position, collisions, etc.) 

LoadResources.h/.cpp:
The class of Key is responsible to load all the resources needed to the run the game

Macros.h:
this file has all the constants and enums that are needed for the game

Mage.h/.cpp:
The class of Mage represent the PC Mage.
Through it we can get all the information we need about the object (coordinates, which tile it’s trying to interact with, etc.) 

main.cpp:
The main function’s only function is just to load the resources and call the controller to initialize the game.

Menu.h/.cpp:
This class is responsible to assemble the main menu of the game

MenuButton.h/.cpp:
This class creates the buttons needed in the menu

Orc.h/.cpp:
The class of Orc represents orcs
Through it we can get all the information we need about the object (position, collisions, etc.) 

Player.h/.cpp:
This class is the base class for all playable characters in the game

Portal.h/.cpp:
The class Portal represents the portal system.
Through it we can get all the information we need about the object (position, collisions, etc.)

StaticObject.h/.cpp:
This class is the base class for all static objects in the game

StatusBar.h/.cpp:
This class is responsible for assembling and displaying the status bar ingame.
It displays: current level, current player, current timer (or elapsed time), if thief has key and the exit button

Thief.h/.cpp:
The class of Thief represent the PC Thief.
Through it we can get all the information we need about the object (position, collisions, etc.)

Throne.h/.cpp:
The class of Throne represents the throne
Through it we can get all the information we need about the object (position, collisions, etc.)

Wall.h/.cpp:
The class of Wall represents the wall
Through it we can get all the information we need about the object (position, collisions, etc.)

Warrior.h/.cpp:
The class of Warrior represent the PC Warrior.
Through it we can get all the information we need about the object (position, collisions, etc.)

resources folder:
includes all the files (textures, sounds, music and board.txt) which are needed to run the game

++++++++++++++++++++++++


data structures:
---------------

vector<Texture> m_menuTxr: 
holds the menu textures

vector<unique_ptr<Player>> m_player: 
holds all the playable characters

vector<unique_ptr<Gnome>> m_gnome: 
holds all the gnomes

vector<unique_ptr<StaticObject>> m_staticObject: 
holds all static objects

vector<unique_ptr<Portal>> m_portalSystem: 
holds all portals. it represents a portal system and to easly know each portal's other end

vector<string> m_map: 
holds each level until passed

vector<Texture> m_textures:
holds all textures loaded into the project

vector<SoundBuffer> m_sounds:
holds all sound buffers loaded into the project


++++++++++++++++++++++++


Algorithms worth mentioning:
---------------------------

gnomes' movment: they move in random direction by using the rand() function


++++++++++++++++++++++++


known bugs:
----------

most of the sound effects added into the game do not play is specific places.
we have checked the correctness of the files and that they are loaded correctly.
we tried to play them in other places and they do play, however not in the intended places.
these sound are: S_ORC_KILLED, S_KEY_TAKEN, S_GATE_OPENED, S_FIRE_EXTINGUISHED,
	         S_PORTAL_ENTERDED, S_INC_TIME, S_DEC_TIME, S_DIS_GNOMES.
 

++++++++++++++++++++++++


Other Notes:
-----------
	
This project was the realization of the previous Save The King project into a real video game.
differently to the last version, we learned much more things in quantity.
we implemented many things and many ideas and we understood how things flow while the code runs.
we also discovered many things about the SFML library
all in all we had a lot fun and laughs while working at the project, and we hope that we have 
done the tasks as intended.


++++++++++++++++++++++++

