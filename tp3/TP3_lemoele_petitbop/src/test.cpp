#include "Dmatrix.h"

int main() {

	std::cout<<std::endl<<"====> Test du constructeur par défaut :"<<std::endl;
	Dmatrix m1 = Dmatrix();
	m1.display(std::cout);
	std::cout<<"Taille : "<<m1.size()<<std::endl;
	std::cout<<"Taille (lignes, colonnes) : "<<m1.lines()<<", "<<m1.columns()<<std::endl;

	std::cout<<std::endl<<"====> Test du construteur avec lines = 0, columns = 0 :"<<std::endl;
	Dmatrix m2 = Dmatrix(0, 0);
	m2.display(std::cout);
	std::cout<<"Taille : "<<m2.size()<<std::endl;
	std::cout<<"Taille (lignes, colonnes) : "<<m2.lines()<<", "<<m2.columns()<<std::endl;

	std::cout<<std::endl<<"====> Test du construteur avec lines = 2, columns = 3 :"<<std::endl;
	Dmatrix m3 = Dmatrix(2, 3);
	m3.display(std::cout);
	std::cout<<"Taille : "<<m3.size()<<std::endl;
	std::cout<<"Taille (lignes, colonnes) : "<<m3.lines()<<", "<<m3.columns()<<std::endl;

	std::cout<<std::endl<<"====> Test du construteur Dmatrix(2, 3, 4.2) avec lines = 2, columns = 3 et default = 4.2 :"<<std::endl;
	Dmatrix m4 = Dmatrix(3, 2, 4.2);
	m4.display(std::cout);
	std::cout<<"Taille : "<<m4.size()<<std::endl;
	std::cout<<"Taille (lignes, colonnes) : "<<m4.lines()<<", "<<m4.columns()<<std::endl;

	std::cout<<std::endl<<"====> Test de la multiplication matrice * vecteur :"<<std::endl;
	Dmatrix m5 = Dmatrix(2, 3);
	for (int i = 0; i < m5.lines(); ++i)
		for (int j = 0; j < m5.columns(); ++j)
			m5(i, j) = i+j;
	m5.display(std::cout);
	Dvector v1 = Dvector(3, 1);
	v1.display(std::cout);
	// v1 = m5*v1;

	std::cout<<std::endl<<"====> Test de la multiplication matrice * matrice :"<<std::endl;
	for (int i = 0; i < m4.lines(); ++i)
		for (int j = 0; j < m4.columns(); ++j)
			m4(i, j) = 1+i*j;
	m4.display(std::cout);
	// m5 = m5*m4;

	std::cout<<std::endl<<"====> Test de la transposition :"<<std::endl;
	Dmatrix m6 = Dmatrix(2, 2);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
        	m6(i,j) = (double)rand();
	m6.display(std::cout);
	m6.transpose();
	m6.display(std::cout);
	m6.transpose();
	m6.display(std::cout);
}