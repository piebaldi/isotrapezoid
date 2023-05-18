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
/// @brief to manage an object with the shape of a rectangle
class Rectangle : public Polygon
{
private:
	int length;
	int width;
	float Perimeter() { return (length + width) * 2; }
	float Area() { return length * width; }

public:

	Rectangle();
	Rectangle(int w, int l);
	Rectangle(const Rectangle& source); //const è un salvaguardia
	virtual ~Rectangle();

	Rectangle& operator=(const Rectangle& r);
	bool operator==(const Rectangle& r);

	void Init();
	void Init(const Rectangle& r);
	void Reset();

	void SetDim(int w, int l);
	void SetLength(int l);
	void SetWidth(int w);

	void GetDim(int& w, int& l);
	int GetLength() { return length; }
	int GetWidth() { return width; };

	int GetArea();
	int GetPerimeter();

	void Draw() { cout << "Drawing rectangle..." << endl; }

	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();

};

ostream& operator << (ostream& out, Rectangle& source);
istream& operator >> (istream& in, Rectangle& source);

#endif