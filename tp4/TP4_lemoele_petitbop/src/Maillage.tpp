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
        curr_tri->deplacer(dx, dy);
    }

    typename std::vector< Segment<num_type> >::iterator curr_seg;

    for(curr_seg = endpoints.begin(); curr_seg != endpoints.end(); curr_seg++){
        curr_seg->p1().deplacer(dx, dy);
        curr_seg->p2().deplacer(dx, dy);
    }

}

template <typename num_type, template <typename, typename> class Container>
bool Maillage<num_type, Container>::is_adjacent(const Maillage<num_type, Container>& m, int& common){
    for(int i = 0; i < 4; i++){
        if(endpoints[i] == m.endpoints[(i+2)%4]){
            common = i;
            return true;
        }
    }

    return false;

}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::set_endpoints(Point<num_type> A, Point<num_type> B, Point<num_type> C, Point<num_type> D){
    endpoints.clear();

    endpoints.push_back(Segment<num_type>(A, B));
    endpoints.push_back(Segment<num_type>(B, C));
    endpoints.push_back(Segment<num_type>(C, D));
    endpoints.push_back(Segment<num_type>(D, A));
}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::fusionner(Maillage<num_type, Container>& other){
    int common;

    if(is_adjacent(other, common)){
        Point<num_type> A = endpoints[0].p1();
        Point<num_type> B = endpoints[0].p1();
        Point<num_type> C = endpoints[0].p1();
        Point<num_type> D = endpoints[0].p1();

        Point<num_type> A_prime = other.endpoints[0].p1();
        Point<num_type> B_prime = other.endpoints[0].p1();
        Point<num_type> C_prime = other.endpoints[0].p1();
        Point<num_type> D_prime = other.endpoints[0].p1();

        if(common == 0){
            set_endpoints(A_prime, B_prime, C, D);
            n += other.n;
        } else if (common == 1){
            set_endpoints(A, B_prime, C_prime, D);
            m += other.m;
        } else if (common == 2){
            set_endpoints(A, B, C_prime, D_prime);
            n += other.n;
        } else if (common == 3){
            set_endpoints(A_prime, B, C, D_prime);
            m += other.m;
        }

        typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;
        for(curr_tri = other.beginiter(); curr_tri != other.enditer(); curr_tri++){
            grid.push_back((*curr_tri));
        }

    }

}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::transformer(double m11, double m12, double m21, double m22) {

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = this->beginiter(); curr_tri != this->enditer(); curr_tri++){
        curr_tri->transformer(m11,m12,m21,m22);
    }

    typename std::vector< Segment<num_type> >::iterator curr_seg;

    for(curr_seg = endpoints.begin(); curr_seg != endpoints.end(); curr_seg++){
        curr_seg->p1().transformer(m11, m12, m21, m22);
        curr_seg->p2().transformer(m11, m12, m21, m22);
    }

}

template <typename num_type, template <typename, typename> class Container>
void Maillage<num_type, Container>::tourner( double angle, const Point<num_type>& pt ) {

    typename Container< Triangle<num_type>, std::allocator<num_type> >::iterator curr_tri;

    for(curr_tri = this->beginiter(); curr_tri != this->enditer(); curr_tri++){
        curr_tri->tourner(angle, pt);
    }

    typename std::vector< Segment<num_type> >::iterator curr_seg;

    for(curr_seg = endpoints.begin(); curr_seg != endpoints.end(); curr_seg++){
        curr_seg->p1().tourner(angle, pt);
        curr_seg->p2().tourner(angle, pt);
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
