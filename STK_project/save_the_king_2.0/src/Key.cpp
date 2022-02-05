#pragma once

//-------------------------------include section------------------------------

#include "Key.h"
#include "Thief.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Key::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Key::collision(Thief& thief)
{
	if (!thief.checkHasKey()) 
	{
		thief.updateHasKey();
		m_isRemoved = true;
	}
	//check if thief doesnt have a key, otherwise thief cannot pick another key
}