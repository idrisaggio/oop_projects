#pragma once

//-------------------------------include section------------------------------

#include "GameObject.h"

//--------------------------------using section-------------------------------

using sf::Vector2f;

//--------------------------------class section-------------------------------

class DynamicObject : public GameObject
{
public:
	DynamicObject(const Texture&, const Vector2f&, float, float);
	~DynamicObject() {};
	
	void reset();
	void move(bool&, float , const RenderTexture&);

protected:
	virtual Vector2f setDirection(float, bool&) = 0;

	void stop();

	Vector2f m_startingPos;
	Vector2f m_direction;

	float m_speed;

private:
	bool isInBounds(const RenderTexture& panel) const;

};

