//!
//! @file 		Maillage.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the template class Maillage.
//!

#ifndef MAILLAGE_H
#define MAILLAGE_H

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

#include "Triangle.h"

//!
//! @class 		Maillage
//!
//! @brief		Template class creating an 2D-grid.
//!
template <typename T, template <typename, typename> class Container>
// template <typename T, class Container = std::allocator<T> >
class Maillage {

    private :
        Container< Triangle<T>, std::allocator<T> > grid;

    public :
        //=============================================================================
        //                              CONSTRUCTORS
        //=============================================================================
        //! @description    Constructor from heigth, width and origin.
        //! @param m        The width.
        //! @param n        The heigth.
        //! @param origine  The origin on the grid.
        Maillage(int m, int n, const Point<T>& origine);

};

#include "Maillage.tpp"
#endif
