/* vim: set filetype=cpp: */
//!
//! @file 		Maillage.tpp
//! @author 	lemoele petitbop
//!
//! @brief 		Implementation for the template class Maillage.
//!

#include "Maillage.h"


template <typename num_type, template <typename, typename> class Container>
// template <typename T, class Container = std::allocator<T> >
Maillage<num_type, Container>::Maillage(int m, int n, const Point<num_type> & O){
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

