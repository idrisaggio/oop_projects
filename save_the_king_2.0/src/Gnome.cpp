#pragma once

//-------------------------------include section------------------------------

#include "Gnome.h"

//---------------------------------func section-------------------------------
//gnome constructor, it sets the gnomes speed 
Gnome::Gnome(const Texture& texture, const Vector2f& position, float objectHeight, float objectWidth)
	: DynamicObject(texture, position, objectHeight, objectWidth)
{
	m_speed = GNOME_SPEED;
}

//----------------------------------------------------------------------------

Vector2f Gnome::getPosition() const
{
	return m_object.getPosition(); 
}

//----------------------------------------------------------------------------
//collision functions, each function depends on what it collides with
void Gnome::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Gnome::collision(King& king)
{

	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Mage& mage)
{

	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Warrior& warrior)
{

	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Thief& thief)
{

	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Gnome& gnome)
{
	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Wall& wall)
{
	stop(); 
}

//----------------------------------------------------------------------------

void Gnome::collision(Throne& throne)
{
	stop(); 
}

//----------------------------------------------------------------------------

void Gnome::collision(Fire& fire)
{
	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Portal& portal)
{
	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Gate& gate)
{
	stop();
}

//----------------------------------------------------------------------------

void Gnome::collision(Orc& orc)
{
	stop();
}

//----------------------------------------------------------------------------

void Gnome::disposeGnome(Gnome& gnome)
{
	gnome.m_isRemoved = true;
}

//----------------------------------------------------------------------------
//this functions randomly generates a direction for the gnome to move to
void Gnome::gnomeDirection(float dt)
{

	if ((m_clock.getElapsedTime().asSeconds()) > 1)
	{
		int direction = rand() % 4; //randomly choose direction
		switch (direction) {
		case 0:
			m_direction = Vector2f(0, -m_speed * dt);
			break;
		case 1:
			m_direction = Vector2f(0, m_speed * dt);
			break;
		case 2:
			m_direction = Vector2f(-m_speed * dt, 0);
			break;
		case 3:
			m_direction = Vector2f(m_speed * dt, 0);
			break;
		default:
			m_direction = Vector2f(0, 0);
			break;
		}
		m_clock.restart();
	}
}

//----------------------------------------------------------------------------

Vector2f Gnome::setDirection(float deltaTime, bool& m_turn)
{
	gnomeDirection(deltaTime); 
	return m_direction;
}