//!
//! @file 		Dmatrix.cpp
//! @author 	lemoele petitbop
//!
//! @brief 		File for the class Dmatrix
//!

#include "Dmatrix.h"

//=============================================================================
//								CONSTRUCTORS
//=============================================================================
Dmatrix::Dmatrix() : Darray() {
	m = 0;
	n = 0;
}

Dmatrix::Dmatrix(int lines, int columns, double val) : Darray(lines*columns, val) {
	m = lines;
	n = columns;
}

Dmatrix::Dmatrix(Dmatrix const& v) : Darray(v) {
	m = v.m;
	n = v.n;
}

//=============================================================================
//								DESTRUCTOR
//=============================================================================
Dmatrix::~Dmatrix() {
	
}