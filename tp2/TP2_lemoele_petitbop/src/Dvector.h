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

		//! @fn 			Method to initialize a vector.
		//! @param size 	Initial length of the vector.
		//! @param val		Initial value of all the components of the vector.
		//!					Optional parameter.
        void init(int size, double val = 0);

	public :

		//! @description 	Default constructor.
		Dvector();

		//! @description 	Constructor.
		//! @param size 	Initial length of the vector.
		//! @param val		Initial value of all the components of the vector.
		//!					Optional parameter.
		Dvector(int size, double val = 0);

		//! @description 	Copy constructor.
		//! @param v 		Dvector instance from which to create a new one.
        Dvector(const Dvector& v);
        // Dvector(Dvector& v);

		//! @description 	Constructor from a file.
		//! @param fileName	File from which to read the initial values of the vector.
        Dvector(std::string fileName);

        //! @descritpion	Destructor
		~Dvector();

		//! @description	Method to display the different coordinates of the vector.
		//! @param str 		Output in which to display the values 
		//!					(can be std::cout, or a file, etc.)
		void display(std::ostream& str);

		//! @description	Accessor to the length of the vector.
		//! @return int 	The length of the vector.
        int size();

		//! @description	Accessor to a value of the vector.
		//! @param i 		The index from which to get the value.
		//!					(0 <= i < length)
		//! @return			The value at index i.
        double get(int i);

        //! @description	Method to fill the vector with random values between 0 and 1.
        void fillRandomly();

		//! @description	Access to a value of the vector.
		//! 				Exemple : dvector(2);
		//! @param i 		The index of the value.
		//!					(0 <= i < length)
		//! @return			The value at index i.
		double & operator () (int i) const;

		//! @description	Add a double to all members of a DVector.
		//! 				Exemple : dvector + 4.2;
		//! @param d 		The double to add.
		//! @return			The result of the operation.
		Dvector operator +(const double d);

		//! @description	Add a double to all members of a DVector.
		//! 				Exemple : dvector - 4.2;
		//! @param d 		The double to substract.
		//! @return			The result of the operation.
		Dvector operator -(const double d);

		//! @description	Add a double to all members of a DVector.
		//! 				Exemple : dvector * 4.2;
		//! @param d 		The double to multiply.
		//! @return			The result of the operation.
		Dvector operator *(const double d);

		//! @description	Add a double to all members of a DVector.
		//! 				Exemple : dvector / 4.2;
		//! @param d 		The double to divise by.
		Dvector operator /(const double d);

		Dvector & operator + (Dvector & v);
};

		Dvector & operator + (const Dvector & v1, const Dvector & v2);
#endif
