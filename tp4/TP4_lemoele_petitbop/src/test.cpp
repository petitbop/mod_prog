#include "Point.h"

int main() {
	
	std::cout<<std::endl<<"====> Test du constructeur de Point :"<<std::endl;
	Point p = Point(4.2, 8.6);
	std::cout<<"Point p : "<<p.x()<<", "<<p.y()<<std::endl;

}