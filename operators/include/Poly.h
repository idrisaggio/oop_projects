#pragma once

//-------------------------------include section------------------------------
#include <iosfwd> 
#include <ostream> 
#include <iostream>
#include <vector>
#include <cmath>

#include "list.h"
#include "Rational.h"

//--------------------------------using section-------------------------------
using std::vector;

//--------------------------------class section-------------------------------
class Poly
{

public:

    Poly();//default 0 
    ~Poly();//d-tor
    Poly(Rational);//scalar
    Poly(int, Rational);//monome
    Poly(const std::vector<Rational>&);//parameter rational
    
    Poly(List*);//help c-tor
    Poly(const Poly&);

    Poly& operator=(const Poly& other);
    Poly& operator+=(const Poly& other);
    Poly& operator-=(const Poly& other);
    Poly& operator*=(const Poly& other);
    
    Rational operator()(Rational)const;
    Rational operator[](int)const;

    void updateList(Rational, int);
    List* getHead()const;
    int deg()const;
    void setHead(List*);

private:
    List* m_polyList;
};

Poly gcd(Poly, Poly);

Poly operator+(const Poly&, const Poly&);
Poly operator-(const Poly&, const Poly&);
Poly operator*(const Poly&, const Poly&);
Poly operator/(const Poly&, const Poly&);
Poly operator%(const Poly&, const Poly&);

Poly operator*(const Poly&, Rational);
Poly operator*(Rational, const Poly&);

bool operator==(const Poly&, const Poly&);
bool operator!=(const Poly&, const Poly&);

bool isEqual(List*, List*);

std::ostream& operator<<(std::ostream&, const Poly&);