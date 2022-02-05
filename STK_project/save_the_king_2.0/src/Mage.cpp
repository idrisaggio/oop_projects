#pragma once

//-------------------------------include section------------------------------

#include "Mage.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Mage::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Mage::collision(King& king)
{
	stop();
}

//----------------------------------------------------------------------------

void Mage::collision(Warrior& warrior)
{
	stop();
}

//----------------------------------------------------------------------------

void Mage::collision(Thief& thief)
{
    stop();
}

//----------------------------------------------------------------------------

void Mage::collision(Gnome& gnome)
{
	stop();
	gnome.collision(*this);
}

//----------------------------------------------------------------------------

void Mage::collision(Wall& wall)
{
	stop();
}

//----------------------------------------------------------------------------

void Mage::collision(Throne& throne)
{
	stop();
}

//----------------------------------------------------------------------------

void Mage::collision(Gate& gate)
{
	stop();
}

//----------------------------------------------------------------------------

void Mage::collision(Orc& orc) 
{
	stop();
}