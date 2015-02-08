#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

void Dvector::init(int n, double val){
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
            tab[i] = val;
        }
    }
}
Dvector::Dvector()
{
    init(0);
}
Dvector::Dvector(int n, double val)
{
    init(n, val);
}
Dvector::Dvector(Dvector& v)
{
    double vSize = v.size();
    assert(vSize >= 0);
    if(vSize == 0){
        init(0);
    }
    if(vSize > 0){
        init(vSize);
        for(int i = 0; i < length; i++){
            tab[i] = v.get(i);
        }
    }
}
Dvector::Dvector(std::string fileName)
{
    std::ifstream data;
    
    data.open(fileName.c_str());
    int nbElem;
    if(data){
        double x;
        nbElem = 0;
        while(data >> x){
            nbElem++;
        }
    } else {    // Code à factoriser
        init(0);
        return;
    }
    data.close();

    init(nbElem);

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
    if(length > 0){
        delete [] tab;
    }
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
