/* vim: set filetype=cpp: */
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
		point1(p1),
		point2(p2),
		point3(p3)
{
}

//=============================================================================
//                              ACCESSORS
//=============================================================================
template <typename T> Point<T> Triangle<T>::p1() const {
	return point1;
}

template <typename T> Point<T> Triangle<T>::p2() const {
	return point2;
}

template <typename T> Point<T> Triangle<T>::p3() const {
	return point3;
}

template <typename T> void Triangle<T>::deplacer(double dx, double dy){
	this->p1().deplacer(dx, dy);
	this->p2().deplacer(dx, dy);
	this->p3().deplacer(dx, dy);
}

template <typename T> void Triangle<T>::transformer(double m11, double m12, double m21, double m22) {
	this->p1().transformer(m11, m12, m21, m22);
	this->p2().transformer(m11, m12, m21, m22);
	this->p3().transformer(m11, m12, m21, m22);
}

template <typename T>
std::ostream& operator<<(std::ostream& flux, Triangle<T>const& t){
    flux << t.p1();
    flux << t.p2();
    flux << t.p3();
    flux << t.p1();
    return flux;
}

