#pragma once


//------------------------------include section-------------------------------
#include <cmath>
#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"
#include "macros.h"
#include "Triangle.h"
#include "Hourglass.h"
#include <iostream>

//-------------------------------func section---------------------------------

/* the default constructor. it was needed to be added for the sake of the
 * compilation. even though it was not mentioned in the exercise */
Hourglass::Hourglass()
{
	m_vertices[0] = Vertex(20, 20);
	m_vertices[1] = Vertex(30, 20);
	m_vertices[2] = Vertex(25, 20 + sqrt(75));
	m_vertices[3] = Vertex(20, 20 + sqrt(75));
	m_vertices[4] = Vertex(30, 20 + sqrt(75));
}

//----------------------------------------------------------------------------

//a constructor that recieves a lower and an upper triangle 
Hourglass::Hourglass(const Triangle& upper,
					const Triangle& lower)
{
	setTriangles(upper, lower);
}

//----------------------------------------------------------------------------

//a constructor that only recieves a lower triangle and forms an upper one
Hourglass::Hourglass(const Triangle& lower)
{					
    Vertex v0 = Vertex (lower.getVertex(0).m_col, lower.getVertex(0).m_row 
						+ lower.getHeight() * 2);
	Vertex v1 = Vertex (lower.getVertex(1).m_col, lower.getVertex(1).m_row 
						+ lower.getHeight() * 2);	

	Triangle upper = Triangle(v0, v1, -1 * lower.getHeight());

	setTriangles(upper, lower);
    
}

//----------------------------------------------------------------------------

/* a func to get a vertex of a triangle. it recieves an integer that indicates
 * the index of a vertex in the triangle */
Vertex Hourglass::getVertex(int index) const
{
	return m_lower.getVertex(index);
}

//----------------------------------------------------------------------------

//a func that returns the distance btw two vertices
double Hourglass::getLength() const
{
	double length = distance(m_vertices[0], m_vertices[1]);
    return length >= 0 ? length : -length;
}

//----------------------------------------------------------------------------

//a func that returns the height of the hourglass
double Hourglass::getHeight() const
{
	double height = (m_vertices[0].m_row - m_vertices[2].m_row) * 2;
	return height >= 0 ? height : -height;
}

//----------------------------------------------------------------------------

//a func that draws the hourglass
void Hourglass::draw(Board& board) const
{
	board.drawLine(m_vertices[0], m_vertices[1]);
	board.drawLine(m_vertices[2], m_vertices[1]);
	board.drawLine(m_vertices[2], m_vertices[0]);
	board.drawLine(m_vertices[3], m_vertices[2]);
	board.drawLine(m_vertices[4], m_vertices[2]);
	board.drawLine(m_vertices[4], m_vertices[3]);
}

//----------------------------------------------------------------------------

//a func that draws a frame of a rectangle around the hourglass
Rectangle Hourglass::getBoundingRectangle() const
{
	struct Vertex bottomLeft, topRight;
    
	bottomLeft.m_col = m_vertices[0].m_col;
	bottomLeft.m_row = m_vertices[0].m_row;
	topRight.m_col = m_vertices[4].m_col;
	topRight.m_row = m_vertices[4].m_row;
    
	return Rectangle(bottomLeft, topRight);
}

//----------------------------------------------------------------------------

//a func that returns the perimeter of the hourglass
double Hourglass::getPerimeter() const
{
	return (getLength() * 6);
}

//----------------------------------------------------------------------------

//a func that returns the area of the hourglass
double Hourglass::getArea() const
{
	double area = (getHeight() * (getLength() / 2))*2;
	return area;
}

//----------------------------------------------------------------------------

//a function that returns the center of the horuglass
Vertex Hourglass::getCenter() const
{
	return m_vertices[2];
}

//----------------------------------------------------------------------------

//a func that upscales/downscales the size of the triangle using a given factor
bool Hourglass::scale(double factor)
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
		m_vertices[3].m_col = center.m_col - (length / 2);
		m_vertices[3].m_row = center.m_row + (height / 2);
		m_vertices[4].m_col = center.m_col + (length / 2);
		m_vertices[4].m_row = center.m_row + (height / 2);

		return true;
	}
	else
		return false;
}

//----------------------------------------------------------------------------

/* a func that checks if everything in this hourglass is valid, if so it 
 * updates the members if not it uses the default input given */
void Hourglass::setTriangles(const Triangle& upper,
							const Triangle& lower)
{	
	if(lower.getVertex(2).m_col == upper.getVertex(2).m_col
	    && lower.getVertex(2).m_row == upper.getVertex(2).m_row
        && lower.getVertex(0).m_row == lower.getVertex(1).m_row
        && upper.getVertex(0).m_row == upper.getVertex(1).m_row
        && lower.getVertex(0).m_row * 2 == upper.getVertex(0).m_row
        && lower.getVertex(1).m_row * 2 == upper.getVertex(1).m_row
		&& lower.getVertex(0).m_col == upper.getVertex(0).m_col
		&& lower.getVertex(1).m_col == upper.getVertex(1).m_col)
    {
		m_upper = upper;
		m_lower = lower;
		setHourglass();
	}
	else
		setHourglassDef();
}

//----------------------------------------------------------------------------

//a func that takes the default input
void Hourglass::setHourglassDef()
{
	m_vertices[0] = Vertex(20, 20);
	m_vertices[1] = Vertex(30, 20);
	m_vertices[2] = Vertex(25, 20 + sqrt(75));
	m_vertices[3] = Vertex(20, 20 + 2 * sqrt(75));
	m_vertices[4] = Vertex(30, 20 + 2 * sqrt(75));
}

//----------------------------------------------------------------------------

//a func that stores the given valid input 
void Hourglass::setHourglass()
{
	m_vertices[0] = m_lower.getVertex(0);
	m_vertices[1] = m_lower.getVertex(1);
	m_vertices[2] = m_lower.getVertex(2);
	m_vertices[3] = m_upper.getVertex(0);
	m_vertices[4] = m_upper.getVertex(1);
}