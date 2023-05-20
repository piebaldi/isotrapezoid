/// @file IsoTrapezoid.cpp
/// @brief Implementation of subclass IsoTrapezoid

#include "IsoTrapezoid.h"
#include <iostream>
#include <cmath>

///@brief Initializer function
void IsoTrapezoid::Init() {
	topSide = bottomSide = height = 1;
}

/// @brief Reset fucntion
void IsoTrapezoid::Reset() {
	//deallocs memory...
	Init();
}
/// @brief Copy initializer function
/// @param source Is from where the params are copied
void IsoTrapezoid::CopyInit(const IsoTrapezoid& source) {
	Reset();
	topSide = source.topSide;
	bottomSide = source.bottomSide;
	height = source.height;
}

/// @brief Calculates side of trapezoid
/// @return Side of trapezoid 
float IsoTrapezoid::Side() {
	float t_base = (bottomSide - topSide) / 2;
	return sqrt((height * height) + (t_base * t_base));
}

/// @brief Default constructor
IsoTrapezoid::IsoTrapezoid() {
	Init();
	cout << "Isotrapezoid default constructor" << endl;
}

/// @brief Params constructor
IsoTrapezoid::IsoTrapezoid(float t, float b, float h) {
	Init();
	SetParams(t, b, h);
	cout << "Isotrapezoid Param costructor" << endl;
}

///@brief copy constructor
///@param source Object to be copied
IsoTrapezoid::IsoTrapezoid(const IsoTrapezoid& source) {
	CopyInit(source);
	cout << "Isotrapezoid copy constr " << endl;
}

///@brief Destructor
IsoTrapezoid::~IsoTrapezoid() {
	Reset();
	cout << "isotrapezoid Destructor" << endl;
}

///@brief Getters for all parameters
/// @param mem_t memory for top side
/// @param mem_b memory for bottom side
/// @param mem_h memory for height
void IsoTrapezoid::GetParams(float& mem_t, float& mem_b, float& mem_h) {
	mem_t = topSide;
	mem_b = bottomSide;
	mem_h = height;
}

/// @brief Setter for top side
/// @param new_t is new value of top side (must be > 0)
void IsoTrapezoid::SetTopSide(float new_t) {
	if (new_t <= 0)
		ErrorMessage("top side is less than/ equal to 0");
	else
		topSide = new_t;


}

/// @brief Setter for bottom side
/// @param new_b is new value of bottom side (must be > 0)
void IsoTrapezoid::SetBottomSide(float new_b) {
	if (new_b <= 0)
		ErrorMessage("b side is less than/ equal to 0");

	else
		bottomSide = new_b;
}

/// @brief Setter for height
/// @param new_h is new value of height (must be > 0)
void IsoTrapezoid::SetHeight(float new_h) {
	if (new_h <= 0)
		ErrorMessage("height is less than/ equal to 0");
	else
		height = new_h;
}

/// @brief Setter for all params
void IsoTrapezoid::SetParams(float new_t, float new_b, float new_h) {
	SetTopSide(new_t);
	SetBottomSide(new_b);
	SetHeight(new_h);
}

/// @brief write an error message 
/// @param string message to be printed
void IsoTrapezoid::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- IsoTrapezoid --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void IsoTrapezoid::WarningMessage(const char* string) {

	cout << endl << "WARNING -- IsoTrapezoid --";
	cout << string << endl;
}

/// @brief Dump function
void IsoTrapezoid::Dump() {

	Polygon::Dump();
	cout << "top side: " << topSide << "\t";
	cout << "bottom side: " << bottomSide << "\t";
	cout << "height: " << height << endl;
}

/// @brief Overload of assignment operator
/// @param r right operand
/// @return left operand
IsoTrapezoid& IsoTrapezoid::operator= (const IsoTrapezoid& r) {
	CopyInit(r);
	return *this;
}

///@brief overload of == operator
/// @param r right operanf
/// @return left operand
bool IsoTrapezoid::operator == (const IsoTrapezoid& r) {
	if (topSide == r.topSide && bottomSide == r.bottomSide && height == height)
		return true;
	return false;
}

/// @brief overload of << operator
/// @param r Right operand
/// @param out Console
/// @return console type to concatenate
ostream& operator << (ostream& out, IsoTrapezoid& r) {
	r.Dump();
	return out;
}

/// @brief overload of >> operator
/// @param r Right operand
/// @param out Console
/// @return console type to concatenate
istream& operator >> (istream& in, IsoTrapezoid& r) {
	float x;
	in >> x;
	//Catches wrong arguments by checking the fail bit of cin ( is 1 when
	//it tries to input incompatible types, like char and int)
	if (!cin) {
		cout << "invalid argument (1 will instead be input)\n";
		x = 1;
		cin.clear(); //resets the fail bit
	}
	//ignore the possible wrong arguments and newline (uo to 10)
	cin.ignore(10, '\n');


	r.SetTopSide(x);
	in >> x;

	if (!cin) {
		cout << "invalid argument (1 will instead be input)\n";
		x = 1;
		cin.clear();
	}
	cin.ignore(10, '\n');


	r.SetBottomSide(x);
	in >> x;

	if (!cin) {
		cout << "invalid argument (1 will instead be input)\n";
		x = 1;
		cin.clear();
	}
	cin.ignore(10, '\n');


	r.SetHeight(x);
	return in;
}

/// @brief Calculates area
/// @return Area
float IsoTrapezoid::Area() {
	return ((topSide + bottomSide) * height) / 2;
}

/// @brief Calculates perimeter
/// @return Perimeter
float IsoTrapezoid::Perimeter() {
	return (topSide + bottomSide + (Side() * 2));
}
