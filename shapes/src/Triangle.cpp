#pragma once

//------------------------------include section-------------------------------
#include <cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Vertex.h"
#include "Board.h"
#include "macros.h"
#include "Utilities.h"

//-------------------------------func section--------------------------------

/* the default constructor. it was needed to be added for the sake of the
 * compilation. even though it was not mentioned in the exercise */ 
Triangle::Triangle()
{
    m_vertices[0] = Vertex(20,20);
	m_vertices[1] = Vertex(30,20);
	m_vertices[2] = Vertex(25,20+sqrt(70));
}

//----------------------------------------------------------------------------

// a constructor. it recieves an array of vertices to build the triangle
Triangle::Triangle(const Vertex vertices[3])
{
    setVertices(vertices[0], vertices[1], vertices[2]);
}

//----------------------------------------------------------------------------

//a constructor. it recieves 2 base vertices and height to build the triangle
Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
{
	Vertex head(v1.m_col - distance(v0, v1) / 2, v1.m_row + height);

	setVertices(v0, v1, head);
} 

//----------------------------------------------------------------------------

/* a func to get a vertex of a triangle. it recieves an integer that indicates
 * the index of a vertex in the triangle */
Vertex Triangle::getVertex(int index) const
{
    return m_vertices[index];
}

//----------------------------------------------------------------------------

// a func to get the length between 2 vertices
double Triangle::getLength() const
{
	double length = distance(m_vertices[0], m_vertices[1]);
	return length >= 0 ? length : -length;
}

//----------------------------------------------------------------------------
	
// a func to get the height of a triangle
double Triangle::getHeight() const
{
	double height = m_vertices[0].m_row - m_vertices[2].m_row;
	return height >= 0 ? height : -height;
}

//----------------------------------------------------------------------------

// a func to draw the triangle. it recieves the drawing board
void Triangle::draw(Board& board) const
{
	board.drawLine(m_vertices[0], m_vertices[1]);
	board.drawLine(m_vertices[2], m_vertices[1]);
	board.drawLine(m_vertices[2], m_vertices[0]);
}

//----------------------------------------------------------------------------

/* a func to draw a frame on the borders of the triangle. 
 * it returns the bounding rectangle */
Rectangle Triangle::getBoundingRectangle() const
{
	struct Vertex bottomLeft, topRight;
	
	bottomLeft.m_col = m_vertices[0].m_col;
	bottomLeft.m_row = m_vertices[0].m_row;
	topRight.m_col = m_vertices[1].m_col;
	topRight.m_row = m_vertices[2].m_row;

	return Rectangle(bottomLeft, topRight);
}

//----------------------------------------------------------------------------

// a func that computes the area of the triangle and retruns it
double Triangle::getArea() const
{
	double area = getHeight() * (getLength() / 2);
	return area;
}

//----------------------------------------------------------------------------

// a func that computes the perimeter of the triangle and returns it
double Triangle::getPerimeter() const
{
	return 3 * distance(m_vertices[0], m_vertices[1]);
}

//----------------------------------------------------------------------------

// a func that computes the center of the triangle (a vertex) and returns it
Vertex Triangle::getCenter() const
{
	struct Vertex centerVertex;
	centerVertex.m_row = ((m_vertices[2].m_row + m_vertices[0].m_row) / 2);
	centerVertex.m_col = ((m_vertices[1].m_col + m_vertices[0].m_col) / 2);
	return centerVertex;

}

//----------------------------------------------------------------------------

/* a func that upscales/downscales the size of the triangle by a given factor, 
 * that the func recieves. it returns true if the factor is valid.
 * otherwise it returns false */
bool Triangle::scale(double factor)
{
	if(factor > 0)
	{
		Vertex center = getCenter();
		double height = getHeight() * factor;
		double length = getLength() * factor;

		m_vertices[0].m_col = center.m_col - (length / 2);
		m_vertices[0].m_row = center.m_row - (height / 2);
		m_vertices[1].m_col = center.m_col + (length / 2);
		m_vertices[1].m_row = center.m_row - (height / 2);
		m_vertices[2].m_row = center.m_row + (height / 2);

		return true;
	}
	else
		return false;
}

//----------------------------------------------------------------------------

/* a func that sets the vertices of the triangle. it recieves 3 vertices, 
 * checks if they are valid and sets them.
 * otherwise, it will set the vertices with default values */
void Triangle::setVertices(const Vertex& v0, 
		const Vertex& v1, 
		const Vertex& v2)
{
	if (v0.isValid() && v1.isValid() && v2.isValid() && sameRow(v0, v1))
		setInputValues(v0, v1, v2);
	else
		setDefaultValues();
}

//----------------------------------------------------------------------------

// a func that sets the input vertices given by the user
void Triangle::setInputValues(Vertex v0,
		Vertex v1,
		Vertex v2)
{
	m_vertices[0].m_col = v0.m_col;
	m_vertices[0].m_row = v0.m_row;
	m_vertices[1].m_col = v1.m_col;;
	m_vertices[1].m_row = v1.m_row;;
	m_vertices[2].m_col = v2.m_col;
	m_vertices[2].m_row = v2.m_row;
}

//----------------------------------------------------------------------------

// a func that sets the default vertices given by the program
void Triangle::setDefaultValues()
{
	m_vertices[0].m_col = 20;
	m_vertices[0].m_row = 20;
	m_vertices[1].m_col = 30;
	m_vertices[1].m_row = 20;
	m_vertices[2].m_col = 25;
	m_vertices[2].m_row = (20+sqrt(75));
}