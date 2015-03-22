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
class Maillage {

    private :
        Container< Triangle<T>, std::allocator<T> > grid;
        Point<T> origin;
        int m;
        int n;

    public :
        //=============================================================================
        //                              CONSTRUCTORS
        //=============================================================================
        //! @description    Constructor from heigth, width and origin.
        //! @param m        The width.
        //! @param n        The heigth.
        //! @param origine  The origin on the grid.
        Maillage(int m, int n, const Point<T>& origine);

        typename Container< Triangle<T>, std::allocator<T> >::iterator beginiter(void);

        typename Container< Triangle<T>, std::allocator<T> >::iterator enditer(void);

        void deplacer( double dx, double dy );

        void transformer( double m11, double m12, double m21, double m22 );

};

template <typename T, template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& flux, Maillage<T, Container>& m);

#include "Maillage.tpp"
#endif
