#include <iostream>
#include <cassert>
#include <string>

class Dvector
{
	private :
		double *tab;
		int length;
	public :
		Dvector();
		Dvector(int size, double init = 0);
        Dvector(Dvector& v);
        Dvector(std::string fileName);
		~Dvector();
		void display(std::ostream& str);
        int size();
        double get(int i);
        void fillRandomly();
};
