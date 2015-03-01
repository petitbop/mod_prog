#include "Dvector.h"

using namespace std;

void Dvector::init(int n, double val){
    if(n < 0){
        throw invalid_argument("Initialisation d'un Dvector de taille négative");
    }
    length = n;
    length_alloc = n;
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

//=============================================================================
//                              CONSTRUCTORS
//=============================================================================
Dvector::Dvector(){
    cout << "Default constructor Dvector(). \n";
    init(0);
}

Dvector::Dvector(int n, double val) {
    cout << "Constructor Dvector(unsigned int length, double default_valor). \n";
    init(n, val);
}

Dvector::Dvector(Dvector const& x) {
    cout << "Copy constructor Dvector(Dvector const& x). \n";
    init(x.length);
    for(int i = 0; i < length; i++){
        (*this)(i) = x(i);
    }
}

Dvector::Dvector(string fileName){
    cout << "Constructor Dvector(string entry_file). \n";
    ifstream data;

    data.open(fileName.c_str());

    int nbElem;
    if(data){
        double a;
        nbElem = 0;
        while(data >> a){
            nbElem++;
        }
        init(nbElem);
    } else {
        init(0);
        return;
    }

    data.clear();
    data.seekg(0, ios::beg);

    for(int i = 0; i < length; i++){
        data >> tab[i];
    }

    data.close();
}

//=============================================================================
//                              DESTRUCTOR
//=============================================================================
Dvector::~Dvector(){
    cout << "Destructor ~Dvector(). \n";
    if(length_alloc > 0){
        delete [] tab;
    }
}

//=============================================================================
//                              METHODS
//=============================================================================
void Dvector::display(ostream& str) const{
    for(int i = 0; i < length; i++){
        str<<tab[i]<<"\n";
    }
}

int Dvector::size() const{
    return length;
}

void Dvector::fillRandomly() {
    for(int i = 0; i < length; i++){
        tab[i] = ((double)rand())/RAND_MAX;
    }
}



//=============================================================================
//                              ACCESSOR OPERATORS
//=============================================================================
double& Dvector::operator()(int i) {
    if(i >= 0 && i < length){
        return tab[i];
    } else {
        throw out_of_range("Débordement d'indice dans un Dvector");
    }
}

double Dvector::operator()(int i) const {
    if(i >= 0 && i < length){
        return tab[i];
    } else {
        throw out_of_range("Débordement d'indice dans un Dvector");
    }
}

//=============================================================================
//                      ARITHMETIC ASSIGN OPERATORS
//=============================================================================
Dvector& Dvector::operator+=(double const& a) {
    for (int i=0; i<length; i++) {
        (*this)(i) += a;
    }
    return *this;
}
Dvector& Dvector::operator-=(double const& a) {
    *this += (-a);
    return *this;
}
Dvector& Dvector::operator*=(double const& a) {
    for (int i=0; i<length; i++) {
        (*this)(i) *= a;
    }
    return *this;
}
Dvector& Dvector::operator/=(double const& a) {
    if(a == 0){
        throw invalid_argument("Division d'un Dvector par zéro");
    }

    for (int i=0; i<length; i++) {
        (*this)(i) /= a;
    }
    return *this;
}

Dvector& Dvector::operator+=(Dvector const& x){
    if(length == x.length){
        for (int i=0; i<length; i++) {
            (*this)(i) += x(i);
        }
    } else {
        throw length_error("Addition de deux Dvector de tailles différentes");
    }
    return *this;
}
Dvector& Dvector::operator-=(Dvector const& v){
    (*this) += -v;
    return *this;
}

Dvector& Dvector::operator=(Dvector const& x){
    if(length_alloc < x.size()){
        if(length_alloc > 0){
            delete [] tab;
        }
        init(x.size());
    } else {
        this->length = x.size();
    }
    memcpy(x.tab, this->tab, x.size()*sizeof(double));
    return *this;
}

void Dvector::egal(Dvector const& x){
    if(length_alloc < x.size()){
        if(length_alloc > 0){
            delete [] tab;
        }
        init(x.size());
    } else {
        this->length = x.size();
    }
    for(int i = 0; i < length; i++){
        (*this)(i) = x(i);
    }
}


//=============================================================================
//                      ARITHMETIC OPERATORS
//=============================================================================
Dvector operator+(Dvector const& x, double const& a) {
    Dvector y = Dvector(x);
    y += a;
    return y; 
}
Dvector operator-(Dvector const& x, double const& a) {
    Dvector y = Dvector(x);
    y += -a;
    return y; 
}
Dvector operator*(Dvector const& x, double const& a) {
    Dvector y = Dvector(x);
    y *= a;
    return y; 
}
Dvector operator/(Dvector const& x, double const& a) {
    Dvector y = Dvector(x);
    y /= a;
    return y; 
}

Dvector operator-(Dvector const& x){
    Dvector y = Dvector(x.size());
    for(int i = 0; i < y.size(); i++){
        y(i) = -x(i);
    }
    return y;
}
Dvector operator+(Dvector const& x, Dvector const& y){
    Dvector z = Dvector(x);
    z += y;
    return z;
}
Dvector operator-(Dvector const& x, Dvector const& y){
    Dvector z = Dvector(x);
    z -= y;
    return z;
}

//=============================================================================
//                              FLUX OPERATORS
//=============================================================================
std::ostream& operator<<(std::ostream& flux, Dvector const& x){
    x.display(flux);
    return flux;
}
std::istream& operator>>(std::istream& flux, Dvector& x){
    double a;
    int i = 0;
    int x_size = x.size();
    while(flux >> a && i < x_size){
        x(i) = a;
        i++;
    }
    return flux;
}

//=============================================================================
//                          COMPARISON OPERATORS
//=============================================================================
bool operator==(Dvector const& x, Dvector const& y) {
    if (x.size() != y.size()) return false;
    for (int i = 0; i < x.size(); ++i)
        if (x(i) != y(i)) return false;
    return true;
}
