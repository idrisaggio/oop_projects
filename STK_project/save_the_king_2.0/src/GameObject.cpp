#pragma once

//-------------------------------include section------------------------------

#include "GameObject.h"

//---------------------------------func section-------------------------------
//game object constructor, sets each object to its position and gives it its txr
GameObject::GameObject(const Texture& texture, const Vector2f& position, float objectHeight, float objectWidth)
	:m_isRemoved(false), m_object({ objectHeight, objectWidth })
{
	m_object.setTexture(&texture);
	m_object.setPosition(position);
}

//----------------------------------------------------------------------------

bool GameObject::checkIsRemoved() const
{
	return m_isRemoved;
}

//----------------------------------------------------------------------------

void GameObject::draw(RenderTexture& obj)
{
	obj.draw(m_object);
}

//----------------------------------------------------------------------------

FloatRect GameObject::getRect() const
{
	return m_object.getGlobalBounds();
}