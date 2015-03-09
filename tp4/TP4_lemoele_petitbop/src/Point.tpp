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

//=============================================================================
//                              ACCESSORS
//=============================================================================
template <typename T> T Point<T>::x() {
	return absciss;
}

template <typename T> T Point<T>::y() {
	return ordinate;
}