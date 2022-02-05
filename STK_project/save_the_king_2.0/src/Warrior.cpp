#pragma once

//-------------------------------include section------------------------------

#include "Warrior.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Warrior::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Warrior::collision(King& king)
{
	stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Mage& Mage)
{
	stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Thief& thief)
{
    stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Gnome& gnome)
{
	stop();
	gnome.collision(*this);
}

//----------------------------------------------------------------------------

void Warrior::collision(Wall& wall)
{
	stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Throne& throne)
{
	stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Fire& fire)
{
	stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Gate& gate)
{
	stop();
}

//----------------------------------------------------------------------------

void Warrior::collision(Portal& portal)
{
	if (!m_playerInPortal)
	{
		m_playerInPortal = true;
		m_object.setPosition(portal.getPosition());
	}
}