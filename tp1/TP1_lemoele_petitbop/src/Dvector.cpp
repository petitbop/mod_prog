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
    if(n < 0){
        throw std::invalid_argument("Tentative d'initialisation d'un Dvector de taille négative");
    }
    length = n;
    if(n == 0){
       tab = NULL; 
    }
    if(n > 0){
        tab = new double[length];
        for(int i = 0; i < length; i++){
            tab[i] = init;
        }
    }
}
Dvector::Dvector(int n)
{
    if(n < 0){
        throw std::invalid_argument("Tentative d'initialisation d'un Dvector de taille négative");
    }
    length = n;
    if(n == 0){
       tab = NULL; 
    }
    if(n > 0){
        tab = new double[length];
    }
}
Dvector::Dvector(Dvector& v)
{
    length = v.size();
    assert(length >= 0);
    if(length == 0){
        tab = NULL;
    }
    if(length > 0){
        tab = new double[length];
        for(int i = 0; i < length; i++){
            tab[i] = v.get(i);
        }
    }
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
    } else {    // Code à factoriser
        length = 0;
        tab = NULL;
        return;
    }
    data.close();

    if(length == 0){
        tab = NULL;
        return;
    }

    tab = new double[length];

    data.open(fileName.c_str());
    if(data){
        for(int i = 0; i < length; i++){
            data >> tab[i];
        }
    } else {
        throw std::runtime_error("Erreur interne : le fichier " + fileName + " n'a pas pu être rouvert...");
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
double Dvector::get(int i){
    if(i >= 0 && i < length){
        return tab[i];
    } else {
        throw std::out_of_range("Débordement d'indice dans un Dvector");
    }
}
void Dvector::fillRandomly()
{
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        tab[i] = ((double)rand())/RAND_MAX;
    }
}
