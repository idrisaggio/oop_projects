#pragma once

//-------------------------------include section------------------------------

#include "Consumable.h"

//--------------------------------class section-------------------------------

class DecreaseTime : public Consumable
{
public:
	using Consumable::Consumable;

	~DecreaseTime() {};

	virtual void collision(King&) override;
	virtual void collision(Mage&) override;
	virtual void collision(Warrior&) override;
	virtual void collision(Thief&) override;
};