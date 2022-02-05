#pragma once

//-------------------------------include section------------------------------

#include "Player.h"

//---------------------------------func section-------------------------------
//player constructor that gives a players its speed 
Player::Player(const Texture& texture, const Vector2f& position, float objectHeight, float objectWidth)
	: DynamicObject(texture, position, objectHeight, objectWidth)
{
	m_speed = PC_SPEED;
	m_reachedThrone = false;
	m_hasKey = false;
}

//----------------------------------------------------------------------------

void Player::setStartPosition(const Vector2f& position)
{
	m_startingPos = position;
	m_object.setPosition(position);
}

//----------------------------------------------------------------------------

void Player::setConsumable(int num)
{
	m_consumable = num;
}

//----------------------------------------------------------------------------

void Player::resetConsumable()
{
	m_consumable = DEFAULT_CASE;
}

//----------------------------------------------------------------------------

int Player::getConsumable() const
{
	return m_consumable;
}

//----------------------------------------------------------------------------

Vector2f Player::getPosition() const
{
	return m_object.getPosition();
}

//----------------------------------------------------------------------------
//move to the directiong of the users keyboard input
Vector2f Player::setDirection(float deltaTime, bool& m_turn)
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
		return { 0, -m_speed * deltaTime };

	if (Keyboard::isKeyPressed(Keyboard::Down))
		return { 0, m_speed * deltaTime };

	if (Keyboard::isKeyPressed(Keyboard::Left))
		return { -m_speed * deltaTime, 0 };

	if (Keyboard::isKeyPressed(Keyboard::Right))
		return { m_speed * deltaTime, 0 };

	while (Keyboard::isKeyPressed(Keyboard::P))//if p is pressed change player
		m_turn = false;

	return { 0 ,0 };
}

//----------------------------------------------------------------------------

bool Player::isReachedThrone() const
{
	return m_reachedThrone;
}

//----------------------------------------------------------------------------

bool Player::checkHasKey() const
{
	return m_hasKey;
}

//----------------------------------------------------------------------------

void Player::setPosition(Vector2f newPos)
{
	m_object.move(newPos);
}

//----------------------------------------------------------------------------

bool Player::checkInPortal() const
{
	return m_playerInPortal;
}

//----------------------------------------------------------------------------

void Player::updateInPortal() 
{
	m_playerInPortal = !m_playerInPortal;
}