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
