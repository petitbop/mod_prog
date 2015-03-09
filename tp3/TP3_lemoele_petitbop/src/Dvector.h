//!
//! @file 		Dvector.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the class Dvector
//!

#ifndef DVECTOR_H
#define DVECTOR_H

#include "Darray.h"

//!
//! @class 		Dvector
//!
//! @brief		Class creating a matrix. Inherited from public class Darray.
//!
class Dvector : public Darray {

    public:
		Dvector();
		Dvector(int n, double val = 0);
        Dvector(Dvector const& x);
        Dvector(Darray const& a);
        
};

double operator*(Dvector const& x, Dvector const& y);

#endif
