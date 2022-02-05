#pragma once

//-------------------------------include section------------------------------

#include "DynamicObject.h"

//---------------------------------func section-------------------------------
//dynamic object constructor 
DynamicObject::DynamicObject(const Texture& texture, const Vector2f& position, float objectHeight, float objectWidth)
	: GameObject(texture, position, objectHeight, objectWidth), m_speed(0), m_startingPos(position)
{

}

//----------------------------------------------------------------------------
//this function is called when a level was reset, it resets each dynamic object 
//back to its startic position
void DynamicObject::reset()
{
	m_isRemoved = false;
	m_object.setPosition(m_startingPos);
}

//----------------------------------------------------------------------------

void DynamicObject::move(bool& m_turn, float deltaTime, const RenderTexture& panel)
{
	m_direction = setDirection(deltaTime, m_turn);
	m_object.move(m_direction); 

	if (!isInBounds(panel)) 
		stop();	
}

//----------------------------------------------------------------------------
//this function makes the object stop by moving it to the opposite direction
void DynamicObject::stop()
{
	m_object.move(-m_direction);
}

//----------------------------------------------------------------------------
//this function checks if the dynamic object is in bounds 
bool DynamicObject::isInBounds(const RenderTexture& panel) const
{
	if (m_object.getPosition().x < 0 || m_object.getPosition().y < 0 ||
		m_object.getPosition().x >(panel.getSize().x - m_object.getSize().x) ||
		m_object.getPosition().y >(panel.getSize().y - m_object.getSize().y))
		return false;

	return true; 
}