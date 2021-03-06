//!
//! @file 		Dvector.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the class Dvector
//!

#ifndef DVECTOR_H
#define DVECTOR_H

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
//! @class 		Dvector
//!
//! @brief		Class creating a vector of double.
//!
class Dvector
{
    private :
        double *tab;
        int length;
        bool own;

		//=============================================================================
    	//								PRIVATE METHODS
		//=============================================================================
        //! @fn 			Method to allocate a tab representing the vector.
        //! @param size 	Length of the tab.
        void alloc(int size);

        //! @fn 			Method to initialize a vector.
        //! @param size 	Initial length of the vector.
        //! @param val		Initial value of all the components of the vector.
        //!					Optional parameter.
        void init(int size, double val = 0);

        //! @fn 			Method to free the tab representing the vector.
        void free();

        //! @fn				Copying a Dvector in the current one, when the Dvector
        //!					does not owns its data.
        //! @param x 		The Dvector to assign.
        void soft_copy(Dvector const& x);

    public :

		//=============================================================================
    	//								CONSTRUCTORS
		//=============================================================================
        //! @description 	Default constructor.
        Dvector();

        //! @description 	Constructor.
        //! @param size 	Initial length of the vector.
        //! @param val		Initial value of all the components of the vector.
        //!					Optional parameter.
        Dvector(int size, double val = 0);

        //! @description 	Copy constructor.
        //! @param v 		Dvector instance from which to create a new one.
        Dvector(Dvector const& v);

        //! @description 	Constructor from a file.
        //! @param fileName	File from which to read the initial values of the vector.
        Dvector(std::string fileName);

		//=============================================================================
    	//								DESTRUCTOR
		//=============================================================================
        //! @descritpion	Destructor
        ~Dvector();

		//=============================================================================
    	//								METHODS
		//=============================================================================
        //! @description	Method to display the different coordinates of the vector.
        //! @param str 		Output in which to display the values 
        //!					(can be std::cout, or a file, etc.)
        void display(std::ostream& str) const;

        //! @description	Accessor to the length of the vector.
        //! @return int 	The length of the vector.
        int size() const;

        //! @description	Method to fill the vector with random values between 0 and 1.
        void fillRandomly();

		//=============================================================================
    	//								ACCESSOR OPERATORS
		//=============================================================================
        //! @description	Access to a reference to a value of the vector.
        //! 				Exemple : dvector(2);
        //! @param i 		The index of the value.
        //!					(0 <= i < length)
        //! @return			The reference to the value at index i.
        double& operator()(int i);

        //! @description	Access to a value of the vector.
        //! 				Exemple : dvector(2);
        //! @param i 		The index of the value.
        //!					(0 <= i < length)
        //! @return			The value at index i.
        double operator()(int i) const;

		//=============================================================================
    	//						ARITHMETIC ASSIGN OPERATORS
		//=============================================================================
        //! @description	Add a double to all members of the current Dvector.
        //! 				Exemple : dvector += 4.2;
        //! @param a 		The double to add.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator+=(double const& a);

        //! @description	Substract a double to all members of the current Dvector.
        //! 				Exemple : dvector -= 4.2;
        //! @param a 		The double to substract.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator-=(double const& a);

        //! @description	Multiply a double to all members of the current Dvector.
        //! 				Exemple : dvector *= 4.2;
        //! @param a 		The double to multiply.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator*=(double const& a);

        //! @description	Divise all members of the current Dvector by a double.
        //! 				Exemple : dvector /= 4.2;
        //! @param a 		The double to divise by.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator/=(double const& a);

        //! @description	Add a Dvector to the current one.
        //! 				Exemple : dvector1 + dvector2;
        //! @param x 		The Dvector to add.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator+=(Dvector const& x);

        //! @description	Substract a Dvector to the current one
        //! 				Exemple : dvector1 - dvector2;
        //! @param x 		The Dvector to substract.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator-=(Dvector const& x);

		//=============================================================================
    	//								SUB-VIEWING METHODS
		//=============================================================================
        //! @description	Copying a Dvector in the current one, when the Dvector owns its data.
        //! @param x 		The Dvector to assign.
        void hard_copy(Dvector const& x);

        //! @description	Copying a Dvector in the current one, when the Dvector owns its data.
        //!					(Slow version : not using the memcpy method.)
        //! @param x 		The Dvector to assign.
        void hard_copy_slow(Dvector const& x);

        //! @description	Visualize a sub-part of a Dvector as a whole vector.
        //! @param copy 	TRUE to copy the Dvector data, FALSE otherwise.
        //! @param start	First index of the sub-part.
        //! @param count	Length of the sub-part.
        //! @return			The Dvector sub-part of the current one. Vector that ranges 
        //!					from index "start" of the current one to "start+count".
        Dvector view(bool copy, int start, int count) const;

        //! @description	Ask if the Dvector owns its data or not.
        //! @return			TRUE if the Dvector is owner of itts data, FALSE otherwise.
        bool isOwner() const;

        //! @description	Accessor to the data of the Dvector.
        //! @return			A tab of double containing the data.
        const double* getData() const;

		//=============================================================================
    	//								ASSIGN OPERATOR
		//=============================================================================
        //! @description	Assign a Dvector to the current one
        //! 				Exemple : dvector1 = dvector2;
        //! @param x 		The Dvector to assign.
        //! @return			A reference to the Dvector resulting of the operation.
        Dvector& operator=(Dvector const& x);

};

//=============================================================================
//						ARITHMETIC OPERATORS
//=============================================================================
//! @description	Add a double to all members of a Dvector.
//! 				Exemple : dvector + 4.2;
//! @param x 		The Dvector to which to add.
//! @param a 		The double to add.
//! @return			The Dvector resulting of the operation.
Dvector operator+(Dvector const& x, double const& a);

//! @description	Substract a double to all members of a Dvector.
//! 				Exemple : dvector - 4.2;
//! @param x 		The Dvector to which to substract.
//! @param a 		The double to substract.
//! @return			The Dvector resulting of the operation.
Dvector operator-(Dvector const& x, double const& a);

//! @description	Multiply a double to all members of a Dvector.
//! 				Exemple : dvector * 4.2;
//! @param x 		The Dvector to which to multiply.
//! @param a 		The double to multiply.
//! @return			The Dvector resulting of the operation.
Dvector operator*(Dvector const& x, double const& a);

//! @description	Divise all members of a Dvector by a double.
//! 				Exemple : dvector / 4.2;
//! @param x 		The Dvector to divise.
//! @param a 		The double to divise by.
//! @return			The Dvector resulting of the operation.
Dvector operator/(Dvector const& x, double const& a);

//! @description	Unitary minus.
//! 				Exemple : - dvector2;
//! @param x 		The Dvector operand.
//! @return			The Dvector resulting of the operation.
Dvector operator-(Dvector const& x);

//! @description	Add a Dvector to another.
//! 				Exemple : dvector1 + dvector2;
//! @param x 		The first Dvector operand.
//! @param y 		The second Dvector operand.
//! @return			The Dvector resulting of the operation.
Dvector operator+(Dvector const& x, Dvector const& y);

//! @description	Substract a Dvector to another
//! 				Exemple : dvector1 - dvector2;
//! @param x 		The first Dvector operand.
//! @param y 		The second Dvector operand.
//! @return			The Dvector resulting of the operation.
Dvector operator-(Dvector const& x, Dvector const& y);

//=============================================================================
//								FLUX OPERATORS
//=============================================================================
//! @description	Redirect all members of a Dvector to a flux.
//! @param x 		The Dvector to redirect.
//! @param flux		The flux to which redirect the Dvector.
//! @return			The new flux.
std::ostream& operator<<(std::ostream& flux, Dvector const& x);

//! @description	Read all members of a Dvector from a flux.
//! @param x 		The Dvector to which to change the members.
//! @param flux		The flux from which to read the Dvector.
//! @return			The new flux.
std::istream& operator>>(std::istream& flux, Dvector& x);

//=============================================================================
//							COMPARISON OPERATORS
//=============================================================================
//! @description	Determine if 2 Dvectors are equals.
//! @param x 		The first Dvector operand.
//! @param y 		The second Dvector operand.
//! @return			TRUE if each member at index i in Dvector x is equal to
//!					each member at index i in Dvector y, FALSE otherwise.
bool operator==(Dvector const& x, Dvector const& y);

#endif
