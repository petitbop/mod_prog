//!
//! @file 		Maillage.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the template class Maillage.
//!

#ifndef SEGMENT_H
#define SEGMENT_H

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
#include <vector>

#include "Point.h"

//!
//! @class 		Maillage
//!
//! @brief		Template class creating an 2D-grid.
//!
template <typename T>
class Segment {

    private :
        std::vector< Point<T> > endpoints;

    public :
        Segment(Point<T> const& p1, Point<T> const& p2);
        Point<T> p1(void) const;
        Point<T> p2(void) const;
        Point<T>& p1(void);
        Point<T>& p2(void);


};

template <typename T>
bool operator==(Segment<T> s1, Segment<T> s2);

/*
template <typename T>
std::ostream& operator<<(std::ostream& flux, Segment<T>);
*/

#include "Segment.tpp"
#endif
