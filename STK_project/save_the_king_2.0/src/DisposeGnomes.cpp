#pragma once

//-------------------------------include section------------------------------

#include "DisposeGnomes.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void DisposeGnomes::collision(King& King)
{
	m_isRemoved = true;
	King.setConsumable(DIS);
	King.collision(*this);
}

//----------------------------------------------------------------------------

void DisposeGnomes::collision(Mage& Mage)
{
	m_isRemoved = true;
	Mage.setConsumable(DIS);
	Mage.collision(*this);
}

//----------------------------------------------------------------------------

void DisposeGnomes::collision(Warrior& Warrior)
{
	m_isRemoved = true;
	Warrior.setConsumable(DIS);
	Warrior.collision(*this);
}

//----------------------------------------------------------------------------

void DisposeGnomes::collision(Thief& Thief)
{
	m_isRemoved = true;
	Thief.setConsumable(DIS);
	Thief.collision(*this);
}