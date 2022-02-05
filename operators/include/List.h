#pragma once

#include "Rational.h"

struct List {
	
	List(Rational coeff, int power, List* next) 
	: m_coeff(coeff), m_power(power), m_next(next){}

	List* createNode(Rational, int);
	void deleteList(List*);

	Rational m_coeff;
	int m_power;
	List *m_next;
};