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
    if(lines < 0 || columns < 0){
        throw std::invalid_argument("Initialisation d'une matrice avec une dimension de taille négative");
    }
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
	        str<<(*this)(i,j)<<" ";		
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

void Dmatrix::exchange(int i, int j) {
	if (i >= 0 && i < m && j >= 0 && j < n) {
		if (i != j)
		{
			double tmp = (*this)(i,j);
			(*this)(i,j) = (*this)(j,i);
			(*this)(j,i) = tmp;
		}
	} else {
		throw std::invalid_argument("Débordement d'indice lors d'un échange de deux valeurs d'une matrice carrée.");
	}
}

void Dmatrix::transpose() {
	if (n == m) {
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < i; ++j)
				exchange(i,j);
	} else {
		throw std::domain_error("Cette méthode de transposition est réservée aux matrices carrées.");
	}
}

//=============================================================================
//                              ACCESSOR OPERATORS
//=============================================================================
double& Dmatrix::operator()(int line, int column) {
    if(line < 0 || line >= m || column < 0 || column >= n){
        throw std::out_of_range("Accès à un élément en-dehors de la matrice");
    }
	return Darray::operator()(column + n*line);
}

double Dmatrix::operator()(int line, int column) const {
    if(line < 0 || line >= m || column < 0 || column >= n){
        throw std::out_of_range("Accès à un élément en-dehors de la matrice");
    }
	return Darray::operator()(column + n*line);
}

//=============================================================================
//                              ASSIGN OPERATOR
//=============================================================================
Dmatrix& Dmatrix::operator=(Dmatrix const& x) {
    Darray::operator=((Darray const &) x);
    m = x.lines();
    n = x.columns();
    return *this;
}

//=============================================================================
//                              EXTRACTION METHODS
//=============================================================================
Dvector Dmatrix::line(bool copy, int pos) const {
    Darray a = view(copy, n*pos, n);
    Dvector v = Dvector();
    if(copy){
        v.hard_copy(a);
    } else {
        v.soft_copy(a);
    }
    return v;
}

Dvector Dmatrix::column(int pos) const {
	Dvector v = Dvector(n);
	for (int j = 0; j < n; ++j)
		v(j) = operator()(pos,j);
	return v;
}

//=============================================================================
//                              ARITHMETIC OPERATORS
//=============================================================================
Dvector operator*(Dmatrix const& x, Dvector const& y) {
    if(x.columns() == y.size()){
		int somme;
	    Dvector z = Dvector(x.lines());
    	for (int j = 0; j < x.columns(); ++j)
    	{
    		somme = 0;
    		for (int i = 0; i < x.lines(); ++i)
    			somme += x(i,j)*y(i);
    		z(j) = somme;
    	}
    	return z;
    } else {
        throw std::length_error("Produit d'une Dmatrix et d'un Dvector incompatibles.");
    }
}

Dmatrix operator*(Dmatrix const& x, Dmatrix const& y){
    if(x.columns() == y.lines()){
    	Dmatrix z = Dmatrix(x.lines(), y.columns());
    	int somme;
    	for (int i = 0; i < x.lines(); ++i)
    	{
    		for (int j = 0; j < y.columns(); ++j)
    		{
                // On pourrait faire un produit scalaire ici
    			somme = 0;
		    	for (int k = 0; k < x.columns(); ++k)
		    		somme += x(i,k)*y(k,j);
		    	z(i,j) = somme;
    		}
    	}
    	return z;
    } else {
        throw std::length_error("Produit de deux Dmatrix incompatibles.");
    }
}
