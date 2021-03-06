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

#include "Segment.h"
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
        std::vector< Segment<T> > endpoints;
        Point<T> origin;
        int m;
        int n;

        bool is_adjacent(const Maillage<T, Container>& m, int& common);
        void set_endpoints(Point<T> A, Point<T> B, Point<T> C, Point<T> D);

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

        void fusionner(Maillage<T, Container>& m);

        void deplacer( double dx, double dy );

        void transformer( double m11, double m12, double m21, double m22 );

        void tourner( double angle, const Point<T>& pt );

};

template <typename T, template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& flux, Maillage<T, Container>& m);

#include "Maillage.tpp"
#endif
