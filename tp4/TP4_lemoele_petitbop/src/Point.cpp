//!
//! @file 		Point.cpp
//! @author 	lemoele petitbop
//!
//! @brief 		File for the class Point.
//!

#include "Point.h"

//=============================================================================
//								CONSTRUCTORS
//=============================================================================
Point::Point(double x, double y){
	absciss = x;
	ordinate = y;
}

//=============================================================================
//                              ACCESSORS
//=============================================================================
double Point::x() {
	return absciss;
}

double Point::y() {
	return ordinate;
}