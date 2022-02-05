#pragma once

//-------------------------------include section------------------------------

#include "King.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void King::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void King::collision(Mage& mage)
{
	stop();
}

//----------------------------------------------------------------------------

void King::collision(Warrior& warrior) 
{
	stop();
}

//----------------------------------------------------------------------------

void King::collision(Thief& thief) 
{
    stop();
}

//----------------------------------------------------------------------------

void King::collision(Gnome& gnome) 
{
	stop();
	gnome.collision(*this);
}

//----------------------------------------------------------------------------

void King::collision(Wall& wall)
{
	stop();
}

//----------------------------------------------------------------------------

void King::collision(Throne& throne)
{
	m_reachedThrone = true;
}

//----------------------------------------------------------------------------

void King::collision(Fire& fire) 
{
	stop();
}

//----------------------------------------------------------------------------

void King::collision(Portal& portal)
{
	if (!m_playerInPortal) 
	{
		m_playerInPortal = true;
		m_object.setPosition(portal.getPosition());
	}
}

//----------------------------------------------------------------------------

void King::collision(Gate& gate)
{
	stop();
}

//----------------------------------------------------------------------------

void King::collision(Orc& orc) 
{
	stop();
}