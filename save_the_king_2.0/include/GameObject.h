#pragma once

//-------------------------------include section------------------------------

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "Macros.h"
#include <vector>

//--------------------------------using section-------------------------------

using sf::RenderTexture;
using sf::RectangleShape;
using sf::FloatRect;
using sf::Vector2f;
using sf::Texture;

class Player;
class King;
class Mage;
class Warrior;
class Thief;
class Gnome;
class Wall;
class Throne;
class Fire;
class Portal;
class Gate;
class Key;
class Orc;
class Consumable;

//--------------------------------class section-------------------------------

class GameObject
{
public:
	GameObject(const Texture&, const Vector2f&, float, float);
	virtual ~GameObject() {};

	bool checkIsRemoved() const;
	void draw(RenderTexture&);
	FloatRect getRect() const;

	virtual void collision(GameObject&) = 0;
	virtual void collision(King&) = 0;
	virtual void collision(Mage&) = 0;
	virtual void collision(Warrior&) = 0;
	virtual void collision(Thief&) = 0;
	virtual void collision(Gnome&) = 0;
	virtual void collision(Wall&) = 0;
	virtual void collision(Throne&) = 0;
	virtual void collision(Fire&) = 0;
	virtual void collision(Portal&) = 0;
	virtual void collision(Gate&) = 0;
	virtual void collision(Key&) = 0;
	virtual void collision(Orc&) = 0;
	virtual void collision(Consumable&) = 0;

protected:
	sf::RectangleShape m_object;

	bool m_isRemoved;
};