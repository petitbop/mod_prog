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
        //! @description 	Default constructor.
        Point(T x, T y);

        //=============================================================================
        //                              ACCESSORS
        //=============================================================================
        //! @description    Default constructor.
        //! @return         The absciss of the point.
        T x();

        //! @description    Default constructor.
        //! @return         The ordinate of the point.
        T y();

};

#include "Point.tpp"
#endif
