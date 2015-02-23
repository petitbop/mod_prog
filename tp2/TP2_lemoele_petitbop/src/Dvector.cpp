#include "Dvector.h"

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
    srand(time(NULL));
}
Dvector::Dvector()
{
    std::cout << "Default constructor Dvector(). \n";
    init(0);
}
Dvector::Dvector(int n, double val)
{
    std::cout << "Constructor Dvector(unsigned int length, double default_valor). \n";
    init(n, val);
}
Dvector::Dvector(const Dvector& v)
{
    std::cout << "Copy constructor Dvector(const Dvector &V). \n";
    double vSize = v.length;
    assert(vSize >= 0);
    if(vSize == 0){
        init(0);
    }
    if(vSize > 0){
        init(vSize);
        for(int i = 0; i < length; i++){
            tab[i] = v.tab[i];
        }
    }
}
// Dvector::Dvector(Dvector& v)
// {
//     std::cout << "Constructor Dvector(std::string entry_file). \n";
//     double vSize = v.size();
//     assert(vSize >= 0);
//     if(vSize == 0){
//         init(0);
//     }
//     if(vSize > 0){
//         init(vSize);
//         for(int i = 0; i < length; i++){
//             tab[i] = v.get(i);
//         }
//     }
// }
Dvector::Dvector(std::string fileName)
{
    std::cout << "Constructor Dvector(std::string entry_file). \n";
    std::ifstream data;
    
    data.open(fileName.c_str());
    int nbElem;
    if(data){
        double x;
        nbElem = 0;
        while(data >> x){
            nbElem++;
        }
    } else {
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
    std::cout << "Destructor ~Dvector(). \n";
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
double Dvector::get(int i){		// A supprimer (remplacé par opérateur())
    if(i >= 0 && i < length){
        return tab[i];
    } else {
        throw std::out_of_range("Débordement d'indice dans un Dvector");
    }
}
void Dvector::fillRandomly()
{
    for(int i = 0; i < length; i++){
        tab[i] = ((double)rand())/RAND_MAX;
    }
}
double & Dvector::operator()(int i) const {
    if(i >= 0 && i < length){
        return tab[i];
    } else {
        throw std::out_of_range("Débordement d'indice dans un Dvector");
    }
}
Dvector Dvector::operator +(const double d) {
    Dvector Res = Dvector(length);
    for (int i=0; i<length; i++) {
        Res.tab[i] = tab[i]+d;
    }
    return Res; 
}
// Dvector operator +(const Dvector & v, const double d) {
//     Dvector Res = Dvector(v);
//     return Res+d; 
// }
Dvector Dvector::operator -(const double d) {
    Dvector Res = Dvector(*this);
    return Res+(-d); 
}
Dvector Dvector::operator *(const double d) {
    Dvector Res = Dvector(length);
    for (int i=0; i<length; i++) {
        Res.tab[i] = tab[i]*d;
    }
    return Res; 
}
Dvector Dvector::operator /(const double d) {
    Dvector Res = Dvector(*this);
    return Res*(1/d); 
}

Dvector & Dvector::operator + (Dvector & v){
	if(this->size() == v.size()){
		Dvector * res = new Dvector(this->size());
		for(int i = 0; i < this->size(); i++){
			(*res)(i) = (*this)(i) + v(i);
			//std::cout << res(i) << std::endl;
		}
		return *res;
	} else {
		throw std::length_error("Tentative d'addition de deux Dvector de tailles différentes");
	}
}
Dvector & operator + (const Dvector & v1, const Dvector & v2){
	Dvector* x = new Dvector(0);
	return *x;	

}
