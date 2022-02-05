#pragma once

//-------------------------------include section------------------------------

#include "DecreaseTime.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void DecreaseTime::collision(King& King)
{
	m_isRemoved = true;
	King.setConsumable(DEC); 
	King.collision(*this);
}

//----------------------------------------------------------------------------

void DecreaseTime::collision(Mage& Mage)
{
	m_isRemoved = true;
	Mage.setConsumable(DEC); 
	Mage.collision(*this);
}

//----------------------------------------------------------------------------

void DecreaseTime::collision(Warrior& Warrior)
{
	m_isRemoved = true;
	Warrior.setConsumable(DEC); 
	Warrior.collision(*this);
}

//----------------------------------------------------------------------------

void DecreaseTime::collision(Thief& Thief)
{
	m_isRemoved = true;
	Thief.setConsumable(DEC); 
	Thief.collision(*this);
}