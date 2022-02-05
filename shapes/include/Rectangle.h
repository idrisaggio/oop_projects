#pragma once

//------------------------------include section-------------------------------
#include "Vertex.h"
#include "Board.h"

//-------------------------------class section--------------------------------

// class "Rectangle" declaration
class Rectangle
{
	public:
		// constructors
		Rectangle();
		Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
		Rectangle(const Vertex vertices[2]);
		Rectangle(double x0, double y0, double x1, double y1);
		Rectangle(const Vertex& start, double width, double height);
		
		// shape info 
		Vertex getBottomLeft() const;
		Vertex getTopRight() const;
		double getWidth() const;
		double getHeight() const;
		
		// general functions
		void draw(Board& board) const;
		Rectangle getBoundingRectangle() const;
		double getArea() const;
		double getPerimeter() const;
		Vertex getCenter() const;

		bool scale(double factor);
	
	private:
		struct Vertex m_bottomLeft;		// holds the bottom left vertex
		struct Vertex m_topRight;		// holds the top right left vertex
		
		void setVertices(const Vertex& bottomLeft, const Vertex& topRight);
};