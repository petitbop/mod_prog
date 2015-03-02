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
//! @brief		Class creating an array. Inherited classes : Darray, Dmatrix
//!
class Darray {

	protected :
   		int size_; 		/* taille du tableau */
    	double *data; 	/* donnees */
    	bool owner; 	/* flag proprietaire de data */

	private :
		//=============================================================================
    	//								PRIVATE METHODS
		//=============================================================================
        //! @fn 			Method to allocate a tab representing the array.
        //! @param size 	Length of the tab.
        void alloc(int size);

        //! @fn 			Method to initialize a array.
        //! @param size 	Initial length of the array.
        //! @param val		Initial value of all the components of the array.
        //!					Optional parameter.
        void init(int size, double val = 0);

        //! @fn 			Method to free the tab representing the array.
        void free();
        
    public :

		//=============================================================================
    	//								CONSTRUCTORS
		//=============================================================================
        //! @description 	Default constructor.
        Darray();

        //! @description 	Constructor.
        //! @param size 	Initial length of the array.
        //! @param val		Initial value of all the components of the array.
        //!					Optional parameter.
        Darray(int size, double val = 0);

        //! @description 	Copy constructor.
        //! @param v 		Darray instance from which to create a new one.
        Darray(Darray const& v);

        //! @description 	Constructor from a file.
        //! @param fileName	File from which to read the initial values of the array.
        Darray(std::string fileName);

		//=============================================================================
    	//								DESTRUCTOR
		//=============================================================================
        //! @descritpion	Destructor
        ~Darray();

		//=============================================================================
    	//								METHODS
		//=============================================================================
        //! @description	Method to display the different coordinates of the array.
        //! @param str 		Output in which to display the values 
        //!					(can be std::cout, or a file, etc.)
        void display(std::ostream& str) const;

        //! @description	Accessor to the length of the array.
        //! @return int 	The length of the array.
        int size() const;

};

#endif
