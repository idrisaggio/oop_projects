25/11/2021

Project guide (operators for polynomials and rationals)
==============================================================================
Authers: Raed Barhoum, Anton Nahhas

..................................


Introduction:
-------------

This project consists of 2 “libraries” of operators; one for rational numbers, and the other for polynomials. 
the objective of this program is to demonstrate the knowledge of how libraries and operators work.
the project requires the user to write a new source file (and must add it to the CMakeList.txt located in the
src folder) to utilize the operators.

++++++++++++++++++++++++


Design:
-------

There are 2 kinds of objects that can be created in this program: a rational number, or a polynomial.
Each polynomial is created by rational numbers as its coefficients.
Each polynomial is either one of the following:
An empty polynomial, The zero polynomial, A monomial, Free element polynomial


++++++++++++++++++++++++


Program's Files:
----------------

Rational.h/.cpp:
The class Rational is responsible for creating rational numbers, and every single mathematical operation on rational number/s.

Poly.h/.cpp:
The class Poly is responsible for creating polynomial, and every single mathematical operation on polynomial/s.

List.h/.cpp:
The class List is responsible for creating a linked list for each polynomial. It’s responsible for allocating and deallocating all memory in this project.


++++++++++++++++++++++++


Data structures:
----------------

For saving the data that represent each polynomial, the program creates for each one a linked list.
Each node in a linked list contains 3 elements: a coefficient, a power and a pointer to the next node.
Each node represents an element in the polynomial.


++++++++++++++++++++++++


Algorithms worth mentioning:
----------------------------
N/A.


++++++++++++++++++++++++


Known bugs:
-----------

No bugs where noticed during the program process.
 

++++++++++++++++++++++++


Other Notes:
------------

This project was an eye opening experience.
I better learned operators and how they work.
In addition I understood how libraries function.


++++++++++++++++++++++++
