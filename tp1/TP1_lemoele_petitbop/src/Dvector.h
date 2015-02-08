#include <iostream>
#include <cassert>
#include <string>

class Dvector
{
	private :
		double *tab;
		int length;
        void init(int size, double val = 0);
	public :
		Dvector();
		Dvector(int size, double val = 0);
        Dvector(Dvector& v);
        Dvector(std::string fileName);
		~Dvector();
		void display(std::ostream& str);
        int size();
        double get(int i);
        void fillRandomly();
};
