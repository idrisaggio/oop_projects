#pragma once

//-------------------------------include section------------------------------

#include <memory>
#include <SFML/Graphics.hpp>
#include "DynamicObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

//--------------------------------using section-------------------------------

using sf::Vector2f;
using sf::Keyboard;

//--------------------------------class section-------------------------------

class Gnome : public DynamicObject
{
public:
	//c-tor
	Gnome(const Texture&, const Vector2f&, float, float);
	//d-tor
	~Gnome() {};

	//get position of monster
	Vector2f getPosition() const;

	void disposeGnome(Gnome&);

	virtual void collision(GameObject&);
	virtual void collision(King&);
	virtual void collision(Mage&);
	virtual void collision(Warrior&);
	virtual void collision(Thief&);
	virtual void collision(Gnome&);
	virtual void collision(Wall&);
	virtual void collision(Throne&);
	virtual void collision(Fire&);
	virtual void collision(Portal&);
	virtual void collision(Gate&);
	virtual void collision(Key&) {};
	virtual void collision(Orc&);
	virtual void collision(Consumable&) {};

protected:
	void gnomeDirection(float dt);
	
private:

	sf::Clock m_clock;
	virtual Vector2f setDirection(float, bool&);
};