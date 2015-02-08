
#ifndef DVECTOR_H
#define DVECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

class Dvector
{
	private :
		double *tab;
		int length;
        void init(int size, double val = 0);
	public :
		Dvector();
		Dvector(int size, double val = 0);
        Dvector(const Dvector& v);
        // Dvector(Dvector& v);
        Dvector(std::string fileName);
		~Dvector();
		void display(std::ostream& str);
        int size();
        double get(int i);
        void fillRandomly();
};

#endif