#pragma once

//-------------------------------include section------------------------------

#include "Fire.h"
#include "Gnome.h"
#include "Mage.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Fire::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Fire::collision(King& king)
{
	king.collision(*this);
}

//----------------------------------------------------------------------------

void Fire::collision(Mage& mage)
{
	m_isRemoved = true;	
}

//----------------------------------------------------------------------------

void Fire::collision(Warrior& warrior)
{
	warrior.collision(*this);
}

//----------------------------------------------------------------------------

void Fire::collision(Thief& thief)
{
	thief.collision(*this);
}

//----------------------------------------------------------------------------

void Fire::collision(Gnome& gnome)
{
	gnome.collision(*this);
}