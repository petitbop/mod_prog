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

    Point<num_type> A(O);
    Point<num_type> B(O.translate(m, 0));
    Point<num_type> C(O.translate(0, n));
    Point<num_type> D(O.translate(m, n));

    endpoints.push_back(Segment<num_type>(A, B));
    endpoints.push_back(Segment<num_type>(B, C));
    endpoints.push_back(Segment<num_type>(C, D));
    endpoints.push_back(Segment<num_type>(D, A));

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
void Maillage<num_type, Container>::deplacer(double dx, double dy){

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = this->beginiter(); curr_tri != this->enditer(); curr_tri++){
        curr_tri.deplacer(dx, dy);
    }

    typename std::vector< Segment<num_type> >::iterator curr_seg;

    for(curr_seg = endpoints.beg(); curr_seg != endpoints.end(); curr_seg++){
        curr_seg.p1().deplacer(dx, dy);
        curr_seg.p2().deplacer(dx, dy);
    }

}

template <typename num_type, template <typename, typename> class Container>
bool Maillage<num_type, Container>::is_adjacent(const Maillage<num_type, Container>& m, Segment<num_type>& common){
    typename std::vector< Segment<num_type> >::iterator curr_seg1;
    typename std::vector< Segment<num_type> >::iterator curr_seg2;

    for(curr_seg1 = endpoints.beg(); curr_seg1 != endpoints.end(); curr_seg1++){
        for(curr_seg2 = endpoints.beg(); curr_seg2 != endpoints.end(); curr_seg2++){
            if((*curr_seg1) == (*curr_seg2)){
                common = (*curr_seg1);
                return true;
            }
        }
    }

    return false;

}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::fusionner(const Maillage<num_type, Container>& m){
}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::transformer(double m11, double m12, double m21, double m22) {

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = this->beginiter(); curr_tri != this->enditer(); curr_tri++){
        curr_tri.transformer(m11,m12,m21,m22);
    }

    typename std::vector< Segment<num_type> >::iterator curr_seg;

    for(curr_seg = endpoints.beg(); curr_seg != endpoints.end(); curr_seg++){
        curr_seg.p1().transformer(m11, m12, m21, m22);
        curr_seg.p2().transformer(m11, m12, m21, m22);
    }

}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::tourner( double angle, const Point<num_type>& pt ) {

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = this->beginiter(); curr_tri != this->enditer(); curr_tri++){
        curr_tri.tourner(angle, pt);
    }

    typename std::vector< Segment<num_type> >::iterator curr_seg;

    for(curr_seg = endpoints.beg(); curr_seg != endpoints.end(); curr_seg++){
        curr_seg.p1().tourner(angle, pt);
        curr_seg.p2().tourner(angle, pt);
    }

}

template <typename num_type, template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& flux, Maillage<num_type, Container>& m){

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = m.beginiter(); curr_tri != m.enditer(); curr_tri++){
        flux << (*curr_tri);
        flux << std::endl;
    }

    return flux;
}
