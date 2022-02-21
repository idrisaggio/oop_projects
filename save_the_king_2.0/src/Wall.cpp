#pragma once

//-------------------------------include section------------------------------

#include "Wall.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Wall::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Wall::collision(King& king)
{
	king.collision(*this);
}

//----------------------------------------------------------------------------

void Wall::collision(Mage& mage)
{
	mage.collision(*this);
}

//----------------------------------------------------------------------------

void Wall::collision(Warrior& warrior)
{
	warrior.collision(*this);
}

//----------------------------------------------------------------------------

void Wall::collision(Thief& thief)
{
	thief.collision(*this);
}

//----------------------------------------------------------------------------

void Wall::collision(Gnome& gnome)
{
	gnome.collision(*this);
}