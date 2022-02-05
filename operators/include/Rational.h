#pragma once

//-------------------------------include section------------------------------
#include <iosfwd> 
#include <ostream> 

//--------------------------------class section-------------------------------
class Rational
{
public:
	Rational(int num, int denom);

	int getNumer()const;
	int getDenom()const;

	Rational &operator=(const Rational& );
	Rational &operator+=(const Rational& );
	Rational &operator-=(const Rational& );
	Rational &operator*=(const Rational& );
	Rational &operator/=(const Rational& );

	Rational &operator+();
	Rational &operator-();
	
private:
	int m_numer;
	int m_denom; 
};

//-------------------------------global operator-------------------------------

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

Rational operator^(const Rational, const int);

bool operator==(const Rational& , const Rational&);
bool operator!=(const Rational& , const Rational& );
bool operator>(const Rational&, const Rational& );
bool operator<(const Rational& , const Rational& );
bool operator>=(const Rational& , const Rational& );
bool operator<=(const Rational& , const Rational& );

std::ostream& operator<<(std::ostream&, const Rational&);

int lcm(int, int);