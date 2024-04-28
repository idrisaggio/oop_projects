#pragma once

//-------------------------------include section------------------------------

#include "Gate.h"
#include "King.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Gate::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Gate::collision(King& king)
{
	king.collision(*this);
}

//----------------------------------------------------------------------------

void Gate::collision(Mage& mage)
{
	mage.collision(*this);
}

//----------------------------------------------------------------------------

void Gate::collision(Warrior& warrior)
{
	warrior.collision(*this);
}

//----------------------------------------------------------------------------

void Gate::collision(Thief& thief)
{
	if (thief.checkHasKey())
	{
		m_isRemoved = true;
		thief.updateHasKey();
	}
	else
		thief.collision(*this);
		//only if thief has a key open the gate
}

//----------------------------------------------------------------------------

void Gate::collision(Gnome& gnome)
{
	gnome.collision(*this);
}