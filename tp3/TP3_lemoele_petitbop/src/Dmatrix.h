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

        //! @descritpion    Exchange the value at index (i,j) with the one at index (j,i).
        //! @param i        The line index.
        //! @param j        The column index.
        void exchange(int i, int j);

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

        //! @description    Transpose the current matrix, if it is square (n = m).
        void transpose();

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
        //                              ASSIGN OPERATOR
        //=============================================================================
        //! @description    Assign a Dmatrix to the current one
        //!                 Exemple : dmatrix1 = dmatrix2;
        //! @param x        The Dmatrix to assign.
        //! @return         A reference to the Dmatrix resulting of the operation.
        Dmatrix& operator=(Dmatrix const& x);

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

//=============================================================================
//                              ARITHMETIC OPERATORS
//=============================================================================
//! @description    Multiply a Dvector to a Dmatrix.
//!                 Exemple : Dmatrix * Dvector;
//! @param x        The Dmatrix to which to multiply.
//! @param y        The Dvector to multiply.
//! @return         The Dvector resulting of the operation.
Dvector operator*(Dmatrix const& x, Dvector const& y);

//! @description    Multiply two Dmatrix.
//!                 Exemple : Dmatrix * Dmatrix;
//! @param x        The first Dmatrix to multiply.
//! @param y        The second Dmatrix to multiply.
//! @return         The Dmatrix resulting of the operation.
Dmatrix operator*(Dmatrix const& x, Dmatrix const& y);

#endif