//!
//! @file 		Maillage.tpp
//! @author 	lemoele petitbop
//!
//! @brief 		Implementation for the template class Maillage.
//!

#include "Maillage.h"


template <typename T, template <typename> class Container>
// template <typename T, class Container = std::allocator<T> >
Maillage<T, Container>::Maillage(int m, int n, const Point<T> & origine): grid(4*m*n){
    
}
