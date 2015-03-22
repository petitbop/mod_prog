/* vim: set filetype=cpp: */
//!
//! @file 		Point.tpp
//! @author 	lemoele petitbop
//!
//! @brief 		Implementation for the template class Point.
//!

#include "Point.h"

//=============================================================================
//								CONSTRUCTORS
//=============================================================================
template <typename T> Point<T>::Point(T x, T y){
	absciss = x;
	ordinate = y;
}

template <typename T> Point<T>::Point(Point<T> const & p){
	absciss = p.x();
	ordinate = p.y();
}

//=============================================================================
//                              ACCESSORS
//=============================================================================
template <typename T> T Point<T>::x() const {
	return absciss;
}

template <typename T> T Point<T>::y() const {
	return ordinate;
}

template <typename T> Point<T> Point<T>::translate(T dx, T dy) const{
    return Point(this->x() + dx, this->y() + dy);
}

template <typename T> void Point<T>::deplacer(double dx, double dy){
    this->absciss += dx;
    this->ordinate += dy;
}

template <typename T> void Point<T>::transformer(double m11, double m12, double m21, double m22) {
	T x = this->x();
	T y = this->y();
    this->absciss = x*m11 + y*m21;
    this->ordinate = x*m12 + y*m22;
}

template <typename T> void Point<T>::tourner( double angle, const Point<T>& pt ) {
	T x = this->x();
	T y = this->y();
	T xp = pt.x();
	T yp = pt.y();
	this->absciss = (x-xp)*cos(angle) - (y-yp)*sin(angle) + xp;
	this->ordinate = (x-xp)*sin(angle) + (y-yp)*cos(angle) + yp;
}

template <typename T>
std::ostream& operator<<(std::ostream& flux, Point<T>const& p){
    flux << p.x() << " " << p.y() << std::endl;
    return flux;
}

template <typename T>
bool operator==(Point<T> p1, Point<T>const& p2){
    return (p1.x() == p2.x() && p1.y() == p2.y());
}
