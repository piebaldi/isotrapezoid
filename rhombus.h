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
/// @brief to manage an object with the shape of a rhombus, subclass of Polygon
class Rhombus : public Polygon
{
protected:
	float diagH;
	float diagV;

	/// @name Math functions
	/// @{
	/// Calculates side (Is virtual for other possible subclasses)
	virtual float Side();
	/// Calculates area, it is implemented in the .h because it doesn't call functions 
	virtual float Area() { return (diagH * diagV) / 2; }
	/// Calculates perimeter
	virtual float Perimeter();

public:
	/// @name Constructors/Destructors
	/// @{
	/// Default constructor
	Rhombus();
	/// Constructor with parameters
	Rhombus(float dH, float dV);
	/// Copy contructor
	Rhombus(const Rhombus& r);
	/// Destrcutor (is virtual for other possible subclasses)
	virtual ~Rhombus();
	/// @}

	/// @name Operators
	/// {
	/// Assignment overloading
	Rhombus& operator=(const Rhombus& r);
	/// Comparison overloading
	bool operator==(const Rhombus& r);
	/// @}

	void Init();
	void Init(const Rhombus& source);
	void Reset();
	/// @name Setters
	/// @{
	void SetDim(float dH, float dV);
	void SetDiagH(float dH);
	void SetDiagV(float dV);
	/// @}

	/// @name Getters
	/// @{
	/// Writes them in the given memory locations
	void GetDiagonals(float& dH, float& dV);
	float GetDiagH() { return diagV; }
	float GetDiagV() { return diagH; }
	float GetSide();
	/// @}

	/// @name Console functions	
	/// @{
	void Draw() { cout << "Drawing rhombus..." << endl; }
	void Dump();
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	///@}

};

std::ostream& operator<<(std::ostream& out, Rhombus& source);
std::istream& operator>>(std::istream& in, Rhombus& source);
#endif
