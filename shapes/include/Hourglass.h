#pragma once

//------------------------------include section-------------------------------
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"
#include "Rectangle.h"
#include "Triangle.h"

//-------------------------------class section--------------------------------

// class "Hourglass" declaration
class Hourglass {
public:
	// constructors
	Hourglass();
	Hourglass(const Triangle& upper, const Triangle& lower);
	Hourglass(const Triangle& lower);
	
	// shape info 
	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeight() const;

	// general functions
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;

	bool scale(double factor);

private:
	Triangle m_lower;		// holds the lower part of the hourglass
	Triangle m_upper;		// holds the upper part of the hourglass

	struct Vertex m_vertices[5]; // holds all vertices of the shape

	void setTriangles(const Triangle& upper, const Triangle& lower);
	void setHourglassDef();
	void setHourglass();
};