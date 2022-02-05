#pragma once

//-------------------------------include section------------------------------

#include "DynamicObject.h"
#include "Portal.h"

//--------------------------------using section-------------------------------

using sf::Vector2f;
using sf::Keyboard;

//--------------------------------class section-------------------------------

class Player : public DynamicObject
{
public:
	Player(const Texture&, const Vector2f&, float, float);

	~Player() {};

	
	virtual void setStartPosition(const Vector2f&);
	virtual void setConsumable(int);
	
	Vector2f setDirection(float, bool&);
	int getConsumable() const;
	Vector2f getPosition() const;
	
	bool checkHasKey() const;
	bool checkInPortal() const;
	bool isReachedThrone() const;
	
	void setPosition(Vector2f);
	void updateInPortal();
	void resetConsumable();

protected:
	bool m_reachedThrone;
	bool m_hasKey;
	bool m_playerInPortal = false;

private:
	int m_consumable = DEFAULT_CASE;
};