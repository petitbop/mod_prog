#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

Dvector::Dvector()
{
	length = 0;
	tab = NULL;
}
Dvector::Dvector(int n, double init)
{
	assert(n > 0);
	length = n;
	tab = new double[length];
	for(int i = 0; i < length; i++){
		tab[i] = init;
	}
}
Dvector::Dvector(int n)
{
	assert(n > 0);
	length = n;
	tab = new double[length];
}
Dvector::Dvector(std::string fileName)
{
    std::ifstream data;
    
    data.open(fileName.c_str());
    if(data){
        int x;
        length = 0;
        while(data >> x){
            length++;
        }
    } else {
        throw std::invalid_argument("Le nom de fichier " + fileName + " est invalide");
    }
    data.close();
    tab = new double[length];

    data.open(fileName.c_str());
    if(data){
        for(int i = 0; i < length; i++){
            data >> tab[i];
        }
    } else {
        throw std::runtime_error("Le fichier " + fileName + " n'a pas pu être rouvert...");
    }
    data.close();
}
Dvector::~Dvector(){
	delete [] tab;
}
void Dvector::display(std::ostream& str){
			for(int i = 0; i < length; i++){
				str<<tab[i]<<"\n";
			}
}
int Dvector::size()
{
    return length;
}
void Dvector::fillRandomly()
{
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        tab[i] = ((double)rand())/RAND_MAX;
    }
}
