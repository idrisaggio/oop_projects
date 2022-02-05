#pragma once

//-------------------------------include section------------------------------

#include <memory>
#include "StaticObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

//--------------------------------using section-------------------------------

using sf::Vector2f;
using sf::Texture;
using sf::Keyboard;

//--------------------------------class section-------------------------------

class Consumable : public StaticObject
{
public:
	Consumable(const Texture&, const Vector2f&, float, float);
	~Consumable() {};

	virtual void collision(GameObject&) override;
	virtual void collision(King&) override;
	virtual void collision(Mage&) override;
	virtual void collision(Warrior&) override;
	virtual void collision(Thief&) override;
	virtual void collision(Gnome&) override {};
	virtual void collision(Wall&) override {};
	virtual void collision(Throne&) override {};
	virtual void collision(Fire&) override {};
	virtual void collision(Portal&) override {};
	virtual void collision(Gate&) override {};
	virtual void collision(Key&) override {};
	virtual void collision(Orc&) override {};
	virtual void collision(Consumable&) override {};
};