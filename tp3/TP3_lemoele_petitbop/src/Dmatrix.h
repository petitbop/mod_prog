//!
//! @file 		Dmatrix.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the class Dmatrix
//!

#ifndef DMATRIX_H
#define DMATRIX_H

#include "Darray.h"

//!
//! @class 		Dmatrix
//!
//! @brief		Class creating a matrix. Inherited from public class Darray.
//!
class Dmatrix : public Darray {

	private :
		int m; 		/* nombre de lignes */
		int n; 		/* nombre de colonnes */

	public :

		//=============================================================================
    	//								CONSTRUCTORS
		//=============================================================================
        //! @description 	Default constructor.
        Dmatrix();

        //! @description 	Constructor.
        //! @param lines 	Initial number of lines of the matrix.
        //! @param columns 	Initial number of columns of the matrix.
        //! @param val		Initial value of all the components of the matrix.
        //!					Optional parameter.
        Dmatrix(int lines, int columns, double val = 0);

        //! @description 	Copy constructor.
        //! @param v 		Dmatrix instance from which to create a new one.
        Dmatrix(Dmatrix const& v);

		//=============================================================================
    	//								DESTRUCTOR
		//=============================================================================
        //! @descritpion	Destructor
        ~Dmatrix();


};

#endif