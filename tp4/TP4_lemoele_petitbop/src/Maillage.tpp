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
        }
    }
}
