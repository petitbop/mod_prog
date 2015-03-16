//!
//! @file 		Triangle.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the template class Triangle.
//!

#ifndef TRIANGLE_H
#define TRIANGLE_H

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

#include "Point.h"

//!
//! @class 		Triangle
//!
//! @brief		Template class creating an triangle, formed by 3 points.
//!
template <typename T> class Triangle {

	private :
        Point<T> point1;
        Point<T> point2;
        Point<T> point3;

    public :

        //=============================================================================
        //                              CONSTRUCTORS
        //=============================================================================
        //! @description    Default constructor.
        Triangle(Point<T> p1, Point<T> p2, Point<T> p3);

        //=============================================================================
        //                              ACCESSORS
        //=============================================================================
        //! @description    Accessor to the first point.
        //! @return         The first point of the triangle.
        Point<T> p1();

        //! @description    Accessor to the second point.
        //! @return         The second point of the triangle.
        Point<T> p2();

        //! @description    Accessor to the third point.
        //! @return         The third point of the triangle.
        Point<T> p3();


};

#include "Triangle.tpp"
#endif