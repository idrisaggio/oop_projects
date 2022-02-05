# pragma once

//------------------------------include section-------------------------------
#include <cmath>
#include "Rectangle.h"
#include "Square.h"
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"

//-------------------------------func section---------------------------------

/* the default constructor. it was needed to be added for the sake of the
 * compilation. even though it was not mentioned in the exercise */
Square::Square()
{
	 m_bottomLeft = Vertex(20, 10);
	 m_topRight = Vertex(30, 20);
}

//----------------------------------------------------------------------------

/* a constructor. it recieves 2 vertices; the bottom left vertex and the 
 * top right vertex, to built the square */
Square::Square(const Vertex& bottomLeft,
		const Vertex& topRight)
{
	setVertices(bottomLeft, topRight);
}

//----------------------------------------------------------------------------

/* a constructor. it recieves the starting vertex of a square and the length 
 * between 2 vertices to build the square */
Square::Square(const Vertex& start,
		double length)
{
	Vertex topRight(start.m_col + length, start.m_row + length);
	setVertices(start, topRight);
}

//----------------------------------------------------------------------------

// a func to get the bottom left vertex of the square
Vertex Square::getBottomLeft() const
{
	return m_bottomLeft;
}

//----------------------------------------------------------------------------

// a func to get the top right vertex of the square
Vertex Square::getTopRight() const
{
	return m_topRight;
}

//----------------------------------------------------------------------------

// a func to get the length between 2 vertices
double Square::getLength() const
{
	return (m_topRight.m_col - m_bottomLeft.m_col);
}

//----------------------------------------------------------------------------

// a func to draw the square. it recieves the drawing board
void Square::draw(Board& board) const
{
	Vertex topLeft(m_bottomLeft.m_col, m_topRight.m_row);
	Vertex bottomRight(m_topRight.m_col, m_bottomLeft.m_row);
	board.drawLine(topLeft, m_bottomLeft);
	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(bottomRight, m_topRight);
	board.drawLine(m_topRight, topLeft);
}

//----------------------------------------------------------------------------

/* a func to draw a frame on the borders of the square.
 * it returns the bounding rectangle */
Rectangle Square::getBoundingRectangle() const
{
	struct Vertex v1, v2;

	v1.m_col = m_bottomLeft.m_col;
	v1.m_row = m_bottomLeft.m_row;
	v2.m_col = m_topRight.m_col;
	v2.m_row = m_topRight.m_row;
	
	return Rectangle(v1, v2);
}

//----------------------------------------------------------------------------

// a func that computes the area of the square and retruns it
double Square::getArea() const
{
	return (pow(getLength(), 2));
}

//----------------------------------------------------------------------------

// a func that computes the perimeter of the square and returns it
double Square::getPerimeter() const
{
	return (4 * getLength());
}

//----------------------------------------------------------------------------

// a func that computes the center of the suare (a vertex) and returns it
Vertex Square::getCenter() const
{
	Vertex Center((m_topRight.m_col + m_bottomLeft.m_col) / 2,
				(m_topRight.m_row + m_bottomLeft.m_row) / 2);

	return Center;
}

//----------------------------------------------------------------------------

/* a func that upscales/downscales the size of the square by a given factor, 
 * that the func recieves. it returns true if the factor is valid.
 * otherwise it returns false */
bool Square::scale(double factor)
{
	if (factor > 0)
	{
		Vertex center = getCenter();
		double length = getLength() * factor;

		m_bottomLeft.m_col = center.m_col - (length / 2);
		m_bottomLeft.m_row = center.m_row - (length / 2);
		m_topRight.m_col = center.m_col + (length / 2);
		m_topRight.m_row = center.m_row + (length / 2);

		return true;
	}
	else
		return false;
}

//----------------------------------------------------------------------------

/* a func that sets the vertices of the square. it recieves 2 vertices, 
 * the bottom left and the top right ones.
 * checks if they are valid and sets them.
 * otherwise, it will set the vertices with default values */
void Square::setVertices(const Vertex& bottomLeft,
		const Vertex& topRight)
{
	Vertex bottomRight(m_topRight.m_col, m_bottomLeft.m_row);
	
	if (bottomLeft.isValid() && topRight.isValid()
		&& topRight.isHigherThan(bottomLeft)
		&& topRight.isToTheRightOf(bottomLeft)
		&& (distance(bottomLeft, bottomRight)
		== distance(bottomRight, topRight)))
	{
	
		m_bottomLeft = bottomLeft;
		m_topRight = topRight;

	}

	else
	{
		m_bottomLeft = Vertex(20, 10);
		m_topRight = Vertex(30, 20);
	}
}