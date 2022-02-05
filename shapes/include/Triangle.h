#pragma once

//------------------------------include section-------------------------------
#include "Vertex.h"
#include "Utilities.h"
#include "Rectangle.h"

//-------------------------------class section--------------------------------

// class "Hourglass" declaration
class Triangle {
	
public:
	// constructors
	Triangle();
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);

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
	
	struct Vertex m_vertices[3];	// holds all vertices of the shape
	
	void setVertices(const Vertex& v0, const Vertex& v1, const Vertex& v2);
	void setInputValues(Vertex v0, Vertex v1, Vertex v2);
	void setDefaultValues();
};