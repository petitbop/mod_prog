//!
//! @file 		Maillage.tpp
//! @author 	lemoele petitbop
//!
//! @brief 		Implementation for the template class Maillage.
//!

#include "Maillage.h"




// template <typename T, typename C> 
// Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine) {
	
// }


template <typename T, template <typename> class Container>
Maillage<T, Container>::Maillage(int m, int n, const Point<T> & origine): list_tri(4*m*n){
    
}
