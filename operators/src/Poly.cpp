#pragma once

//-------------------------------include section------------------------------
#include "poly.h"

//--------------------------------func section--------------------------------
// defaultive c-tor
Poly::Poly()
	:m_polyList(nullptr)
{
	m_polyList = m_polyList->createNode(Rational(0,1), 1);
	
}

//----------------------------------------------------------------------------
// d-tor. it sends the poly list to free memory
Poly::~Poly()
{
	m_polyList->deleteList(m_polyList);
}

//----------------------------------------------------------------------------
// a c-tor that creates a polynom from a scalar (free element)
Poly::Poly(Rational scalar)
	:m_polyList(nullptr)
{
	m_polyList = m_polyList->createNode(scalar, 0);
}

//----------------------------------------------------------------------------
// a c-tor that creates a monom
Poly::Poly(int pow, Rational coeff)
	:m_polyList(nullptr)
{
	m_polyList = m_polyList->createNode(coeff, pow);
}

//----------------------------------------------------------------------------
// c-tor that recieves a vector with rational coefficient and a pointer
Poly::Poly(const std::vector<Rational>& coeffs): m_polyList(nullptr)
{
	List* currNode = nullptr;
	for (int i = 0, pow = int(coeffs.size() - 1);
		i < int(coeffs.size());
		i++, pow--)
	{
		if (coeffs[i] != Rational(0, 1))
		{
			if (m_polyList == nullptr)
				currNode = m_polyList = m_polyList->createNode(coeffs[i], pow);
			else
			{
				currNode->m_next = currNode->createNode(coeffs[i], pow);
				currNode = currNode->m_next;
			}
		}
	}
}

//----------------------------------------------------------------------------

/*c-tor that recieves a pointer*/
Poly::Poly(List* ptr) :
	m_polyList(ptr){}

//----------------------------------------------------------------------------

/*a function that returns the degree of a polynom which is the largest degree
of a certain member of a polynom*/
int Poly::deg() const
{
	if (m_polyList == nullptr)
		return -1;
	else
		return m_polyList->m_power;
}

//----------------------------------------------------------------------------

/*copy constructor*/
Poly::Poly(const Poly& other)
{
	this->m_polyList = nullptr;
	List* node = other.getHead();
	while (node)
	{
		updateList(node->m_coeff, node->m_power);
		node = node->m_next;
	}
}

//----------------------------------------------------------------------------

/*operator that adds 2 polynomials*/
Poly operator+(const Poly& a, const Poly& b)
{
	Poly newPoly(nullptr);
	List* aNode = a.getHead();
	List* bNode = b.getHead();

	while (aNode != nullptr || bNode != nullptr)
	{
		if (aNode != nullptr &&
			(bNode == nullptr || aNode->m_power > bNode->m_power))
		{
			newPoly.updateList(aNode->m_coeff, aNode->m_power);

			aNode = aNode->m_next;
		}
		else if (bNode != nullptr &&
			(aNode == nullptr || aNode->m_power < bNode->m_power))
		{
			newPoly.updateList(bNode->m_coeff, bNode->m_power);
			bNode = bNode->m_next;
		}
		else if (bNode->m_coeff + aNode->m_coeff != 0)
		{
			newPoly.updateList(aNode->m_coeff + bNode->m_coeff,
				bNode->m_power);
			bNode = bNode->m_next;
			aNode = aNode->m_next;
		}
		else
		{
			bNode = bNode->m_next;
			aNode = aNode->m_next;
		}
	}
	return newPoly;
}

//----------------------------------------------------------------------------

/*operator that deducts 2 polynomials*/
Poly operator-(const Poly& a, const Poly& b)
{
	Poly newPoly(nullptr);
	newPoly = a + b * Rational(-1, 1);
	return newPoly;
}

//----------------------------------------------------------------------------

/*operator that multiplies 2 polynomials*/
Poly operator*(const Poly& a, const Poly& b)
{
	Poly newPoly(nullptr);
	List* aNode = a.getHead();
	List* bNode = b.getHead();

	while (aNode != nullptr)
	{
		Poly tempPoly(nullptr);
		if (newPoly.getHead() == nullptr)
			newPoly = tempPoly;

		while (bNode != nullptr)
		{
			int newPow = aNode->m_power + bNode->m_power;
			Rational newCoeff = aNode->m_coeff * bNode->m_coeff;
			tempPoly.updateList(newCoeff, newPow);
			bNode = bNode->m_next;
		}
		newPoly += tempPoly;
		aNode = aNode->m_next;
		bNode = b.getHead();
	}
	return newPoly;
}

//----------------------------------------------------------------------------

/*operator that devides 2 polynomials using long division and returns the 
number of times b is found in a*/
Poly operator/(const Poly& a, const Poly& b)
{
	Poly newPoly(nullptr);
	Poly poly1 = a;
	Poly poly2 = b;

	List* aNode = a.getHead();
	List* bNode = b.getHead();

	if (isEqual(aNode,  bNode))
		return Rational(1, 1);

	bNode = b.getHead();
	while (bNode != NULL)
	{
		if ((poly1.getHead()->m_power < poly2.getHead()->m_power))
			break;
		Poly tempPoly(poly1.getHead()->m_power - poly2.getHead()->m_power,
			poly1.getHead()->m_coeff / poly2.getHead()->m_coeff);
		newPoly += tempPoly;
		poly1 = poly1 - tempPoly * poly2;

		bNode = bNode->m_next;
	}

	return newPoly;
}

//----------------------------------------------------------------------------

/*operator that returns the remainder after the devision of 2 polynomials*/
Poly operator%(const Poly& a, const Poly& b)
{
	Poly poly1 = a;
	Poly poly2 = b;

	List* aNode = a.getHead();
	List* bNode = b.getHead();

	if (isEqual(aNode, bNode))
		return Rational(0, 1);

	bNode = b.getHead();
	while (bNode != NULL)
	{
		if ((poly1.getHead()->m_power < poly2.getHead()->m_power))
			break;
		Poly tempPoly(poly1.getHead()->m_power - poly2.getHead()->m_power,
			poly1.getHead()->m_coeff / poly2.getHead()->m_coeff);
		poly1 = poly1 - tempPoly * poly2;

		bNode = bNode->m_next;
	}

	return poly1;
}

//----------------------------------------------------------------------------

/*a func that computes gcd*/
Poly gcd(Poly a, Poly b)
{
	Poly poly1 = a;
	Poly poly2 = b;

	while (poly1 % poly2 != 0)
	{
		Poly remainder = poly1 % poly2;
		poly1 = poly2;
		poly2 = remainder;
	}
	return poly2;
}

//----------------------------------------------------------------------------

/*a func that checks if 2 polynomials are identical or not*/
bool isEqual(List* aNode, List* bNode)
{
	bool equal = false;
	 while (aNode != NULL && bNode != NULL)
	{
		if ((aNode->m_coeff == bNode->m_coeff)
			&& aNode->m_power == bNode->m_power)
			equal = true;
		else
		{
			equal = false;
			break;
		}

		aNode = aNode->m_next;
		bNode = bNode->m_next;
	}
	return (equal ? true : false);
}

//----------------------------------------------------------------------------

/*assignment operator*/
Poly& Poly::operator=(const Poly& other)
{
	Poly temp(other);
	std::swap(temp.m_polyList, m_polyList);
	return (*this);
}

//----------------------------------------------------------------------------

/*operator that adds a poly to the other*/
Poly& Poly::operator+=(const Poly& other)
{
	(*this) = (*this) + other;
	return (*this);
}

//----------------------------------------------------------------------------

/*operator that deducts a poly to the other*/
Poly& Poly::operator-=(const Poly& other)
{
	(*this) = (*this) - other;
	return (*this);
}

//----------------------------------------------------------------------------

/*operator that multiplies  a poly to the other*/
Poly& Poly::operator*=(const Poly& other)
{
	(*this) = (*this) * other;
	return (*this);
}

//----------------------------------------------------------------------------

/*operator that multiplies a poly with a scalar*/
Poly operator*(const Poly& poly, Rational scalar)
{
	Poly tempPoly(scalar);
	tempPoly *= poly;
	return tempPoly;
}

//----------------------------------------------------------------------------

/*operator that multiplies a scalar with a poly*/
Poly operator*(Rational scalar, const Poly& poly)
{
	Poly tempPoly(scalar);
	tempPoly *= poly;
	return tempPoly;
}

//----------------------------------------------------------------------------

//operator that compares the degree of 2 polynomials 
bool operator==(const Poly& a, const Poly& b)
{
	if (a.deg() == b.deg())
		return true;
	return false;
}

//----------------------------------------------------------------------------

/*this function check if 2 polynomials are different according to their 
degree*/
bool operator!=(const Poly& a, const Poly& b)
{
	return !(a == b);
}

//----------------------------------------------------------------------------

/*operator that recieves a value and returns the value of the polynom when the 
value recieved is subsituded in the polynom */
Rational Poly::operator()(Rational value) const
{
	List* polyList = this->getHead();

	Rational res = Rational(0,1);

	while (polyList)
	{
		res += polyList->m_coeff * (value ^ polyList->m_power);
		polyList = polyList->m_next;
	}

	return res;
}

//----------------------------------------------------------------------------

/*operator that recieves an integer as a power and returns the value of the 
coefficient that has that power*/
Rational Poly::operator[](int power) const
{
	List* polyList = this->getHead();

	Rational wanted = Rational(0, 1);
	bool found = false;

	while (polyList)
	{
		if (polyList->m_power == power)
		{
			found = true;
			wanted = polyList->m_coeff;
		}

		polyList = polyList->m_next;
	}

	if (found)
		return wanted;
	else
	{
		std::cout << "not found\n";
		return Rational(0,1);
	}
}

//----------------------------------------------------------------------------

/*extraction operator*/
std::ostream& operator<<(std::ostream& out, const Poly& poly)
{
	List* node = poly.getHead();

	if (node == nullptr)
	{
		out << 0 << std::endl;
		return out;
	}

	while (node)
	{
		if (node->m_power == 0)
			out << node->m_coeff;
		else
			out << node->m_coeff << "*x^" << node->m_power;
		if(node->m_next != nullptr)
			if (node->m_next->m_coeff > Rational(0,1))
				out << "+";
		
		node = node->m_next;
	}
	
	out << "\n";
	return out;
}

//----------------------------------------------------------------------------

/*thhis func adds a node to the linked list*/
void Poly::updateList(Rational coeff, int power)
{
	if (coeff != Rational(0, 1)) 
	{
		List* newNode = nullptr;
		newNode = newNode->createNode(coeff, power);
		
		if (m_polyList == nullptr) {
			m_polyList = newNode;
			return;
		}

		List* temp = m_polyList;
		while (temp->m_next != nullptr) {
			temp = temp->m_next;
		}

		temp->m_next = newNode;
	}
}

//----------------------------------------------------------------------------

/*this function sets the pointer to the head of the list*/
void Poly::setHead(List* head) 
{
	m_polyList = head;
}

//----------------------------------------------------------------------------

/*this function returns the head of the list*/
List* Poly::getHead() const
{
	return m_polyList;
}