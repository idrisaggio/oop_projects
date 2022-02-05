#pragma once

//-------------------------------include section------------------------------

#include "StaticObject.h"

//---------------------------------func section-------------------------------

Vector2f StaticObject::getPosition() const
{
	return m_object.getPosition();
}