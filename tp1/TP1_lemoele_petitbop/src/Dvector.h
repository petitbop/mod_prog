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
		Dvector(int size, double init);
        Dvector(int n);
        Dvector(std::string fileName);
		~Dvector();
		void display(std::ostream& str);
        int size();
        void fillRandomly();
};
