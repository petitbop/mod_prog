//!
//! @file 		Darray.cpp
//! @author 	lemoele petitbop
//!
//! @brief 		File for the class Darray
//!

#include "Darray.h"

//=============================================================================
//                              PRIVATE METHODS
//=============================================================================
void Darray::alloc(int n){
    if(n < 0){
        throw std::invalid_argument("Initialisation d'un Darray de taille négative");
    }
    size_ = n;
    if(n == 0){
        data = NULL; 
    }
    if(n > 0){
        data = new double[size_];
    }
}

void Darray::init(int n, double val){
    alloc(n);
    owner = true;
    for(int i = 0; i < size_; i++){
        data[i] = val;
    }
    srand(time(NULL));
}

void Darray::free(){
    bool is_null = size_ == 0;
    bool own_stuff = !is_null && owner;
    if(own_stuff){
        delete [] data;
    }
}

//=============================================================================
//                              CONSTRUCTORS
//=============================================================================
Darray::Darray(){
    std::cout << "Default constructor Darray(). \n";
    init(0);
}

Darray::Darray(int n, double val) {
    std::cout << "Constructor Darray(int length, double default_valor). \n";
    init(n, val);
}

Darray::Darray(Darray const& x) {
    std::cout << "Copy constructor Darray(Darray const& x). \n";
    init(0);
    *this = x;
}

Darray::Darray(std::string fileName){
    std::cout << "Constructor Darray(string entry_file). \n";
    std::ifstream file;

    file.open(fileName.c_str());

    int nbElem;
    if(file){
        double a;
        nbElem = 0;
        while(file >> a){
            nbElem++;
        }
        init(nbElem);
    } else {
        init(0);
        return;
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    for(int i = 0; i < size_; i++){
        file >> data[i];
    }

    file.close();
}

//=============================================================================
//                              DESTRUCTOR
//=============================================================================
Darray::~Darray(){
    std::cout << "Destructor ~Darray(). \n";
    free();
}

//=============================================================================
//                              METHODS
//=============================================================================
void Darray::display(std::ostream& str) const{
    for(int i = 0; i < size_; i++){
        str<<data[i]<<"\n";
    }
}

int Darray::size() const{
    return size_;
}

//=============================================================================
//                      ARITHMETIC ASSIGN OPERATORS
//=============================================================================
Darray& Darray::operator+=(double const& a) {
    for (int i=0; i<size_; i++) {
        (*this)(i) += a;
    }
    return *this;
}
Darray& Darray::operator-=(double const& a) {
    *this += (-a);
    return *this;
}
Darray& Darray::operator*=(double const& a) {
    for (int i=0; i<size_; i++) {
        (*this)(i) *= a;
    }
    return *this;
}
Darray& Darray::operator/=(double const& a) {
    if(a == 0){
        throw std::invalid_argument("Division d'un Darray par zéro");
    }

    for (int i=0; i<size_; i++) {
        (*this)(i) /= a;
    }
    return *this;
}

Darray& Darray::operator+=(Darray const& x){
    if(size_ == x.size_){
        for (int i=0; i<size_; i++) {
            (*this)(i) += x(i);
        }
    } else {
        throw std::length_error("Addition de deux Darray de tailles différentes");
    }
    return *this;
}
Darray& Darray::operator-=(Darray const& v){
    (*this) += -v;
    return *this;
}


//=============================================================================
//                      ARITHMETIC OPERATORS
//=============================================================================
Darray operator+(Darray const& x, double const& a) {
    Darray y = Darray(x);
    y += a;
    return y; 
}
Darray operator-(Darray const& x, double const& a) {
    Darray y = Darray(x);
    y += -a;
    return y; 
}
Darray operator*(Darray const& x, double const& a) {
    Darray y = Darray(x);
    y *= a;
    return y; 
}
Darray operator/(Darray const& x, double const& a) {
    Darray y = Darray(x);
    y /= a;
    return y; 
}

Darray operator-(Darray const& x){
    Darray y = Darray(x.size());
    for(int i = 0; i < y.size(); i++){
        y(i) = -x(i);
    }
    return y;
}
Darray operator+(Darray const& x, Darray const& y){
    Darray z = Darray(x);
    z += y;
    return z;
}
Darray operator-(Darray const& x, Darray const& y){
    Darray z = Darray(x);
    z -= y;
    return z;
}

//=============================================================================
//                              ACCESSOR OPERATORS
//=============================================================================
double& Darray::operator()(int i) {
    if(i >= 0 && i < size_){
        return data[i];
    } else {
        throw std::out_of_range("Débordement d'indice dans un Darray");
    }
}

double Darray::operator()(int i) const {
    if(i >= 0 && i < size_){
        return data[i];
    } else {
        throw std::out_of_range("Débordement d'indice dans un Darray");
    }
}

//=============================================================================
//                              SUB-VIEWING METHODS
//=============================================================================
void Darray::soft_copy(Darray const& x){
    size_ = x.size_;
    data = x.data;
    owner = false;
}

void Darray::hard_copy(Darray const& x){
    free();
    alloc(x.size());

    memcpy(this->data, x.data, x.size()*sizeof(double));
    owner = true;
}

Darray Darray::view(bool copy, int start, int count) const{
    if(size_ == 0){
        throw new std::length_error("View sur un Darray de taille nulle");
    }
    if (count <= 0){
        throw new std::invalid_argument("View d'un nombre négatif ou nul d'éléments");
    }
    if(start < 0 || start + count - 1 > size_ - 1){
        throw new std::out_of_range("Débordement d'indice dans un view");
    }

    Darray x = Darray();

    if(copy){
        x.alloc(count);
        memcpy(x.data, data + start, count * sizeof(double));
        x.owner = true;
    } else {
        x.data = data + start;
        x.size_ = count;
        x.owner = false;
    }

    return x;
}

bool Darray::isOwner() const{
    return owner;
}

const double* Darray::getData() const{
    return data;
}

//=============================================================================
//                              ASSIGN OPERATOR
//=============================================================================
Darray& Darray::operator=(Darray const& x){
    bool is_null = size_ == 0;
    bool own_stuff = (!is_null) && owner;
    if(own_stuff || (is_null && x.owner)){
        (*this).hard_copy(x);
    } else {
        bool diff_length = !is_null && size_ != x.size_;
        if((!own_stuff) && diff_length){
            throw new std::invalid_argument("Assignation incompatible : membre gauche non propriétaire et tailles différentes");
        }
        (*this).soft_copy(x);
    }
    return *this;
}
