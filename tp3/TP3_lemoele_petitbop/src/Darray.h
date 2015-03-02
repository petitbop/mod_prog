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
//! @brief		Class creating an array. Can be inherited.
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

        //! @fn				Copying a Darray in the current one, when the Darray
        //!					does not owns its data.
        //! @param x 		The Darray to assign.
        void soft_copy(Darray const& x);

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


		//=============================================================================
    	//						ARITHMETIC ASSIGN OPERATORS
		//=============================================================================
        //! @description	Add a double to all members of the current Darray.
        //! 				Exemple : dvector += 4.2;
        //! @param a 		The double to add.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator+=(double const& a);

        //! @description	Substract a double to all members of the current Darray.
        //! 				Exemple : dvector -= 4.2;
        //! @param a 		The double to substract.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator-=(double const& a);

        //! @description	Multiply a double to all members of the current Darray.
        //! 				Exemple : dvector *= 4.2;
        //! @param a 		The double to multiply.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator*=(double const& a);

        //! @description	Divise all members of the current Darray by a double.
        //! 				Exemple : dvector /= 4.2;
        //! @param a 		The double to divise by.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator/=(double const& a);

        //! @description	Add a Darray to the current one.
        //! 				Exemple : dvector1 + dvector2;
        //! @param x 		The Darray to add.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator+=(Darray const& x);

        //! @description	Substract a Darray to the current one
        //! 				Exemple : dvector1 - dvector2;
        //! @param x 		The Darray to substract.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator-=(Darray const& x);

		//=============================================================================
    	//								ACCESSOR OPERATORS
		//=============================================================================
        //! @description	Access to a reference to a value of the array.
        //! 				Exemple : darray(2);
        //! @param i 		The index of the value.
        //!					(0 <= i < size_)
        //! @return			The reference to the value at index i.
        double& operator()(int i);

        //! @description	Access to a value of the array.
        //! 				Exemple : darray(2);
        //! @param i 		The index of the value.
        //!					(0 <= i < size_)
        //! @return			The value at index i.
        double operator()(int i) const;

		//=============================================================================
    	//								SUB-VIEWING METHODS
		//=============================================================================
        //! @description	Copying a Darray in the current one, when the Darray owns its data.
        //! @param x 		The Darray to assign.
        void hard_copy(Darray const& x);

        //! @description	Visualize a sub-part of a Darray as a whole array.
        //! @param copy 	TRUE to copy the Darray data, FALSE otherwise.
        //! @param start	First index of the sub-part.
        //! @param count	Length of the sub-part.
        //! @return			The Darray sub-part of the current one. array that ranges 
        //!					from index "start" of the current one to "start+count".
        Darray view(bool copy, int start, int count) const;

        //! @description	Ask if the Darray owns its data or not.
        //! @return			TRUE if the Darray is owner of itts data, FALSE otherwise.
        bool isOwner() const;

        //! @description	Accessor to the data of the Darray.
        //! @return			A tab of double containing the data.
        const double* getData() const;

		//=============================================================================
    	//								ASSIGN OPERATOR
		//=============================================================================
        //! @description	Assign a Darray to the current one
        //! 				Exemple : darray1 = darray2;
        //! @param x 		The Darray to assign.
        //! @return			A reference to the Darray resulting of the operation.
        Darray& operator=(Darray const& x);

};

//=============================================================================
//						ARITHMETIC OPERATORS
//=============================================================================
//! @description	Add a double to all members of a Darray.
//! 				Exemple : dvector + 4.2;
//! @param x 		The Darray to which to add.
//! @param a 		The double to add.
//! @return			The Darray resulting of the operation.
Darray operator+(Darray const& x, double const& a);

//! @description	Substract a double to all members of a Darray.
//! 				Exemple : dvector - 4.2;
//! @param x 		The Darray to which to substract.
//! @param a 		The double to substract.
//! @return			The Darray resulting of the operation.
Darray operator-(Darray const& x, double const& a);

//! @description	Multiply a double to all members of a Darray.
//! 				Exemple : dvector * 4.2;
//! @param x 		The Darray to which to multiply.
//! @param a 		The double to multiply.
//! @return			The Darray resulting of the operation.
Darray operator*(Darray const& x, double const& a);

//! @description	Divise all members of a Darray by a double.
//! 				Exemple : dvector / 4.2;
//! @param x 		The Darray to divise.
//! @param a 		The double to divise by.
//! @return			The Darray resulting of the operation.
Darray operator/(Darray const& x, double const& a);

//! @description	Unitary minus.
//! 				Exemple : - dvector2;
//! @param x 		The Darray operand.
//! @return			The Darray resulting of the operation.
Darray operator-(Darray const& x);

//! @description	Add a Darray to another.
//! 				Exemple : dvector1 + dvector2;
//! @param x 		The first Darray operand.
//! @param y 		The second Darray operand.
//! @return			The Darray resulting of the operation.
Darray operator+(Darray const& x, Darray const& y);

//! @description	Substract a Darray to another
//! 				Exemple : dvector1 - dvector2;
//! @param x 		The first Darray operand.
//! @param y 		The second Darray operand.
//! @return			The Darray resulting of the operation.
Darray operator-(Darray const& x, Darray const& y);

#endif
