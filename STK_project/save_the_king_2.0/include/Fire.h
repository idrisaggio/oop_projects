#pragma once

//-------------------------------include section------------------------------

#include "StaticObject.h"

//--------------------------------class section-------------------------------

class Fire : public StaticObject
{
public:
	
	using StaticObject::StaticObject;
	
	~Fire() {};

	virtual void collision(GameObject&) override;
	virtual void collision(King&) override;
	virtual void collision(Mage&) override;
	virtual void collision(Warrior&) override;
	virtual void collision(Thief&) override;
	virtual void collision(Gnome&) override;
	virtual void collision(Wall&) override {};
	virtual void collision(Throne&) override {};
	virtual void collision(Fire&) override {};
	virtual void collision(Portal&) override {};
	virtual void collision(Gate&) override {};
	virtual void collision(Key&) override {};
	virtual void collision(Orc&) override {};
	virtual void collision(Consumable&) override {};
};
