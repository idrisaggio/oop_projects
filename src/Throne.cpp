#pragma once

//-------------------------------include section------------------------------

#include "Throne.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Throne::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Throne::collision(King& king)
{
	king.collision(*this);
}

//----------------------------------------------------------------------------

void Throne::collision(Mage& mage)
{
	mage.collision(*this);
}

//----------------------------------------------------------------------------

void Throne::collision(Warrior& warrior)
{
	warrior.collision(*this);
}

//----------------------------------------------------------------------------

void Throne::collision(Thief& thief)
{
	thief.collision(*this);
}

//----------------------------------------------------------------------------

void Throne::collision(Gnome& gnome)
{
	gnome.collision(*this);
}