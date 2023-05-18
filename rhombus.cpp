/// @file rhombus.cpp
/// @brief Implementation of the class rhombus.
/// Detaila
///

#include "rhombus.h"
#include <iostream>
#include <cmath>

using namespace std;

/// @brief Default constructor
Rhombus::Rhombus()
{
	Init();
	cout << "Rhombus default constructor - invoked" << endl;
}

/// @brief  Overload of constructor
/// @param dH  Horizontal diagonal
/// @param dV  Vertical diagonal
Rhombus::Rhombus(float dH, float dV)
{
	SetDiagH(dH);
	SetDiagV(dV);
	cout << "Rhombus param constructor - invoked" << endl;
}

/// @brief Copy constructor
/// @param source Object from which to copy 
Rhombus::Rhombus(const Rhombus& r)
{
	cout << "Rhombus Copy constructor - invoked" << endl;
	Init(r);
}

/// @brief Destructor
Rhombus::~Rhombus()
{
	Reset();
	cout << "Rhombus destructor - invoked" << endl;
}

/// @brief Overload of "=" operator, copies the diagonals of two objects
/// @param r Right operand
/// @return Left operand
Rhombus& Rhombus::operator=(const Rhombus& r)
{
	Init(r);
	return *this;
}

/// @brief Overload of "==" operator, checks if the diagonals of two objects are equal
/// @param r Right operand
/// @return Left operand
bool Rhombus::operator==(const Rhombus& r)
{
	if (diagH == r.diagH && diagV == r.diagV)
		return true;
	return false;
}

/// @brief Object initializer
void Rhombus::Init()
{
	diagH = 1;
	diagV = 1;
}

/// @brief Copy object initializer
/// @oaram source Object to copy from
void Rhombus::Init(const Rhombus& source)
{
	Reset();
	diagH = source.diagH;
	diagV = source.diagV;
}

/// @brief Deallocs object memory and initializes it
void Rhombus::Reset()
{
	//dealloc pointers...
	Init();
}

/// @brief Dump of rhombus, shows diagonals
void Rhombus::Dump()
{
	Polygon::Dump();
	cout << "Dump of Rhombus" << endl;
	cout << "diagH = " << diagH << "\tdiagV = " << diagV << endl;
}

/// @brief Modify a new horizontal diagonal
/// @param dH New value of horizontal diagonal
void Rhombus::SetDiagH(float dH)
{
	if (dH < 0)
		ErrorMessage("Cannot set a diagonal to a negative number.");
	else if (dH == 0)
		ErrorMessage("Cannot set a diagonal to zero.");
	else
		diagH = dH;
}

/// @brief Modify a new vertical diagonal
/// @param dV New value of vertical diagonal
void Rhombus::SetDiagV(float dV)
{
	if (dV < 0)
		ErrorMessage("Cannot set a diagonal to a negative number.");
	else if (dV == 0)
		ErrorMessage("Cannot set a diagonal to zero.");
	else
		diagV = dV;
}

/// @brief Modify both horizontal and vertical diagonals
/// @param dH New value of horizontal diagonal
/// @param dV New value of vertical diagonal
void Rhombus::SetDim(float dH, float dV)
{
	SetDiagH(dH);
	SetDiagV(dV);
}
/*
/// @brief Gets the value of horizontal diagonal
/// @return The value of horizontal diagonal
float Rhombus::GetDiagH()
{
	return diagH;
}

/// @brief Gets the value of vertical diagonal
/// @return The value of vertical diagonal
float Rhombus::GetDiagV()
{
	return diagV;
}
*/
/// @brief Writes the value of both diagonal in two memory locations
/// @param mem_dH memory location of horizontal diagonal
/// @param mem_dV memory location of vertical diagonal
void Rhombus::GetDiagonals(float& mem_dH, float& mem_dV)
{
	mem_dH = diagH;
	mem_dV = diagV;
}

/// @brief Computes the side of the rhombus given the two diagonals
/// @return Side
float Rhombus::Side()
{
	float x = (diagH / 2) * (diagH / 2) + (diagV / 2) * (diagV / 2);
	return sqrt(x);
}

///@brief Returns the side of rhombus
///@return Side of rhombus
float Rhombus::GetSide()
{
	return Side();
}

/// @brief Computes the permieter of a rhombus given the two diagonals
/// @return Perimeter
float Rhombus::Perimeter()
{
	return Side() * 4;
}
/*
/// @brief Computes the area of a rhombus
/// @return Area
float Rhombus::Area()
{
	return (diagH * diagV) / 2;
}
*/
/// @brief Error message function
/// @param string Specific string error 
void Rhombus::ErrorMessage(const char* string) {
	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;
}

/// @brief Warning message function
/// @param string Specific string warning
void Rhombus::WarningMessage(const char* string) {
	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;
}

/// @brief Overload of operator <<. Dumps object on stream.
ostream& operator << (ostream& out, Rhombus& source)
{
	source.Dump();
	return out;
}

/// @brief Overload of operator >>. Writes diagH and diagV subsequently.
istream& operator >> (istream& in, Rhombus& source)
{
	float x;
	in >> x;
	source.SetDiagH(x);
	in >> x;
	source.SetDiagV(x);
	return in;
}