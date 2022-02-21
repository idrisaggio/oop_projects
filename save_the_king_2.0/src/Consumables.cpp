#pragma once

//-------------------------------include section------------------------------

#include "Consumable.h"

//---------------------------------func section-------------------------------
//consumable constructor
Consumable::Consumable(const Texture& texture, const Vector2f& position, float objectHeight, float objectWidth)
	: StaticObject(texture, position, objectHeight, objectWidth)
{

}

//----------------------------------------------------------------------------
//collision functions, each function depends on what it collides with
void Consumable::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Consumable::collision(King& King)
{
	m_isRemoved = true;
	King.collision(*this);
}

//----------------------------------------------------------------------------

void Consumable::collision(Mage& Mage)
{
	m_isRemoved = true;
	Mage.collision(*this);
}

//----------------------------------------------------------------------------

void Consumable::collision(Warrior& Warrior)
{
	m_isRemoved = true;
	Warrior.collision(*this);
}

//----------------------------------------------------------------------------

void Consumable::collision(Thief& Thief)
{
	m_isRemoved = true;
	Thief.collision(*this);
}