#pragma once

//-------------------------------include section------------------------------

#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>

#include "Rational.h"

//--------------------------------using section-------------------------------

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::cout;

//--------------------------------func section--------------------------------

/*the constructor checks for default value, which is 0. calculates all 
the rational nums depending on its form*/
Rational::Rational(int numer, int denom)

{
	if (denom == 0)
	{
		std::cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << std::endl;
		exit(0);
	}
	else if (numer == 0)
	{
		m_numer = numer;
		m_denom = 1;
	}	
	
	else if (numer == denom)
	{
		m_numer = 1;
		m_denom = 1;
	}
	else 
	{
		int d;
		d = std::gcd(numer, denom);
 
		m_numer = numer / d;
		m_denom = denom / d;
	} 
}

//----------------------------------------------------------------------------
//this function returns the numerator member
int Rational::getNumer()const
{
	return m_numer;
}

//----------------------------------------------------------------------------
//this function returns the denominator member
int Rational::getDenom()const
{
	return m_denom;
}

//----------------------------------------------------------------------------

/*this function creates a comparison operator between 2 Rationals*/
bool operator==(const Rational& a, const Rational& b)
{
	return (a.getNumer() == b.getNumer() && a.getDenom() == b.getDenom() ?
		true : false);
}

//----------------------------------------------------------------------------

/*this function creates an operator to check if 2 rational numbers are 
different*/
bool operator!=(const Rational& a, const Rational& b)
{
	return !(a == b);
}

//----------------------------------------------------------------------------

/*this function creates an operator that checks who is larger btw 2 rationals*/
bool operator>(const Rational& a, const Rational& b)
{
	if (a.getDenom() == b.getDenom())
		return (a.getNumer() > b.getNumer() ? true : false);
	else
	{
		int Denom1 = a.getDenom();
		int Denom2 = b.getDenom();
		int lcd = lcm(Denom1, Denom2);
		return ((a.getNumer() * (lcd / a.getDenom())) > (b.getNumer() * (lcd / b.getDenom())) ? true : false);
	}
}

//----------------------------------------------------------------------------

/*this function creates an operator that checks who is smaller btw 
2 rationals*/
bool operator<(const Rational& a, const Rational& b)
{
	return (a > b ? false : true);
}

//----------------------------------------------------------------------------

/*this function creates an operator that checks who is larger and equal btw 
2 rationals*/
bool operator>=(const Rational& a, const Rational& b)
{
	return (a == b || a > b ? true : false);
}

//----------------------------------------------------------------------------

/*this function creates an operator that checks who is smaller or equal
btw 2 rationals*/
bool operator<=(const Rational& a, const Rational& b)
{
	return (a == b || a < b ? true : false);
}

//----------------------------------------------------------------------------

/*this operator sums up 2 rational nums*/
Rational operator+(const Rational& a, const Rational& b)
{
	if (a.getDenom() == b.getDenom())
		return Rational(a.getNumer() + b.getNumer(), a.getDenom());
	else
	{
		int Denom1 = a.getDenom();
		int Denom2 = b.getDenom();
		int lcd = lcm(Denom1, Denom2);
		return Rational((a.getNumer() * (lcd / a.getDenom())) 
			+ (b.getNumer() * (lcd / b.getDenom())), lcd);
	}
}

//----------------------------------------------------------------------------

/*operator that deducts 2 rational nums*/
Rational operator-(const Rational& a,const Rational& b)
{
	if (a.getDenom() == b.getDenom())
		return Rational(a.getNumer() - b.getNumer(), a.getDenom());
	else
	{
		int Denom1 = a.getDenom();
		int Denom2 = b.getDenom();
		int lcd = lcm(Denom1, Denom2);
		return Rational((a.getNumer() * (lcd / a.getDenom()))
			- (b.getNumer() * (lcd / b.getDenom())), lcd);
	}
	
}

//----------------------------------------------------------------------------

/*operator that multiplies 2 Rational nums*/
Rational operator*(const Rational& a, const Rational& b)
{
	return Rational(a.getNumer() * b.getNumer(),
		a.getDenom() * b.getDenom());
}

//----------------------------------------------------------------------------

/*operator that devides 2 rational nums*/
Rational operator/(const Rational& a, const Rational& b)
{
	return Rational(a.getNumer() * b.getDenom(),
		a.getDenom() * b.getNumer());
}

//----------------------------------------------------------------------------

//assignment operator
Rational& Rational::operator=(const Rational& other)
{
	m_numer = other.getNumer();
	m_denom = other.getDenom();
	
	return *this;
}

//----------------------------------------------------------------------------

/*operator that adds a rational num to another*/
Rational& Rational::operator+=(const Rational& other)
{
	(*this) = (*this) + other;
	return (*this);
}

//----------------------------------------------------------------------------

/*operator that deducts a rational num to another*/
Rational& Rational::operator-=(const Rational& other)
{
	(*this) = (*this) - other;
	return (*this);
}

//----------------------------------------------------------------------------

/*operator that multiplies a rational num to another*/
Rational& Rational::operator*=(const Rational& other)
{
	return (*this) = (*this) * other;
}

//----------------------------------------------------------------------------

/*operator that devides a rational num to another*/
Rational& Rational::operator/=(const Rational& other)
{
	return (*this) = (*this) / other;
}

//----------------------------------------------------------------------------

/*unary operator*/
Rational& Rational::operator+() 
{
	return *this;
}

//----------------------------------------------------------------------------

/*Unary operator*/
Rational& Rational::operator-() 
{
	m_numer *= -1;
	return *this;
}

//----------------------------------------------------------------------------

/*operator that raises a certain power to a rational num*/
Rational operator^(const Rational value, const int power)
{
	if (power == 0)
		return Rational(1,1);

	int iter = power;
	Rational res = value;
	while (iter > 1)
	{
		res *= value;
		iter--;
	}
	return res;
}

//----------------------------------------------------------------------------

/*extraction operator*/
std::ostream& operator<<(std::ostream& out, const Rational& a)
{
	if (a.getDenom() == 1)
		out << a.getNumer();
	else
		out << a.getNumer() << "/" << a.getDenom();
	return out;
}

//----------------------------------------------------------------------------

//least common multiple 
int lcm(int a, int b)
{
    return (a * b) / std::gcd(a, b);
}