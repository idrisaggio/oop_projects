#pragma once

//-------------------------------include section------------------------------

#include "Portal.h"
#include "Gnome.h"

//---------------------------------func section-------------------------------
//collision functions, each function depends on what it collides with
void Portal::collision(GameObject& object)
{
	object.collision(*this);
}

//----------------------------------------------------------------------------

void Portal::collision(Gnome& gnome)
{
	gnome.collision(*this);
}