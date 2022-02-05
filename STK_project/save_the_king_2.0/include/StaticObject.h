#pragma once

//-------------------------------include section------------------------------

#include "GameObject.h"

//--------------------------------class section-------------------------------

class StaticObject : public GameObject
{
public:

	//c-tor
	using GameObject::GameObject;
	//d-tor
	virtual ~StaticObject() {};

	Vector2f getPosition() const;
};
