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

	private:
		int m; 		/* nombre de lignes */
		int n; 		/* nombre de colonnes */

};

#endif