#pragma once

//-------------------------------include section------------------------------

#include "Orc.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Orc::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Orc::collision(King& king)
{
	king.collision(*this);
}

//----------------------------------------------------------------------------

void Orc::collision(Mage& mage)
{
	mage.collision(*this);
}

//----------------------------------------------------------------------------

void Orc::collision(Warrior& warrior)
{
	m_isRemoved = true;
}

//----------------------------------------------------------------------------

void Orc::collision(Thief& thief)
{
	thief.collision(*this);
}

//----------------------------------------------------------------------------

void Orc::collision(Gnome& gnome)
{
	gnome.collision(*this);
}