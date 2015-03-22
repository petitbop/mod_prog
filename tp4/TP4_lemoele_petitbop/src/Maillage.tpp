/* vim: set filetype=cpp: */
//!
//! @file 		Maillage.tpp
//! @author 	lemoele petitbop
//!
//! @brief 		Implementation for the template class Maillage.
//!

#include "Maillage.h"


template <typename num_type, template <typename, typename> class Container>
Maillage<num_type, Container>::Maillage(int m, int n, const Point<num_type> & O): origin(O), m(m), n(n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Point<num_type> P = O.translate(i, j);
            Point<num_type> Q = P.translate(1, 0);
            Point<num_type> R = P.translate(0, 1);
            Point<num_type> S = P.translate(1, 1);

            grid.push_back(Triangle<num_type>(R, P, Q));
            grid.push_back(Triangle<num_type>(R, S, Q));
        }
    }
}
template <typename num_type, template <typename, typename> class Container>
typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator
Maillage<num_type, Container>::beginiter(void){
    return grid.begin();
}

template <typename num_type, template <typename, typename> class Container>
typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator
Maillage<num_type, Container>::enditer(void){
    return grid.end();
}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::transformer(double m11, double m12, double m21, double m22) {

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = this->beginiter(); curr_tri != this->enditer(); curr_tri++){
        curr_tri.transformer(m11,m12,m21,m22);
    }

}

template <typename num_type, template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& flux, Maillage<num_type, Container>const& m){

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = m.beginiter(); curr_tri != m.enditer(); curr_tri++){
        flux << (*curr_tri);
        flux << std::endl;
    }

    return flux;
}
