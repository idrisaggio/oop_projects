#pragma once

//-------------------------------include section------------------------------

#include "Consumable.h"

//--------------------------------class section-------------------------------

class DisposeGnomes : public Consumable
{
public:
	using Consumable::Consumable;
	
	~DisposeGnomes() {};

	virtual void collision(King&) override;
	virtual void collision(Mage&) override;
	virtual void collision(Warrior&) override;
	virtual void collision(Thief&) override;

private:
};