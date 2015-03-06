#include "Dvector.h"

Dvector::Dvector():Darray(){

}

Dvector::Dvector(int n, double val):Darray(n, val){

}

Dvector::Dvector(Dvector const& x):Darray(x){

}

Dvector& Dvector::operator*=(Dvector const& x){
    if(size_ == x.size_){
        for (int i=0; i<size_; i++) {
            (*this)(i) *= x(i);
        }
    } else {
        throw std::length_error("Produit terme à terme de deux Darray de tailles différentes");
    }
    return *this;
}

Dvector operator*(Dvector const& x, Dvector const& y){
    Dvector z = Dvector(x);
    z *= y;
    return z;
}
