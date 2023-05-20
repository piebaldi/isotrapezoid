/// @file rectangle.cpp
/// @@brief class Rectangle: implementation of methods
///
///	Details.

#include <iostream>
#include "rectangle.h"

/// @brief default constructor 
Rectangle::Rectangle() {

	cout << "Rectangle - constructor - default" << endl;
	Init();

}

/// @brief constructor 
/// @param w width in pixels
/// @param h length in pixels
Rectangle::Rectangle(int w, int l) {

	Init();
	cout << "Rectangle - constructor" << endl;

	if (w <= 0)
		ErrorMessage("constructor: width should be > 0");
	else
		width = w;

	if (l <= 0)
		ErrorMessage("constructor: length should be > 0");
	else
		length = l;



}

/// @brief destructor 
Rectangle::~Rectangle() {

	cout << "Rectangle - destructor" << endl;
	Reset();

}

/// @brief Initializer function.
void Rectangle::Init() {
	length = 1;
	width = 1;
}

/// @brief Reset function.
void Rectangle::Reset() {
	//memory dealloc...
	Init();
}

/// @brif Copy initialization function
void Rectangle::Init(const Rectangle& r) {

	Reset();
	length = r.length;
	width = r.width;
}

/// @brief set width of the object
/// @param w width in pixels
void Rectangle::SetWidth(int w) {

	if (w < 0)
		ErrorMessage("width should be > 0");
	else
		width = w;

}

/// @brief set length of the object
/// @param l length in pixels
void Rectangle::SetLength(int l) {

	if (l < 0)
		ErrorMessage("length should be > 0");
	else
		length = l;
}

/// @brief set width and length of the object
/// @param w width in pixels
/// @param l length in pixels
void Rectangle::SetDim(int w, int l) {

	SetWidth(w);
	SetLength(w);
}

///@brief copy constructor
Rectangle::Rectangle(const Rectangle& source) {

	cout << "Copy constructor called" << endl;
	Init(source);
}


/// @brief overload of operator "=", copies width and length
/// @param r Right operand
/// @return Left operand
Rectangle& Rectangle::operator=(const Rectangle& r) {
	Init(r);
	return *this; //ritorna l'operatore a sinistra (this è un puntatore), 
				  //è evidente il senso con degli = a catena
}

/// @brief overload of operator "==", compares width and length
/// @param r right operand
/// @return left operand
bool Rectangle::operator==(const Rectangle& r) {
	if (r.width == width && r.length == length)
		return true;
	return false;
}

/*
/// @brief set length of the object
/// @param l length in pixels
int Rectangle::GetLength() {

	return length;

}
*/

/// @brief set width and length of the object
/// @param w width in pixels
/// @param l length in pixels
void Rectangle::GetDim(int& w, int& l) {

	w = width;
	l = length;
}

/// @brief Computes area
/// @return Area
int Rectangle::GetArea() {

	return Area();
}

/// @brief Computes perimeter
/// @return perimeter
int Rectangle::GetPerimeter() {

	return Perimeter();
}

/// @brief write an error message
/// @param string message to be printed
void Rectangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Rectangle --";
	cout << string << endl;
}

/// @brief write a warning message
/// @param string mesdsage to be printed
void Rectangle::WarningMessage(const char* string) {

	cout << endl << "WARNING --Rectangle--";
	cout << string << endl;
}

/// @brief Rectangle dump
void Rectangle::Dump() {

	Polygon::Dump();
	cout << "Rectangle dump" << endl;
	cout << "lenght: " << length << "\t";
	cout << "width: " << width << endl;
}

/// @brief Overload of operator <<
std::ostream& operator << (std::ostream& out, Rectangle& source) {

	source.Dump();
	return out;
}

/// @brief Overload of operator >>
std::istream& operator >> (std::istream& in, Rectangle& source) {

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

	source.SetLength(x);
	in >> x;

	if (!cin) {
		cout << "\ninvalid argument (1 will instead be input)\n";
		x = 1;
		cin.clear();
	}

	cin.ignore(10, '\n');
	source.SetWidth(x);
	return in;
}