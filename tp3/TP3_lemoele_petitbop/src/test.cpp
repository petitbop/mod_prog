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
	Dmatrix m4 = Dmatrix(2, 3, 4.2);
	m4.display(std::cout);
	std::cout<<"Taille : "<<m4.size()<<std::endl;
	std::cout<<"Taille (lignes, colonnes) : "<<m4.lines()<<", "<<m4.columns()<<std::endl;

}