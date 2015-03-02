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
    std::cout << "Constructor Darray(unsigned int length, double default_valor). \n";
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
