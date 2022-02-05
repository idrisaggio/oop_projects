#pragma once

//------------------------------include section-------------------------------
#include <cmath>
#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"
#include "macros.h"

//-------------------------------func section---------------------------------

/* the default constructor. it was needed to be added for the sake of the
 * compilation. even though it was not mentioned in the exercise */
Rectangle::Rectangle()
{
	m_bottomLeft = Vertex(20, 10);
	m_topRight = Vertex(30, 20);
}

//----------------------------------------------------------------------------

//a constructor that recieves 2 vertices 
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	setVertices(bottomLeft, topRight);
}

//----------------------------------------------------------------------------

//a constructor that recieves an array of vertices
Rectangle::Rectangle(const Vertex vertices[2])
{
	setVertices(vertices[0], vertices[1]);
}

//----------------------------------------------------------------------------

//a func that recieves the values of 2 vertices
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	Vertex bottomLeft(x0, y0);
	Vertex topRight(x1, y1);

	setVertices(bottomLeft, topRight);
}

//----------------------------------------------------------------------------

/*a constructor that receives a start point, widthand height, the function 
computes the other vertices*/
Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	Vertex topRight(start.m_col + width, start.m_row + height);
	setVertices(start, topRight);
}

//----------------------------------------------------------------------------

//this func returns bottom left vertex
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

//----------------------------------------------------------------------------

//this function return topright vertex
Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}

//----------------------------------------------------------------------------

//this func returns the width of the rectangle
double Rectangle::getWidth() const
{
	return (m_topRight.m_col - m_bottomLeft.m_col);
}

//----------------------------------------------------------------------------

//this func returns the height of the rectangle 
double Rectangle::getHeight() const
{
	return (m_topRight.m_row - m_bottomLeft.m_row);
}

//----------------------------------------------------------------------------
/* this function computes the top-left and bottom right vertices draws the 
 * rectangle */
void Rectangle::draw(Board& board) const
{
	Vertex topLeft(m_bottomLeft.m_col, m_topRight.m_row);
	Vertex bottomRight(m_topRight.m_col, m_bottomLeft.m_row);
	board.drawLine(topLeft, m_bottomLeft);
	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(bottomRight, m_topRight);
	board.drawLine(m_topRight, topLeft);
}

//----------------------------------------------------------------------------

//this function forms a rectangle frame around the rectangle
Rectangle Rectangle::getBoundingRectangle() const
{
	return *this;
}

//----------------------------------------------------------------------------

//this func returns the are of the rectangle
double Rectangle::getArea() const
{
	return(getWidth() * getHeight());
}

//----------------------------------------------------------------------------

//this func returns the perimeter of the rectangle
double Rectangle::getPerimeter() const
{
	return (2 * (getWidth() + getHeight()));
}

//----------------------------------------------------------------------------

//this func returns the center of the rectangle
Vertex Rectangle::getCenter() const
{
	Vertex Center((m_topRight.m_col + m_bottomLeft.m_col) / 2,
			(m_topRight.m_row + m_bottomLeft.m_row) / 2);

	return Center;
}

//----------------------------------------------------------------------------

/* this func upscales/downscales the size of the rectangle according to the 
 * given factor */
bool Rectangle::scale(double factor)
{
	if(factor > 0)
	{
		Vertex center = getCenter();
		double height = getHeight() * factor;
		double width = getWidth() * factor;

		m_bottomLeft.m_col = center.m_col - (width / 2);
		m_bottomLeft.m_row = center.m_row - (height / 2);
		m_topRight.m_col = center.m_col + (width / 2);
		m_topRight.m_row = center.m_row + (height / 2);

		return true;
	}
	else
		return false;
}

//----------------------------------------------------------------------------

/*this func checks if al vertices are valid then updates the members, 
 * if not we use the default inp */
void Rectangle::setVertices(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (bottomLeft.isValid() && topRight.isValid()
		&& topRight.isHigherThan(bottomLeft)
		&& topRight.isToTheRightOf(bottomLeft))
	{
		m_bottomLeft = bottomLeft;
		m_topRight = topRight;

	}

	else
	{
		m_bottomLeft = Vertex(20, 10);
		m_topRight = Vertex(30,20);
	}
}