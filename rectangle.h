/*! \file rectangle.h
	\brief Declaration of the class Rectangle

	Details.
*/


#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "poligono.h"
#include <iostream>

using namespace std;

/// @class Rectangle
/// @brief to manage an object with the shape of a rectangl, subclass of Polygon
class Rectangle : public Polygon
{
private:
	int length;
	int width;

	/// @name Math functions
	/// @{
	/// Calculates perimeter (is virtua for other possible subclasses)
	virtual float Perimeter() { return (length + width) * 2; }
	/// Calculates area (is virtual for other possible subclasses)
	virtual float Area() { return length * width; }
	/// @}
public:

	/// @name Constructors/Destructors
	/// @{
	Rectangle();
	Rectangle(int w, int l);
	Rectangle(const Rectangle& source); //const è un salvaguardia
	/// Destructor (is virtual for other possbile subclasses)
	virtual ~Rectangle();
	/// @}

	/// @name Operators
	/// {
	/// Assignment overloading
	Rectangle& operator=(const Rectangle& r);
	/// Comparison overloading
	bool operator==(const Rectangle& r);
	/// @}

	/// @name Handlers
	/// @{
	void Init();
	void Init(const Rectangle& r);
	void Reset();
	/// @}

	/// @name Setters
	/// @{
	void SetDim(int w, int l);
	void SetLength(int l);
	void SetWidth(int w);
	/// @}

	/// @name Getters
	/// @{
	/// Returns parameters in given memory allocations 
	void GetDim(int& w, int& l);
	int GetLength() { return length; }
	int GetWidth() { return width; };
	int GetArea();
	int GetPerimeter();
	/// @}

	/// @name Console functions
	/// @{
	void Draw() { cout << "\nDrawing rectangle..." << endl; }

	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

/// @name IN/OUT operators
/// @{
ostream& operator << (ostream& out, Rectangle& source);
istream& operator >> (istream& in, Rectangle& source);
/// @}

#endif