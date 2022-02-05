#pragma once

//-------------------------------include section------------------------------

#include <iostream>
#include "list.h"
#include "Rational.h"
#include "Poly.h"

//--------------------------------func section--------------------------------

//this function allocates new memory for the new node to be added
List* List::createNode(Rational currCoeff, int power)
{
	List* Node = nullptr;
	Node = new List(currCoeff, power, nullptr);
	
	if (Node == nullptr)
	{
		std::cerr << "failed to alloc memory\n";
		exit(EXIT_FAILURE);
	}

	return Node;
}

//----------------------------------------------------------------------------

//this function deletes memory allocated after the program is done 
void List::deleteList(List* head)
{
	List* tempPtr;
	while (head != NULL)
	{
		tempPtr = head->m_next;
		delete head;
		head = tempPtr;
	}
}