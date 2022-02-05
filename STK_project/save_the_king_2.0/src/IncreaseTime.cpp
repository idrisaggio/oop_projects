#pragma once

//-------------------------------include section------------------------------

#include "IncreaseTime.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void IncreaseTime::collision (King& King)
{
	m_isRemoved = true;
	King.setConsumable(INC);
	King.collision(*this);
}

//----------------------------------------------------------------------------

void IncreaseTime::collision(Mage& Mage)
{
	m_isRemoved = true;
	Mage.setConsumable(INC);
	Mage.collision(*this);
}

//----------------------------------------------------------------------------

void IncreaseTime::collision(Warrior& Warrior)
{
	m_isRemoved = true;
	Warrior.setConsumable(INC);
	Warrior.collision(*this);
}

//----------------------------------------------------------------------------

void IncreaseTime::collision(Thief& Thief)
{
	m_isRemoved = true;
	Thief.setConsumable(INC);
	Thief.collision(*this);
}