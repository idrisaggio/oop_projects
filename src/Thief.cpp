#pragma once

//-------------------------------include section------------------------------

#include "Thief.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Thief::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Thief::collision(King& king) 
{
    stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Mage& mage) 
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Warrior& warrior) 
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Gnome& gnome) 
{
	stop();
	gnome.collision(*this);
}

//----------------------------------------------------------------------------

void Thief::collision(Wall& wall)
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Gate& Gate) 
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Throne& throne)
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Fire& fire) 
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::collision(Portal& portal)
{
	if (!m_playerInPortal)
	{
		m_playerInPortal = true;
		m_object.setPosition(portal.getPosition());
	}
}

//----------------------------------------------------------------------------

void Thief::collision(Orc& orc) 
{
	stop();
}

//----------------------------------------------------------------------------

void Thief::updateHasKey()
{
	m_hasKey = !m_hasKey;
}