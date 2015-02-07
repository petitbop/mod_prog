#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>

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
