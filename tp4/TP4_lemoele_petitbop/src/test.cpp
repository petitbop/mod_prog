#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"
#include<vector>

int main() {
	
	std::cout<<std::endl<<"====> Test du constructeur de Point :"<<std::endl;
	Point<float> p1(4.2f, 8.6f);
	std::cout<<"Point p1 : "<<p1.x()<<", "<<p1.y()<<std::endl;
	Point<double> p2(2.4, 6.8);
	std::cout<<"Point p2 : "<<p2.x()<<", "<<p2.y()<<std::endl;
	Point<int> p3(2, 6);
	std::cout<<"Point p3 : "<<p3.x()<<", "<<p3.y()<<std::endl;
	
	std::cout<<std::endl<<"====> Test du constructeur de Triangle :"<<std::endl;
	Point<double> pt1(5.7, 9.3);
	Point<double> pt2(4.2, 8.6);
	Point<double> pt3(2.4, 1.0);
	Triangle<double> t(pt1, pt2, pt3);
	std::cout<<"Point p1 de t : ("<<t.p1().x()<<", "<<t.p1().y()<<"), (";
	std::cout<<t.p2().x()<<", "<<t.p2().y()<<"), ("<<t.p3().x()<<", "<<t.p3().y()<<")"<<std::endl;

	std::cout<<std::endl<<"====> Test du constructeur de Maillage :"<<std::endl;
	Point<double> origin(0,0);
	Maillage<double,std::vector> m1(1, 2, origin);
	std::cout << m1;
	
	std::cout<<std::endl<<"====> Test des transformations de Maillage :"<<std::endl;
	std::cout<<"==> Transformer (2,3,4,5) :"<<std::endl;
	m1.transformer(2,3,4,5);
	std::cout << m1;
	std::cout<<"==> Deplacer (3,4) :"<<std::endl;
	m1.deplacer(3,4);
	std::cout << m1;
	std::cout<<"==> Tourner (M_PI/2, p2) :"<<std::endl;
	m1.tourner(M_PI/2, p2);
	std::cout << m1;
	std::cout<<"==> Fusionner (m) :"<<std::endl;
    Point<double> p0(0,0);
    Point<double> p4(2,0);
    m1 = Maillage<double,std::vector>(2, 2, p0);
    Maillage<double,std::vector> m2 = Maillage<double,std::vector>(2, 2, p4);
    //std::cout << m2;
    m1.fusionner(m2);
    std::cout << m1;
    
	
}
