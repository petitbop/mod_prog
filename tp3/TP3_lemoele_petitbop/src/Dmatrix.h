//!
//! @file 		Dmatrix.h
//! @author 	lemoele petitbop
//!
//! @brief 		Header file for the class Dmatrix
//!

#ifndef DMATRIX_H
#define DMATRIX_H

#include "Darray.h"
#include "Dvector.h"

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

        //=============================================================================
        //                              METHODS
        //=============================================================================
        //! @description    Method to display the different coordinates of the matrix.
        //! @param str      Output in which to display the values 
        //!                 (can be std::cout, or a file, etc.)
        void display(std::ostream& str) const;

        //! @description    Accessor to the number of lines of the matrix.
        //! @return int     The number of lines of the matrix.
        int lines() const;

        //! @description    Accessor to the number of columns of the matrix.
        //! @return int     The number of columns of the matrix.
        int columns() const;

        //=============================================================================
        //                              ACCESSOR OPERATORS
        //=============================================================================
        //! @description    Access to a reference to a value of the matrix.
        //!                 Exemple : dmatrix(2, 3);
        //! @param line     The line of the value.
        //!                 (0 <= i < m)
        //! @param column   The column of the value.
        //!                 (0 <= i < n)
        //! @return         The reference to the value.
        double& operator()(int line, int column);

        //! @description    Access to a value of the matrix.
        //!                 Exemple : dmatrix(2, 3);
        //! @param line     The line of the value.
        //!                 (0 <= i < m)
        //! @param column   The column of the value.
        //!                 (0 <= i < n)
        //! @return         The value.
        double operator()(int line, int column) const;

        //=============================================================================
        //                              EXTRACTION METHODS
        //=============================================================================
        //! @description    Extract a line as a Dvector instance.
        //! @param copy     ?????
        //! @param pos      The index of the line.
        //!                 (0 <= i < m)
        //! @return         The reference to the Dvector.
        Dvector line(bool copy, int pos) const;

        //! @description    Extract a column as a Dvector instance.
        //! @param pos      The index of the column.
        //!                 (0 <= i < n)
        //! @return         The reference to the Dvector.
        Dvector column(int pos) const;

};

#endif