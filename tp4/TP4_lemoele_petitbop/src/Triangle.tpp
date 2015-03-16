//!
//! @file 		Triangle.tpp
//! @author 	lemoele petitbop
//!
//! @brief 		Implementation for the template class Triangle.
//!

#include "Triangle.h"

//=============================================================================
//                              CONSTRUCTORS
//=============================================================================

template <typename T> Triangle<T>::Triangle(Point<T> p1, Point<T> p2, Point<T> p3) :
		point1(p1.x(), p1.y()),
		point2(p2.x(), p2.y()),
		point3(p3.x(), p3.y())
{}

//=============================================================================
//                              ACCESSORS
//=============================================================================
template <typename T> Point<T> Triangle<T>::p1() {
	return point1;
}

template <typename T> Point<T> Triangle<T>::p2() {
	return point2;
}

template <typename T> Point<T> Triangle<T>::p3() {
	return point3;
}