#include "Dvector.h"


int main (int argc, const char* argv[]) {

	// std::cout<<std::endl<<"====> Test du constructeur par défaut :"<<std::endl;
	// Dvector v1 = Dvector();
	// v1.display(std::cout);
	// std::cout<<"Taille : "<<v1.size()<<std::endl;

	// std::cout<<std::endl<<"====> Test du construteur avec length = 0 :"<<std::endl;
	// Dvector v2 = Dvector(0);
	// v2.display(std::cout);
	// std::cout<<"Taille : "<<v2.size()<<std::endl;

	// std::cout<<std::endl<<"====> Test du construteur avec length = 2 :"<<std::endl;
	// Dvector v3 = Dvector(2);
	// v3.display(std::cout);
	// std::cout<<"Taille : "<<v3.size()<<std::endl;

	// std::cout<<std::endl<<"====> Test du construteur Dvector(3,2) avec length = 3 et default = 4.2 :"<<std::endl;
	// Dvector v4 = Dvector(3, 4.2);
	// v4.display(std::cout);
	// std::cout<<"Taille : "<<v4.size()<<std::endl;

	// std::cout<<std::endl<<"====> Test 1 du remplissage aléatoire sur le vecteur de taille 3 :"<<std::endl;
	// v4.fillRandomly();
	// v4.display(std::cout);

	// std::cout<<std::endl<<"====> Test 2 du remplissage aléatoire sur le vecteur de taille 3 :"<<std::endl;
	// v4.fillRandomly();
	// v4.display(std::cout);

	// std::cout<<std::endl<<"====> Test du constructeur par copie du vecteur de taille 3 :"<<std::endl;
	// Dvector v5 = Dvector(v4);
	// v5.display(std::cout);
	// std::cout<<"Taille : "<<v5.size()<<std::endl;

	// std::cout<<std::endl<<"====> Test du constructeur lisant dans un fichier inexistant :"<<std::endl;
	// Dvector v6 = Dvector("fichier_inexistant.txt");
	// v6.display(std::cout);
	// std::cout<<"Taille : "<<v6.size()<<std::endl;

	// std::cout<<std::endl<<"====> Test du constructeur lisant dans le fichier tp1_test1.txt :"<<std::endl;
	// Dvector v7 = Dvector("tp1_test1.txt");
	// v7.display(std::cout);
	// std::cout<<"Taille : "<<v7.size()<<std::endl;
	
	// std::cout<<std::endl<<"====> Test du constructeur lisant dans le fichier tp1_test2.txt :"<<std::endl;
	// Dvector v8 = Dvector("tp1_test2.txt");
	// std::cout<<"Taille : "<<v8.size()<<std::endl<<std::endl;

	std::cout<<std::endl<<"====> Test de la surcharge d'opérateurs entre un vecteur et un réel :"<<std::endl;
	Dvector u1 = Dvector(3, 4.2);
	(u1+2.0).display(std::cout);
	(u1-3.0).display(std::cout);
	(u1*3.0).display(std::cout);
	(u1/2.0).display(std::cout);


} 