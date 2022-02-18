28/10/2021

Project guide (shapes)
==============================================================================
Authers: Raed Barhoum, Anton Nahhas

..................................


Introduction:
------------

this program builds simple objects of geometric shapes. 4 objects are built:
rectangle, Triangle , square and hourglass(which is 2 triangles on each other
one is normal and the other is inverted, they both have the same head).
each shape had a header and an executable file. the shapes are drawn by the main.


++++++++++++++++++++++++


Program's Files:
----------------
main.cpp:
    the main function of the program which runs the program, when this
    function runs it demands from the user to enter points as inputs to
    build the demanded object.
    the function prints the object and its data on the board,the function
    ends after finishing all the objects.

Board.h/.cpp:
	the board will draw & print the shapes objects, this
	class is already prepared from the course staff.

Vertex.h/.cpp:
	a vertex class which describes a vertex made of
    two points (x, y), contains also some sub-functions to help dealing with
    the vertices to be drawn on.

Utilities.h/.cpp:
    class which contains helper functions to deal with points.

macros.h:
    contains the size_parameters of the board.

Triangle.h/.cpp:
    a class which describes an equilateral triangle which contains multiple
    constructors builders and some other mathematical sub-functions to help working with
    triangles.
	
Square.h/.cpp:
	the square class describes a square using two vertices a bottom left
    and a top right one which together the board forms a square, with 
	the help of other mathematical sub-functions and constructors.
 
Rectangle.h/.cpp:
	a rectangle class which describes a rectangle giving two vertices
	(buttom left, top right), and some other sub-functions and constructors
	to deal with rectangles objects easily.

Hourglass.h/.cpp:
   	this class describes an hourglass which are two triangles one upwards 
	and the other is inverted both heads are touching forming an sand 
	hourglass, this is done with the help of other sub-functions and 
	constructors.


++++++++++++++++++++++++


data structures:
---------------

in this program we only used arrays as data structures, its main role was
to hold the vertices of the object we would create mainly for triangles.


++++++++++++++++++++++++


known bugs:
----------

no bugs where noticed during the program process.

 
++++++++++++++++++++++++


Other Notes:
-----------

this project helped me learn a lot about classes, objects,
constructors, etc. definately worth the time spent on it.  


++++++++++++++++++++++++

 

   
