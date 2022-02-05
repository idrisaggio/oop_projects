#pragma once

//------------------------------include section-------------------------------
#include "Board.h"
#include "Rectangle.h"

//-------------------------------class section--------------------------------

// class "Square" declaration
class Square {
public:
	// constructors
	Square();
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);

	// shape info 
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getLength() const;

	// general functions
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;

	bool scale(double factor);

private:

	Vertex m_bottomLeft;	// holds the bottom left vertex
	Vertex m_topRight;		// holds the bottom left vertex

	// sets the vertices of the shape
	void setVertices(const Vertex& bottomLeft, const Vertex& topRight);
};