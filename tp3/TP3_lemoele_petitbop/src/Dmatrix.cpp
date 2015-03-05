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
    std::cout << "Default constructor Dmatrix(). \n";
	m = 0;
	n = 0;
}

Dmatrix::Dmatrix(int lines, int columns, double val) : Darray(lines*columns, val) {
    std::cout << "Constructor Dmatrix(int lines, int columns, double default_valor). \n";
	m = lines;
	n = columns;
}

Dmatrix::Dmatrix(Dmatrix const& v) : Darray(v) {
    std::cout << "Copy constructor Dmatrix(Dmatrix const& x). \n";
	m = v.m;
	n = v.n;
}

//=============================================================================
//								DESTRUCTOR
//=============================================================================
Dmatrix::~Dmatrix() {
    std::cout << "Destructor ~Dmatrix(). \n";
}

//=============================================================================
//                              METHODS
//=============================================================================
void Dmatrix::display(std::ostream& str) const {
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
	        str<<operator()(i,j)<<" ";		
		}
		str<<std::endl;	
	}
}

int Dmatrix::lines() const {
	return m;
}
int Dmatrix::columns() const {
	return n;
}

//=============================================================================
//                              ACCESSOR OPERATORS
//=============================================================================
double& Dmatrix::operator()(int line, int column) {
	return Darray::operator()(column + n*line);
}

double Dmatrix::operator()(int line, int column) const {
	return Darray::operator()(column + n*line);
}

//=============================================================================
//                              EXTRACTION METHODS
//=============================================================================
Dvector Dmatrix::line(bool copy, int pos) const {
}

Dvector Dmatrix::column(int pos) const {
	// Dvector v = Dvector(n);
	// for (int j = 0; j < n; ++j)
	// 	v(j) = operator()(pos,j);
	// return v;
}

