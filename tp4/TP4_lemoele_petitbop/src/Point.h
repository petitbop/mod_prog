//!
//! @file 		Point.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the class Darray
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
class Point {

	private :
        double absciss;
        double ordinate;

    public :

		//=============================================================================
    	//								CONSTRUCTORS
		//=============================================================================
        //! @description 	Default constructor.
        Point(double x, double y);

        //=============================================================================
        //                              ACCESSORS
        //=============================================================================
        //! @description    Default constructor.
        //! @return         The absciss of the point.
        double x();

        //! @description    Default constructor.
        //! @return         The ordinate of the point.
        double y();

};

#endif
