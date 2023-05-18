/// @file rhombus.h
/// @brief Declaration of the class Rhombus
///
///	Details.
///


#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "poligono.h"
#include <iostream>

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
class Rhombus : public Polygon
{
protected:
	float diagH;
	float diagV;
	float Side();
	float Area() { return (diagH * diagV) / 2; }
	float Perimeter();

public:
	Rhombus();
	Rhombus(float dH, float dV);
	Rhombus(const Rhombus& r);

	virtual ~Rhombus();

	Rhombus& operator=(const Rhombus& r);
	bool operator==(const Rhombus& r);

	void Init();
	void Init(const Rhombus& source);
	void Reset();

	void SetDim(float dH, float dV);
	void SetDiagH(float dH);
	void SetDiagV(float dV);

	void GetDiagonals(float& dH, float& dV);
	float GetDiagH() { return diagV; }
	float GetDiagV() { return diagH; }
	float GetSide();

	void Draw() { cout << "Drawing rhombus..." << endl; }

	void Dump();
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);

};

std::ostream& operator<<(std::ostream& out, Rhombus& source);
std::istream& operator>>(std::istream& in, Rhombus& source);
#endif