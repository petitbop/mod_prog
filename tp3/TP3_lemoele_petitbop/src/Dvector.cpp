#include "Dvector.h"

Dvector::Dvector():Darray(){

}

Dvector::Dvector(int n, double val):Darray(n, val){

}

Dvector::Dvector(Dvector const& x):Darray(x){

}

Dvector::Dvector(Darray const& x):Darray(x){

}

double operator*(Dvector const& x, Dvector const& y){
    if(x.size() != x.size()){
        throw std::length_error("Produit terme à terme de deux Darray de tailles différentes");
    }

    double res = 0;
    for (int i=0; i<x.size(); i++) {
        res += x(i) * y(i);
    }

    return res;
}
