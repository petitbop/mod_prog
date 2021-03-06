//!
//! @file 		Point.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the template class Point.
//!

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <math.h>

//!
//! @class 		Point
//!
//! @brief		Class creating an 2D-point.
//!
template <typename T> class Point {

	private :
        T absciss;
        T ordinate;

    public :

		//=============================================================================
    	//								CONSTRUCTORS
		//=============================================================================
        //! @description 	Constructor from coordinates.
        //! @param x        The absciss.
        //! @param y        The ordinate.
        Point(T x, T y);

        Point(Point<T> const & p);

        //=============================================================================
        //                              ACCESSORS
        //=============================================================================
        //! @description    Accessor to the absciss.
        //! @return         The absciss of the point.
        T x() const;

        //! @description    Accessor to the ordinate.
        //! @return         The ordinate of the point.
        T y() const;

        Point<T> translate(T dx, T dy) const;

        void deplacer( double dx, double dy );

        void transformer( double m11, double m12, double m21, double m22 );

        void tourner( double angle, const Point<T>& pt );

};

template <typename T>
std::ostream& operator<<(std::ostream& flux, Point<T>const& m);

template <typename T>
bool operator==(Point<T> const& s1, Point<T> const& s2);

#include "Point.tpp"
#endif
