//!
//! @file 		Darray.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the class Darray
//!

#ifndef DARRAY_H
#define DARRAY_H

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
//! @class 		Darray
//!
//! @brief		Class creating an array. Inherited classes : Dvector, Dmatrix
//!
class Darray {

	protected :
   		int size_; 		/* taille du tableau */
    	double *data; 	/* donnees */
    	bool owner; 	/* flag proprietaire de data */
};

#endif
