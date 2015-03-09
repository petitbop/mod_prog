#include "Point.h"
#include "Triangle.h"

int main() {
	
	std::cout<<std::endl<<"====> Test du constructeur de Point :"<<std::endl;
	Point<float> p1(4.2f, 8.6f);
	std::cout<<"Point p1 : "<<p1.x()<<", "<<p1.y()<<std::endl;
	Point<double> p2(2.4, 6.8);
	std::cout<<"Point p2 : "<<p2.x()<<", "<<p2.y()<<std::endl;
	Point<int> p3(2, 6);
	std::cout<<"Point p3 : "<<p3.x()<<", "<<p3.y()<<std::endl;
	// Comment limiter à float et double ???????????????????????????????????
	
	// std::cout<<std::endl<<"====> Test du constructeur de Triangle :"<<std::endl;
	// Point<double> pt1(5.7, 9.3);
	// Point<double> pt2(4.2, 8.6);
	// Point<double> pt3(2.4, 1.0);
	// Triangle<double> t(pt1, pt2, pt3);

}